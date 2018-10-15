/*
 * Test.c
 *
 *  Created on: 2018年3月8日
 *      Author: Michael.Qubit
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 要生成和返回随机数的函数 */
int *  getRandom(void)
{
   static int  r[10];
   int i;

   /* 设置种子 */
   srand( (unsigned)time( NULL ) );

   for ( i = 0; i < 10; ++i)
   {
      r[i] = rand();
      printf("%d\n", r[i] );
   }

   return r;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}

// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}
