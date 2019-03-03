#include"sort.h"
#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//����
static void Insert(int *arr,int sit)
{
	assert(arr != NULL);

	int tmp = arr[sit];
	int i;

	for(i = sit-1; i >= 0; i--)
	{
		if(arr[i] < tmp)
		{
			arr[i+1] = arr[i];
		}
		else
		{
			break;
		}
	}

	arr[i+1] = tmp;
}

//��������
void Insert_Sort(int *arr,int len) //ʱ�临�Ӷ� O(n^2) �ռ临�Ӷ�o(1)  �ȶ�
{
	assert(arr != NULL);
	if(len <= 1)
	{
		return;
	}

	for(int i = 1; i < len; i++)
	{
		Insert(arr,i);
	}
}




//ϣ������Ĳ���
static void Shell_Insert(int *arr,int sit,int ruler)
{
	assert(arr != NULL);

	int tmp = arr[sit];
	int i;

	for(i = sit - ruler; i >= 0; i -= ruler)
	{
		if(arr[i] < tmp)
		{
			arr[i+ruler] = arr[i];
		}
		else
		{
			break;
		}
	}

	arr[i+ruler] = tmp;
}

//ϣ������
void Shell_Sort(int *arr,int len)//ʱ�临�Ӷ�O(n^(1.5 -- 1.3)) �ռ临�Ӷ�O(1)  ���ȶ�
{
	assert(arr != NULL);

	if(len <= 1)
	{
		return;
	}

	int ruler[] = {5,3,1};

	for(int i = 0; i < sizeof(ruler) / sizeof(ruler[0]); i++)
	{
		while(len <= ruler[i])
		{
			i++;
		}

		for(int j = ruler[i]; j < len; j++)
		{
			Shell_Insert(arr,j,ruler[i]);
		}
	}
}



//ѡ������
void Select_Sort(int *arr,int len)//ʱ�临�Ӷ�o(n^2) �ռ临�Ӷ�O(1)  ���ȶ�
{
	assert(arr != NULL);

	int tmp;
	int sit;

	for(int i = 0; i < len; i++)
	{
		sit = i;
		for(int j = i+1; j < len; j++)
		{
			if(arr[j] > arr[sit])
			{
				sit = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[sit];
		arr[sit] = tmp;
	}
}




//ð������
void Bulu_Sort(int *arr,int len)//ʱ�临�Ӷ�o(n^2) �ռ临�Ӷ�o(1)  �ȶ�
{
	assert(arr != NULL);

	if(len <= 1)
	{
		return;
	}
	

	int tmp;
	for(int i = 1; i < len; i++)
	{
		int sign = 0;
		for(int j = 0; j < len - i; j++)
		{
			if(arr[j+1] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				sign = 1;
			}
		}
		if(0 == sign)//ð���Ż����������������ֱ������
		{
			break;
		}
	}
}












//�����Ż��ģ�����ȡ�кͣ��������ݲ��ò�������

//����
static void QInsert(int *arr,int low,int high)
{
	assert(arr != NULL);

	int tmp = arr[high];
	int i;

	for(i = high-1; i >= low; i--)
	{
		if(arr[i] < tmp)
		{
			arr[i+1] = arr[i];
		}
		else
		{
			break;
		}
	}

	arr[i+1] = tmp;
}

//��������
 void QInsert_Sort(int *arr,int low,int high) //ʱ�临�Ӷ� O(n^2) �ռ临�Ӷ�o(1)  �ȶ�
{
	assert(arr != NULL);
	if(high == low)
	{
		return;
	}

	for(int i = low+1; i <= high; i++)
	{
		QInsert(arr,low,i);
	}
}


//���м�ֵ�ŵ�low��λ��
static void Put_Between_To_First(int *arr,int low,int high)
{
	assert(arr != NULL);
	if(high - low >= 2)
	{
		int between = (low + high) / 2;
		int tmp;
		int sit;

		if(arr[low] >= arr[between])
		{
			if(arr[high] >= arr[low])
			{
				sit = low;
			}
			else if(arr[high] <= arr[between])
			{
				sit = between;
			}
			else
			{
				sit = high;
			}
		}
		else
		{
			if(arr[high] <= arr[low])
			{
				sit = low;
			}
			else if(arr[high] >= arr[between])
			{
				sit = between;
			}
			else
			{
				sit = high;
			}
		}

		tmp = arr[low];
		arr[low] = arr[sit];
		arr[sit] = tmp;
	}

}

//��Ԫ�طŵ���ȷ��λ��
static int Partition(int *arr,int low, int high) 
{
	assert(arr != NULL);

	int tmp = arr[low];
	int tmp_tmp;

	while(low < high)
	{
		while((low < high) && (arr[high] <= tmp))  //�мǵ���ʱ��highҲҪ�Լ�
		{
			/*
			if((high-low)>1 && arr[high] > arr[high-1])
			{
				tmp_tmp = arr[high];
				arr[high] = arr[high-1];
				arr[high-1] = tmp_tmp;
			}*/
			
			high--;
		}
		if(low < high)
		{
			arr[low] = arr[high];
			//low++;
		}
		else
		{
			break;
		}

		while((low < high) && (arr[low] >= tmp))
		{	
			/*
			if((high-low)>1 && arr[low] < arr[low+1])
			{
				tmp_tmp = arr[low];
				arr[low] = arr[low+1];
				arr[low+1] = tmp_tmp;
			}*/
			
			low++;
		}
		if(low < high)
		{
			arr[high] = arr[low];
			//high--;
		}
		else
		{
			break;
		}
	}

	arr[high] = tmp;

	return low;
}


//�ݹ�ʹÿ��Ԫ�ص�ȷ��λ��
static void Quick(int *arr,int low,int high)
{
	Put_Between_To_First(arr,low,high);//�����ݴ��������������Ч
	
	if((high - low) < 20)
	{
		QInsert_Sort(arr,low,high);
		return;
	}

	int par = Partition(arr,low,high);
	
	if(par > low+1)
	{
		Quick(arr,low,par-1);
	}
	if(par < high-1)
	{
		Quick(arr,par+1,high);
	}
}

//��������
void Quick_Sort(int *arr,int len)//ʱ�临�Ӷ� o(nlog2 n) �ռ临�Ӷ�O(log2 n)  ���ȶ�
{
	assert(arr != NULL);

	Quick(arr,0,len-1);
}










//������

//һ�θ�����
static void Sort_Only(int *arr,int start,int tail)
{
	assert(arr != NULL);

	int parent = start;
	int tmp = arr[parent];
	int i;

	for(i = 2*start+1; i <= tail; i= 2*i+1 )
	{
		if(i+1 <= tail && arr[i] > arr[i+1])
		{
			i++;
		}

		if(arr[i] < tmp)
		{
			arr[parent] = arr[i];

			parent = i;
		}

		else
		{
			break;
		}
	}

	arr[parent] = tmp;
}

//������
void Teap_Sort(int *arr,int len)
{
	assert(arr != NULL);

	int tmp;

	for(int i = (len-1-1)/2; i >= 0; i--)
	{
		Sort_Only(arr,i,len-1);
	}

	for(int i = 0; i<len-1; i++)
	{
		tmp = arr[len-i-1];
		arr[len-i-1] = arr[0];
		arr[0] = tmp;

		Sort_Only(arr,0,len-i-1-1);
	}
}




//�鲢����

//�鲢һ������
static void Merge_Only(int *arr,int len,int grap)
{
	assert(arr != NULL);

	int *brr = (int *)malloc(sizeof(int)*len);
	assert(brr != NULL);
	int i = 0;

	int low1 = 0;
	int high1 = low1+grap-1;
	int low2 = high1+1;
	int high2 = low2+grap > len ? len-1 : low2+grap-1;

	while(low2 < len)
	{
		while((low1 <= high1) && (low2 <= high2))
		{
			if(arr[low1] >= arr[low2])
			{
				brr[i++] = arr[low1++];
			}
			else
			{
				brr[i++] = arr[low2 ++];
			}
		}

		while(low1 <= high1)
		{
			brr[i++] = arr[low1 ++];
		}
		while(low2 <= high2)
		{
			brr[i++] = arr[low2 ++];
		}

	 low1 = high2+1;
	 high1 = low1+grap-1;
	 low2 = high1+1;
	 high2 = low2+grap > len ? len-1 : low2+grap-1;
	}

	while(low1 < len)
	{
		brr[i++] = arr[low1 ++];
	}

	for(i = 0; i< len; i++)
	{
		arr[i] = brr[i];
	}

	free(brr);
}

//�鲢����
void MergeSort(int *arr,int len)
{
	assert(arr != NULL);

	for(int grap = 1; grap<len; grap *= 2)
	{
		Merge_Only(arr,len,grap);
	}
}


/*
//һ�˹鲢����,gapΪ�鲢�εĳ���
static void Merge(int *arr,int len,int gap)//O(n)
{
	int low1 = 0;//��һ���鲢�ε���ʼ�±꣬�±��ȡ
	int high1 = low1+gap-1;//��һ���鲢�εĽ����±꣬�±��ȡ
	int low2 = high1+1;//�ڶ����鲢����ʼ�±꣬�±��ȡ
	int high2 = low2+gap<len ? low2+gap-1 : len-1;//�ڶ����鲢�εĽ����±꣬�±��ȡ
	
	int *brr = (int *)malloc(len*sizeof(int));
	assert(brr != NULL);
	int i = 0;//brr�±�

	//�鲢�γɶ�,��Ҫ�鲢
	while(low2 < len)
	{
		//�����鲢�ζ���������
		while(low1<=high1 && low2<=high2)
		{
			if(arr[low1] <= arr[low2])
			{
				brr[i++] = arr[low1++];
			}
			else
			{
				brr[i++] = arr[low2++];
			}
		}

		//һ���鲢������ɣ���һ����������
		while(low1 <= high1)
		{
			brr[i++] = arr[low1++];
		}

		while(low2 <= high2)
		{
			brr[i++] = arr[low2++];
		}

		low1 = high2+1;
		high1 = low1+gap-1;
		low2 = high1+1;
		high2 = low2+gap<len ? low2+gap-1 : len-1;
	}

	//�鲢�β��ɶ�
	while(low1 < len)
	{
		brr[i++] = arr[low1++];
	}

	for(i=0;i<len;i++)
	{
		arr[i] = brr[i];
	}

	free(brr);
}

void MergeSort(int *arr,int len)//O(nlogn),O(n),�ȶ�
{
	for(int i=1;i<len;i*=2)
	{
		Merge(arr,len,i);
	}
}


*/




//������ǰ�������ں�
void  Part_Positive_minus(int *arr,int len)
{
	assert(arr != NULL);

	int i = 0;
	int j = len-1;
	int tmp;

	while(i < j)
	{
		while(i<j && arr[i]<0)
		{
			i++;
		}

		while(i<j && arr[j]>=0)
		{
			j--;
		}

		if(i<j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		i++;
		j--;
	}

}




//������ǰż���ں�
void Part_Odd_Even(int *arr,int len)
{
	assert(arr != NULL);

	int i = 0;
	int j = len-1;
	int tmp;

	while(i < j)
	{
		while(i<j && (arr[i] & 1) == 1)
		{
			i++;
		}

		while(i<j && (arr[j] & 1) == 0) // ==  ��������ȼ�����  &
		{
			j--;
		}

		if(i<j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		i++;
		j--;
	}
}






	


//����len�������
void Init1(int **arr,int len)
{
	assert(arr != NULL);

	int ran;

	*arr = (int *)malloc(sizeof(int) * len);
	assert(*arr != NULL);

	for(int i = 0; i < len;i++)
	{
		//srand((unsigned int)time(NULL));
		ran = rand();
		//printf("(%d)",ran);

		(*arr)[i] = ran;
		//printf("%6d",(*arr)[i]);
	}

}

//����len���������������
void Init2(int **arr,int len)
{
	assert(arr != NULL);

	*arr = (int *)malloc(sizeof(int) * len);
	assert(*arr != NULL);

	for(int i = 0; i < len;i++)
	{
		(*arr)[i] = i;
	}
}

//����len���������������
void Init3(int **arr,int len)
{
	assert(arr != NULL);

	*arr = (int *)malloc(sizeof(int) * len);
	assert(*arr != NULL);

	for(int i = len; i >= 0; i--)
	{
		(*arr)[len-i] = i;
	}
}

//����len�������ظ����������
void Init4(int **arr,int len)
{
	assert(arr != NULL);

	*arr = (int *)malloc(sizeof(int) * len);
	assert(*arr != NULL);

	int i = 0;

	while(i < len)
	{
		for(int j = 0; j < 10;j++)
		{
			(*arr)[i] = j+j;
		}
		i++;
	}
}


//���������Ƿ�����
bool Test_Is_Sort(int *arr,int len)
{
	assert(arr != NULL);

	for(int i = 0; i< len-1; i++)
	{
		if(arr[i] < arr[i+1])
		{
			return false;
		}
	}

	return true;
}

//show
void Show(int *arr,int len)
{
	assert(arr != NULL);

	for(int i = 0; i< len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
}