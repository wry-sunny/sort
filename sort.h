
#pragma once 

//��������
void Insert_Sort(int *arr,int len);

//ϣ������
void Shell_Sort(int *arr,int len);

//ѡ������
void Select_Sort(int *arr,int len);

//ð������
void Bulu_Sort(int *arr,int len);

//��������
void Quick_Sort(int *arr,int len);

//������
void Teap_Sort(int *arr,int len);


//�鲢����
void MergeSort(int *arr,int len);

//������ǰ�������ں�
void  Part_Positive_minus(int *arr,int len);

//������ǰż���ں�
void Part_Odd_Even(int *arr,int len);

//����10000�������
void Init(int **arr,int len);

//show
void Show(int *arr,int len);


//����len�������
void Init1(int **arr,int len);


//����len���������������
void Init2(int **arr,int len);


//����len���������������
void Init3(int **arr,int len);


//����len�������ظ����������
void Init4(int **arr,int len);

//���������Ƿ�����
bool Test_Is_Sort(int *arr,int len);

//KMP�㷨
void KMP();

void QInsert_Sort(int *arr,int low,int high);