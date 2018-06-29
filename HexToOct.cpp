#include <iostream>

#include <string.h>

using namespace std;

char h[100002], b[400002], e[400002];

int main()
{
	int n;//定义输入的行数
	cin >> n;
	while(n--)
	{
		scanf("%s",h);	
		int i, len = 0;
		/*十六进制转二进制的操作*/
		for(i = strlen(h) - 1; i >= 0; i--)
		{
			int v;
			if(h[i] >= '0' && h[i] <= '9')
			{
				v = h[i] - '0';
			}else{
				v = h[i] - 'A' + 10;
			}
			for(int j = 0; j < 4; j++)
			{
				b[len++] = v % 2 + '0';
				v /= 2;
			}
		}
		b[len] = '\0';
		/*二进制转换成八进制*/
		int x = 0;//对三个二进制数求和 
		int cnt = 1;//用于表示2的几次幂的指 
		int l = 0; //用于保存八进制数的下标
		for(i = 0; i < len; i++)
		{
			if(cnt == 4 || i == len -1)
			{
				x = cnt *(b[i] - '0') + x;
				e[l++] = x + '0';
				cnt = 1;
				x = 0;
			}
			else
			{
				x = cnt *(b[i] - '0') + x;
				cnt *= 2;
			}
		} 
		/*输出部分*/
		i = l - 1;
		while(i >= 0 && e[i] == '0')
		{/*去掉前导0*/
			i--;	
		}
		if(i < 0){
			cout << 0;
		}
		for(; i >= 0; i--)
		{
			cout << e[i];
		}
		cout << endl;
	} 
	
	return 0;
}
