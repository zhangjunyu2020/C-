#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student
{
    char name[50];
    int age;
    int score;
    char addr[51];
};
typedef struct student ss;

union test
{
    unsigned char a;
    unsigned int b;
    unsigned short c;
};

enum color
{
    red,
    blue,
    green,
    yellow
};

int main(int argc, char *argv[])
{
    printf("c4:\n");

    struct student stu;
    strcpy(stu.name, "zhangjunyu");
    stu.age = 18;
    stu.score = 100;
    strcpy(stu.name, "xi'an");

    struct student stu1 = {"zhangsan", 20, 99, "beijing"};
    // scanf("%s %d %d %s", stu.name, &stu.age, &stu.score, stu.addr);

    struct student stu2[10];

    ss *p_ss = (ss *)malloc(sizeof(ss) * 3);

    //  随机数种子
    srand((unsigned int)time(NULL));

    //  共用体
    union test tt;
    tt.a = 'A';
    printf("%d\n", tt);
    tt.a = 'A';
    tt.b = 100;
    printf("%d\n", tt);
    tt.a = 'A';
    tt.b = 100;
    tt.c = 200;
    printf("%d\n", tt);

    //  枚举
    enum color clr;
    int val = 2;
    //  scanf("%d", &val);
    printf("color is ");
    switch (val)
    {
    case red:
        printf("red\n");
        break;
    case blue:
        printf("blue\n");
        break;
    case green:
        printf("green\n");
        break;
    case yellow:
        printf("yellow\n");
        break;
    default:
        break;
    }

    FILE *fp = fopen("a.txt", "r");
    if (!fp)
    {
        printf("open file error!\n");
        return -1;
    }
    printf("open file success: %p\n", fp);

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        /* code */
        printf("%c", ch);
    }

    //  fgetc   逐字符 读取
    //  fputs   逐字符 写入
    //  fgets   逐行 读取
    //  fputs   逐行 写入
    fclose(fp);

    fp = fopen("a.txt", "r");
    if (!fp)
    {
        printf("open file error!\n");
        return -1;
    }

    printf("\n=================================\n");
    char *p = (char *)malloc(sizeof(char) * 20);
    while (!feof(fp))    //  feof文件指针，判断文件是否到结尾
    {
        memset(p, 0, 20);
        fgets(p, 20, fp);
        printf("%s", p);        
    }
    
    

    free(p);
    fclose(fp);

    return 0;
}