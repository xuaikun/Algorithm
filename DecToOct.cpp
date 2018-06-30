#include <iostream>
using namespace std;

int main()
{
	long x;
	int l = 0;
	cin >> x;
	char b[10], a[8]= {'0','1','2','3','4','5','6','7'};
	
	if(x < 0)
	{
		cout << 0;
	}
	while(x)
	{
		b[l++] = a[x%8];
		x /= 8;
	}
	for(int i = l - 1; i >= 0; i--)
	{
		cout << b[i];
	}
	return 0;
}
