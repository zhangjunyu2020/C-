#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include"sort.h"

int main()
{
    printf("hello world!\n");

    //  32
    //  数据类型关键字: char doubl float int long short signed unsigned void struct union enum
    //  控制语句关键字：switch break case continue default do while if else goto for return
    //  存储类关键字：extern const static auto register
    //  其他类关键字：sizeof typedef volatile

    //  9
    //  if()else()
    //  for(){}
    //  while(){}
    //  do{}while()
    //  continue;
    //  break;
    //  switch(){case ():break; default;}
    //  goto aa; aa:
    //  return ;

    //  34
    //  + - * / % ++ --
    //  < <= == > >= !=
    //  ! && ||
    //  << >> ~ | ^ &
    //  =
    //  ? :
    //  , * & sizeof (类型) -> [] () {}

    //  常量（只读）C语言推荐用 #define price 3 const在C语言中不安全
    const int price = 3; // price = 5;  error
    //  变量
    int weight = 5;
    //  静态变量
    for (int i = 0; i < 5; i++)
    {
        static int a = 0;
        a++;
        printf("a: %d\n", a);
    }

    unsigned int a = -10;
    printf("%u\n", a);
    printf("%d\n", a);
    //  正数的原码、反码、补码一致
    //  负数的反码，除了符号位与原码一致，其余位都与原码相反，补码在其反码的基础上加一
    //  int a1 = 0123;   八进制
    //  int a2 = 0x123;  十六进制

    char ch1 = 127;
    ch1 += 2;
    printf("%d\n", ch1);

    short ss = 0x7fff + 2;
    printf("%d\n", ss);
    //  0111 1111 1111 1111 补码0xfff
    //  0000 0000 0000 0010 补码2
    //  1000 0000 0000 0001 补码相加+
    //  1000 0000 0000 0000 反码
    //  1111 1111 1111 1111 原码

    extern int a1;   //  声明一个变量，extern声明的变量没有创建存储空间，变量在定义时创建存储空间
    volatile int a2; //  防止编译器优化代码，常用于嵌入式开发
    register int a3; //  定义寄存器变量，提高效率，如果cpu中有空闲寄存器，register生效。cpu中没有空闲寄存器，register无效。

    char ch2[] = "sa";
    printf("ch2 size: %d\n", sizeof(ch2));
    printf("ch2 address size: %d\n", sizeof(&ch2));
    int *p;
    printf("p size: %d\n", sizeof(p));

    //  输入、输出
    // char ch[] = "";
    // int input;
    // scanf("%s %d", &ch, &input);
    // printf("input: %s, %d\n", ch, input);

    //  运算符
    // 算术运算符：+ - * / % ++ --
    //  < <= == > >= !=
    //  ! && ||
    //  位运算符：<< >> ~ | ^ &
    //  赋值运算符：=
    //  三目运算符：? :
    //  其他运算符：sizeof , * &  (类型) -> [] () {}

    printf("%6.3f\n", 5.0 / 2);

    //  单目运算符优先级高于双目运算符

    //  char,short -> signed int -> unsigned int -> long -> double <- float

    //  程序流程结构：顺序结构、选择结构、循环结构。

    printf("max value: %d\n", 2 > 3 ? 2 : 3);

    //  break、continue、goto
    // aa:
    //     goto aa;

    //  数组
    int arr[5] = {};

    //  字符串
    printf("arr's size: %d\n", sizeof(arr));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 10;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int arr1[] = {123, 4, 65, 6, 14, 8, 2, 1212, 45, 7, 5};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    my_sort(arr1, len, 1);
    my_sort(arr1, len, 0);

    //  二维数组
    // int arr2[2][3] = {};

    // for (int i = 0; i < 2; i++)
    // {
    //     int a;
    //     for (int j = 0; j < 3; j++)
    //     {
    //         scanf("%d", &a);
    //         arr2[i][j] = a;
    //     }
    // }
    // printf("arr2[2][3]:\n");
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", arr2[i][j]);
    //     }
    //     printf("\n");
    // }

    //  字符串数组
    //  char arr3[3][] = {"sasa","sweew"};   error
    //  char arr3[3][8] = {"sasa", "sweew"};    right
    //  char arr3[][8] = {"sasa", "sweew"};     right

    //  char chh[5];
    //  fgets(chh, sizeof(chh) / sizeof(chh[0]), stdin);
    //  printf("%s\n", chh);
    //  123->123\n->123\n 123456->123456\n->1234\n
    
    int lenn = strlen("hello world");
    printf("lenn_strlen: %d\n", lenn);
    printf("lenn_sizeof: %d\n", sizeof("hello world")/sizeof('h'));
    
    //  添加随机数种子
    srand((unsigned int)time(NULL));
    printf("range 20 to 29 random: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand()%10+20);
    }printf("\n");
    
    

    return 0;
}

// 返回值类型 函数名(){
//      代码体;
//      
//      return 0; 返回值;
// }

// void name(){
//      代码体;
//      return 0; 返回值;  
// }

