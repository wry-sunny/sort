#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>

typedef struct stack
{
	int *data;
	int top;
}Stack;

typedef struct Que
{
	int *data;
	int head;
	int tail;
}Que;

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

// O(n^2)  O(1)  �ȶ�
void BubbleSort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// O(n^2)  O(1)  �ȶ�
void BubbleSort2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < len - 1; ++i)
	{
		flag = 0;
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}

		if (!flag)
		{
			break;
		}
	}
}

// O(n^2)   O(1)  ���ȶ�
void  SelectSort(int *arr, int len)
{
	int min = 0;
	for (int i = 0; i < len; ++i)
	{
		min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			Swap(&arr[min], &arr[i]);
		}
	}
}

//O(n^2)�  O(n)���   �ȶ�
void  InsertSort(int *arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int tmp = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; --j)
		{
			if (arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + 1] = tmp;
	}
}

void Shell(int *arr, int len, int width)
{
	for (int i = width; i < len; ++i)
	{
		int tmp = arr[i];
		int j = 0;
		for (j = i - width; j >= 0; j -= width)
		{
			if (arr[j] > tmp)
			{
				arr[j + width] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + width] = tmp;
	}
}

//O(n^1.3) - O(n^1.5)   O(1)   ���ȶ�
void ShellSort(int *arr, int len)
{
	int d[] = { 5, 3, 1 };  // ���һ�����ݱ�����1

	for (int i = 0; i < sizeof(d) / sizeof(d[0]); ++i)
	{
		Shell(arr, len, d[i]);
	}
}

// O(n)   O(1)   ���ȶ�
int OnceQuick(int *arr, int left, int right)
{
	int i = left;
	int j = right;
	int tmp = arr[i];

	while (i < j)
	{
		// �Ӻ���ǰ�ҵ�һ���Ȼ�׼С������
		while (i < j && arr[j] >= tmp) j--;
		//undo
		if (i == j)
		{
			break;
		}
		arr[i] = arr[j];

		//��ǰ�����ҵ�һ���Ȼ�׼�������
		//undo
		while (i < j && arr[i] <= tmp) i++;
		if (i == j)
		{
			break;
		}

		arr[j] = arr[i];
	}

	arr[i] = tmp;

	return i;
}

// �ݹ����  O(nlogn)   O(logn)
void Quick(int *arr, int left, int right)
{
	// ���ŵ�һ�δ������
	int pos = OnceQuick(arr, left, right);

	if (pos - left > 1)
	{
		Quick(arr, left, pos - 1); // �ݹ鴦���׼��ߵ�����
	}

	if (right - pos > 1)
	{
		Quick(arr, pos + 1, right); //�ݹ鴦���׼�ұߵ�����
	}
}

// �ǵݹ����
void Quick2(int *arr, int left, int right)
{
	Stack st;
	int n = right - left + 1;
	int len = (int)(log10((double)n) / log10((double)2)) + 1;  // logn
	st.data = (int *)malloc(2 * sizeof(int) * len);
	assert(st.data != NULL);
	st.top = 0;

	st.data[st.top++] = left;
	st.data[st.top++] = right;

	while (st.top != 0)
	{
		right = st.data[--st.top];
		left = st.data[--st.top];

		int pos = OnceQuick(arr, left, right);

		if (right - pos > 1)
		{
			st.data[st.top++] = pos+1;
			st.data[st.top++] = right;
		}

		if (pos - left > 1)
		{
			st.data[st.top++] = left;
			st.data[st.top++] = pos - 1;
		}
	}

	free(st.data);
}

// O(nlogn)   O(logn)      ���ȶ�
void  QuickSort(int *arr, int len)
{
	//Quick(arr, 0, len - 1);
	Quick2(arr, 0, len - 1);
}

//O(logn)   O(1)   ���ȶ�
void Adjust(int *arr, int len, int start)
{
	int tmp = arr[start];
	int i = start * 2 + 1;

	while (i < len)
	{
		if (i + 1 < len && arr[i + 1] > arr[i])
		{
			i += 1;
		}
		// ��һ���ж���ɺ���iλ���Һ��ӽϴ����һ��

		if (arr[i] < tmp)
		{
			break;
		}

		arr[start] = arr[i];
		start = i;
		i = 2 * start + 1;
	}

	arr[start] = tmp;
}

//O(nlogn)   O(1)
void CreateHeap(int *arr, int len)
{
	for (int i = (len - 2) / 2; i >= 0; --i)
	{
		Adjust(arr, len, i);
	}
}

// O(nlogn)   O(1)   ���ȶ�
void HeapSort(int *arr, int len)
{
	CreateHeap(arr, len);

// 	for (int i = 0; i < len; ++i)
// 	{
// 		Swap(&arr[0], &arr[len - 1 - i]);
// 		Adjust(arr, len - 1 - i, 0);
// 	}

	int end = len - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		Adjust(arr, end, 0);
		end--;
	}
}

// ��·�鲢  O(n)  O(n)   �ȶ� 
void Meger(int *arr, int len, int width)
{
	int low1 = 0;
	int high1 = low1 + width - 1; // -1ʹ��high1Ϊ�������һ��Ԫ�ص��±�
	int low2 = high1 + 1;
	int high2 = low2 + width - 1 < len - 1 ? low2 + width - 1 : len - 1;

	int *brr = (int *)malloc(sizeof(int) * len);
	assert(brr != NULL);

	int index = 0;
	while (low1 < len)  //ֻҪ��һ���λ�û�ϲ���brr�У�ѭ������ִ��
	{
		//��˳��鲢�������ڵĶΣ� �˳�ʱ���п��ܵ�һ�������ݹ鲢���
		//Ҳ�п����ǵڶ��������ݹ鲢���
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] < arr[low2])
			{
				brr[index++] = arr[low1++];
			}
			else
			{
				brr[index++] = arr[low2++];
			}
		}

		//����һ����ʣ������ݴ洢��brr��
		while (low1 <= high1)
		{
			brr[index++] = arr[low1++];
		}
		//���ڶ�����ʣ������ݴ洢��brr��
		while (low2 <= high2)
		{
			brr[index++] = arr[low2++];
		}

		// ��������鲢ʣ��Ķ�
		low1 = high2 + 1;
		high1 = low1 + width - 1 < len - 1 ? low1 + width - 1 : len - 1;
		low2 = high1 + 1;
		high2 = low2 + width - 1 < len - 1 ? low2 + width - 1 : len - 1;
	}

	for (int i = 0; i < len; ++i)
	{
		arr[i] = brr[i];
	}

	free(brr);
}

//  O(nlogn)  O(n)    �ȶ�
void MegerSort(int *arr, int len)
{
	for (int i = 1; i < len; i *= 2)
	{
		Meger(arr, len, i);
	}
}

//O(n)
int GetWidth(int *arr, int len)
{
	int max = arr[0];
	for (int i = 1; i < len; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	// ����max��λ��   1234   234
	int width = 0;
	while (max > 0)
	{
		width += 1;
		max /= 10;
	}

	return width;
}

//  1234
// O(d)
int GetRadixVal(int val, int digit) // val = 1234 digit = 0
{
	while (digit > 0)
	{
		val /= 10;
		digit--;
	}

	return val % 10;
}

//O(dn)   O(n)   �ȶ�
void RadixSort(int *arr, int len)
{
	Que que[10];
	for (int i = 0; i < 10; ++i)
	{
		que[i].data = (int *)malloc(sizeof(int)* len);
		assert(que[i].data != NULL);
		que[i].head = que[i].tail = 0;
	}
	int width = GetWidth(arr, len);

	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < len; j++)
		{
			int digitval = GetRadixVal(arr[j], i);
			que[digitval].data[que[digitval].tail++] = arr[j];
		}	

		int count = 0;
		for (int k = 0; k < 10; ++k)
		{
			while (que[k].head != que[k].tail)
			{
				arr[count++] = que[k].data[que[k].head++];
			}

			que[k].head = que[k].tail = 0;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		free(que[i].data);
	}
}

void Show(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d  ", arr[i]);
	}

	printf("\n");
}

int main()
{
	int arr[] = {35,26,13,228,65,45,139,42,717,239,83, 123,563,1276};

	int len = sizeof(arr) / sizeof(arr[0]);

	//BubbleSort(arr, len);
	//SelectSort(arr, len);
	//QuickSort(arr, len);
	//HeapSort(arr, len);
	//MegerSort(arr, len);
	RadixSort(arr, len);
	Show(arr, len);

}