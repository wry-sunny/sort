#include"sort.h"
#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//插入
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

//插入排序
void Insert_Sort(int *arr,int len) //时间复杂度 O(n^2) 空间复杂度o(1)  稳定
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




//希尔排序的插入
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

//希尔排序
void Shell_Sort(int *arr,int len)//时间复杂度O(n^(1.5 -- 1.3)) 空间复杂度O(1)  不稳定
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



//选择排序
void Select_Sort(int *arr,int len)//时间复杂度o(n^2) 空间复杂度O(1)  不稳定
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




//冒泡排序
void Bulu_Sort(int *arr,int len)//时间复杂度o(n^2) 空间复杂度o(1)  稳定
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
		if(0 == sign)//冒泡优化，待排序列有序就直接跳出
		{
			break;
		}
	}
}












//快排优化的，三者取中和，最后的数据采用插入排序

//插入
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

//插入排序
 void QInsert_Sort(int *arr,int low,int high) //时间复杂度 O(n^2) 空间复杂度o(1)  稳定
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


//将中间值放到low的位置
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

//把元素放到的确切位置
static int Partition(int *arr,int low, int high) 
{
	assert(arr != NULL);

	int tmp = arr[low];
	int tmp_tmp;

	while(low < high)
	{
		while((low < high) && (arr[high] <= tmp))  //切记等于时候high也要自减
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


//递归使每个元素到确切位置
static void Quick(int *arr,int low,int high)
{
	Put_Between_To_First(arr,low,high);//在数据大概有序的情况下有效
	
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

//快速排序
void Quick_Sort(int *arr,int len)//时间复杂度 o(nlog2 n) 空间复杂度O(log2 n)  不稳定
{
	assert(arr != NULL);

	Quick(arr,0,len-1);
}










//堆排序

//一次根调整
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

//堆排序
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




//归并排序

//归并一次排序
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

//归并排序
void MergeSort(int *arr,int len)
{
	assert(arr != NULL);

	for(int grap = 1; grap<len; grap *= 2)
	{
		Merge_Only(arr,len,grap);
	}
}


/*
//一趟归并过程,gap为归并段的长度
static void Merge(int *arr,int len,int gap)//O(n)
{
	int low1 = 0;//第一个归并段的起始下标，下标可取
	int high1 = low1+gap-1;//第一个归并段的结束下标，下标可取
	int low2 = high1+1;//第二个归并段起始下标，下标可取
	int high2 = low2+gap<len ? low2+gap-1 : len-1;//第二个归并段的结束下标，下标可取
	
	int *brr = (int *)malloc(len*sizeof(int));
	assert(brr != NULL);
	int i = 0;//brr下标

	//归并段成对,需要归并
	while(low2 < len)
	{
		//两个归并段都还有数据
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

		//一个归并段已完成，另一个还有数据
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

	//归并段不成对
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

void MergeSort(int *arr,int len)//O(nlogn),O(n),稳定
{
	for(int i=1;i<len;i*=2)
	{
		Merge(arr,len,i);
	}
}


*/




//负数在前，正数在后
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




//奇数在前偶数在后
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

		while(i<j && (arr[j] & 1) == 0) // ==  运算符优先级高于  &
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






	


//生成len个随机数
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

//生成len个升序有序的数字
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

//生成len个降序有序的数字
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

//生成len个大量重复的随机数字
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


//测试数据是否有序
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