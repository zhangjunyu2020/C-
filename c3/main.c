#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void func();
int *func10();
// static void func(){ //  静态函数可以与全局函数重名,但重名的静态函数与全局函数不可以在同一文件中。
//     printf("func_s\n");
// }

void show_arr(int *p, int len);

int main(int argc, char *argv[])
{
    printf("c3:\n");

    //  预处理   ->   编译   ->   汇编   ->   链接
    //  代码区 - 常量区 - 初始化数据区data - 未初始化数据区bss - 堆区 - 栈区
    //  低地址  ------------------------------------------------>  高地址
    //  栈区存储模型，先进后出，后进先出。  从高地址向低地址存储。
    //  堆区存储模型，自由存储。

    //  随机数种子
    srand((unsigned int)time(NULL));

    int *p = (int *)malloc(sizeof(int) * 10);
    printf("p_arr_init: ");
    show_arr(p, 10);

    //  内存重置0
    memset(p, 0, sizeof(int) * 10);
    printf("p_arr_reset: ");
    show_arr(p, 10);

    for (int i = 0; i < 10; i++)
    {
        *(p + i) = rand() % 100;
    }

    printf("p_arr_rst: ");
    show_arr(p, 10);

    func();

    //  内存拷贝
    int arr[50];
    memcpy(arr, p, sizeof(int) * 10);
    printf("memory copy: ");
    show_arr(arr, 10);

    int *pp = func10();
    memcpy(pp, p, sizeof(int) * 10);
    printf("pp copy: ");
    show_arr(pp, 10);

    free(p);
    p = NULL;

    int **p2 = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++)
    {
        p2[i] = (int *)malloc(sizeof(int) * 3);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &p2[i][j]);
        }
    }

    printf("mark: \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", p2[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < 3; j++)
    {
        free(p2[j]);
    }
    free(p2);

    return 0;
}

int *func10()
{
    int *p = (int *)malloc(sizeof(int) * 10);
    return p;
}

void show_arr(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void func()
{
    printf("func\n");
}