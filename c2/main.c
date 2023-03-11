#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delet_space(char *dest, char *str);
void my_swap(int *a, int *b);
void my_strcpy(char *dest, char *ch);

int main(int argc, char *argv[])
{
    printf("pointer:\n");

    //  小端存储
    int a = 0x44434241;
    // 4*16 + 1 = 65
    printf("%c\n", a);

    //  & 取址，* 取值
    int b = 12;
    printf("b: %d\n", b);
    printf("b_address: %p\n", &b);
    int *p = &b;
    *p = 24;
    printf("b: %d\n", b);
    printf("b_address: %p\n", &b);

    //  空指针：内存地址编号为0的空间。
    int *e_p = NULL;

    //  野指针：指针变量指向一个未知的空间。操作野指针对应的内存空间可能报错。
    //  int *y_p = 100;
    //  printf("%p\n", pp); error 禁止访问，不建议将变量的值直接赋予pp。

    //  万能指针
    void *w_p;
    int c = 9;
    w_p = &c; // !!!
    printf("c: %d\n", (*(int *)w_p));

    //  const常量 可以通过指针修改 故不安全。
    const int d = 10;
    printf("d: %d\n", d);
    int *pp = &d; //  warning: initialization discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
    *pp = 20;
    printf("d: %d\n", d);

    //  常量指针
    int e = 15;
    int f = 20;
    const int *pp_c1 = &e;

    // *pp_c1 = 20; //  error 常量指针 值不可更改
    pp_c1 = &f; //  地址可以更改

    //  指针常量
    int *const pp_c2 = &e;

    *pp_c2 = 30; //  值可以更改
    //  pp_c2 = &f; //  error 指针常量 地址不可更改

    int arr[] = {13, 45, 78};
    int *pp_a = arr;

    printf("size of pp_a: %d\n", sizeof(pp_a)); //  8   x64下指针大小为8字节 int为4字节
    printf("size of arr:  %d\n", sizeof(arr));  //  12  4*3 表示数组的大小

    printf("arr[0]: %d\n", *pp_a);
    printf("arr[2]: %d\n", *(pp_a + 2));

    char str1[] = {"sasadhaj"};
    char str2[10];

    my_strcpy(str2, str1);

    printf("str2: %s\n", str2);
    //  指针的加减运算与指针类型有关 p--

    //  指针数组
    int x = 11, y = 22, z = 33;
    int *arr1[3] = {&x, &y, &z};
    printf("xyz_address: %p,%p,%p\n", arr1[0], arr1[1], arr1[2]);
    printf("xyz_value: %d,%d,%d\n", *arr1[0], *arr1[1], *arr1[2]);

    int g[] = {1, 2, 3};
    int h[] = {4, 5, 6};
    int i[] = {7, 8, 9};
    int *arr2[3] = {&g, &h, &i};
    printf("%d\n", arr2[1][1]);
    printf("%d\n", *((arr2[1]) + 1)); //  偏移量

    //  多级指针
    int *arr3[3] = {&g, &h, &i};
    int **pp_erji = arr3;
    printf("%d\n", **pp_erji);
    printf("%d\n", *(*(pp_erji + 1) + 1));

    //  值传递与地址传递
    printf("e f: %d %d\n", e, f);
    my_swap(&e, &f);
    printf("e f: %d %d\n", e, f);

    char str3[] = "    h e   l lo  w o  r l  d  ";
    char str4[50];
    delet_space(str4, str3);
    printf("str4: %s, size: %d, strlen: %d\n", str4, sizeof(str4), strlen(str4));

    //
    char ch1[] = "hello world"; //  栈区字符串。
    char *ch2 = "hello world";  //  数据区常量区字符串，不允许修改其内容。
    ch1[2] = 'm';
    //  ch2[2] = 'm';     //  error
    //  *(ch2+2) = 'm';   //  error

    printf("ch1: %s\n", ch1);
    printf("ch2: %s\n", ch2);

    char *ch3 = strstr("hiuasdgudbbahjzgxhwasaa", "hw");
    printf("ch3: %s\n", ch3); // hwasaa

    char ch4[] = "zhang";
    strcat(ch4, "junyu");
    printf("ch4: %s\n", ch4); // zhangjunyu

    printf("strcmp: %d\n", strcmp("zhang1", "zhang"));

    //  字符串分割
    char ch5[] = "www.baidu.com";
    char *ch6 = strtok(ch5, ".");
    printf("ch6: %s\n", ch6);
    ch6 = strtok(NULL, ".");
    printf("ch6: %s\n", ch6);
    ch6 = strtok(NULL, ".");
    printf("ch6: %s\n", ch6);

    char ch7[] = "   -123456sas123";
    int num = atoi(ch7);
    printf("num: %d\n", num);
    
    char ch8[] = "  -123654.1324sas124";
    double num1 = atof(ch8);
    printf("num1: %.2f\n", num1);

    

    return 0;
}

void delet_space(char *dest, char *str)
{
    int i = 0;
    int index = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            dest[index] = str[i];
            index++;
        }

        i++;
    }
    dest[index] = '\0';
}

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void my_strcpy(char *dest, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    str[i] = '\0';
}