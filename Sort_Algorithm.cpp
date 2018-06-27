#include <iostream> 
using namespace std;

void Input(int *L, int n);
void SelectSort(int *L, int n);
void BubbleSort(int *L, int n);
void InserSort(int *L, int n);
void MergeSort(int *L, int n);
void Merge(int *LA, int n, int *LB, int m, int *LC);
void QuickSort(int *L, int l, int r); 
int Partition(int *L, int l, int r);
void Output(int *L, int n);

int main()
{
	int n, m;
	cin >> n;
	int LA[n];
	
	Input(LA, n);
	//SelectSort(LA, n);//选择排序 
	//BubbleSort(LA, n);//冒泡排序 
	//InserSort(LA, n);//插入排序
	//MergeSort(LA, n);//归并排序 
	QuickSort(LA, 0, n - 1); //快速排序 
	/*测试两个数组合并*/
	//cin >> m;
	//int LB[m];
	//Input(LB, m);
	//int LC[n + m];
	//Merge(LA, n, LB, m, LC);
	Output(LA, n); 
	
	return 0;
}

void Input(int *L, int n)
{
	for(int i = 0; i < n; i++)
	{
		cin >> L[i];
	}
}

void SelectSort(int *L, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int Min = i, temp;
		for(int j = i + 1; j < n; j++)	
		{
			if(L[Min] > L[j])
			{
				Min = j;
			}
		}
		{
			temp = L[Min];
			L[Min] = L[i];
			L[i] = temp;
		}
	}	
}

void BubbleSort(int *L, int n)
{
	int temp;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(L[j + 1] < L[j])
			{
				temp = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp;
			}
		}
	}
}

void InserSort(int *L, int n)
{
	for(int i = 0; i < n; i++)
	{
		int v = L[i];
		int j = i - 1;
		while(j >= 0 && L[j] > v)
		{
			L[j + 1] = L[j];
			j = j - 1;
		}
		L[j + 1] = v;
	}
}

void MergeSort(int *L, int n)
{
	int A[n/2];
	int B[n/2];
	if(n > 1)
	{
		if(n % 2 == 0)//n为偶数
		{
			for(int i = 0; i < n/2; i++)
			{
				A[i] = L[i];	
			}	
			for(int i = 0, j = n/2; j < n; j++,i++)
			{
				B[i] = L[j];
			}
			MergeSort(A, n/2);
			MergeSort(B, n/2);
			Merge(A, n/2, B, n/2, L);
		}
		else//n为奇数
		{
			for(int i = 0; i < (n + 1)/2; i++)
			{
				A[i] = L[i];	
			}		
			for(int i = 0, j = (n + 1)/2; j < n; j++, i++)
			{
				B[i] = L[j];
			}
			MergeSort(A, (n + 1)/2);
			MergeSort(B, (n - 1)/2);
			Merge(A, (n + 1)/2, B, (n - 1)/2, L);
		} 
	}
}
void Merge(int *LA, int n, int *LB, int m, int *LC)
{
	int i = 0, j = 0, k = 0;
	while(i < n && j < m)
	{
		if(LA[i] > LB[j])
		{
			LC[k] = LB[j];
			j++;
		}
		else
		{
			LC[k] = LA[i];
			i++;
		}
		k++;
	}
	if(i == n)
	{
		for(int q = j; q < m; q++)
		{
			LC[k] = LB[q];
			k++;
		}
	}
	else
	{
		for(int q = i; q < n; q++)
		{
			LC[k] = LA[q];
			k++;
		}
	}
}

void QuickSort(int *L, int l, int r)
{
	int s;
	if(l < r)
	{
		s = Partition(L, l, r);
		QuickSort(L, l, s - 1);
		QuickSort(L, s + 1, r);
	}
}
int Partition(int *a, int low, int high)
{
	int part_element = a[low];
    for (;;)
	 {
        while (low < high && part_element <= a[high]) 
		{
            high--;
        }
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element) 
		{
            low++;
        }
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

void Output(int *L, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << L[i] << " ";
		 
	}	
} 
