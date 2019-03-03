//***************排序程序*******************//

#include"sort.h"
#include<time.h>
#include<stdio.h>

int main()
{
	//int arr[] = {0,1,3,5,4,7,6,2,1,2,0};
	int arr[] = {1,-2,-6,5,-3,0,-9,22,44,-8,-15,3,6};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	//int *arr;
	//int len = 1000000;
	//Init1(&arr,len);//随机数
	//Init2(&arr,len);//升序有序
	//Init3(&arr,len);//降序有序
	//Init4(&arr,len);//随机但有大量重复数字
	
	//Insert_Sort(arr,len);
	//Shell_Sort(arr,len);
	//Select_Sort(arr,len);
	//Bulu_Sort(arr,len);
	
	int time1 = clock();
	//QInsert_Sort(arr,0,len-1);
	//Quick_Sort(arr,len);
	Teap_Sort(arr,len);
	//MergeSort(arr,len);
	int time2 = clock();

	//Part_Positive_minus(arr,len);
	//Part_Odd_Even(arr,len);

	Show(arr,len);
	printf("%d\n",time2-time1);

	if(Test_Is_Sort(arr,len))
	{
		printf("sort!!\n");
	}
	else
	{
		printf("unsort!!!!!\n");
	}

	return 0;
}


/*
int main()
{
	int arr[] = {5,2,3};
	Put_Between_To_First(arr,0,2);
	Show(arr,3);
	return 0;
}
*/