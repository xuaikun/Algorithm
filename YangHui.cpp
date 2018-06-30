#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int L[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(j == 0 || i == j)
			{
				L[i][j] = 1;
				if(i == j) break;
			}
			else
			{
				//本行中间值等于肩上两个数之和 
				//画图找规律 
				L[i][j] = L[i-1][j-1]+L[i-1][j];
			}
			
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j) 
			{
				cout << L[i][j] << " ";	
				cout<<endl;
				break;
			}
			cout << L[i][j] << " ";	
		}
	}
	return 0;
}
