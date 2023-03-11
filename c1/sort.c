#include"sort.h"
#include <stdio.h>
#include <stdlib.h>

void my_sort(int arr1[], int len, int flag)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (flag)
            {
                if (arr1[j + 1] < arr1[j])
                {
                    int temp = arr1[j];
                    arr1[j] = arr1[j + 1];
                    arr1[j + 1] = temp;
                }
            }
            else
            {
                if (arr1[j + 1] > arr1[j])
                { 
                    int temp = arr1[j];
                    arr1[j] = arr1[j + 1];
                    arr1[j + 1] = temp;
                } 
            }
        }
    }
    printf("after sort:");
    for (int i = 0; i < len; i++)
    {
        printf(" %d", arr1[i]);
    }
    printf("\n");
}
