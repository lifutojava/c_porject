/*
 * main.cpp
 *
 *  Created on: 2018年3月12日
 *      Author: Michael.Qubit
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	//外层控制行
	for(int i = 1;i<10;i++)
	{
		//内层控制列
		for(int j = 1;j<=i;j++)
		{
			printf("%d * %d = %d \t", i , j , i*j );
		}
		printf("\n");
	}
	system("pause");
//	pause();
//	getch();
	return 0;
}

