
#pragma once 

//插入排序
void Insert_Sort(int *arr,int len);

//希尔排序
void Shell_Sort(int *arr,int len);

//选择排序
void Select_Sort(int *arr,int len);

//冒泡排序
void Bulu_Sort(int *arr,int len);

//快速排序
void Quick_Sort(int *arr,int len);

//堆排序
void Teap_Sort(int *arr,int len);


//归并排序
void MergeSort(int *arr,int len);

//负数在前，正数在后
void  Part_Positive_minus(int *arr,int len);

//奇数在前偶数在后
void Part_Odd_Even(int *arr,int len);

//生成10000个随机数
void Init(int **arr,int len);

//show
void Show(int *arr,int len);


//生成len个随机数
void Init1(int **arr,int len);


//生成len个升序有序的数字
void Init2(int **arr,int len);


//生成len个降序有序的数字
void Init3(int **arr,int len);


//生成len个大量重复的随机数字
void Init4(int **arr,int len);

//测试数据是否有序
bool Test_Is_Sort(int *arr,int len);

//KMP算法
void KMP();

void QInsert_Sort(int *arr,int low,int high);