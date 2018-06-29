#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

char h[100];

int main()
{
	scanf("%s",h);
	unsigned long x = 0;//注意这里用无符号 
	int i,cnt = 0;
	for(i = strlen(h) - 1; i >= 0; i--)
	{
		int v;
		if(h[i] >= '0' && h[i] <= '9')
		{
			v = h[i] - '0';
		}
		else
		{
			v = h[i] - 'A' + 10;
		}
		x = pow(16,cnt) * v + x;
		cnt++;
	}
	cout << x;
	return 0;
}
