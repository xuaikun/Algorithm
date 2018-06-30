/*求子串中回文子串的个数*/
//链接：https://blog.csdn.net/nwpu_yike/article/details/20871141
#include <iostream>  
#include <string.h> 
using namespace std;  
  
int main(int argc, char* argv[])  
{  
    char s[5000];  
    int p, i, Half, Left, Right, Count;  
    while( cin>>s )  
    {  
        i = strlen(s);  
        Count = 0;  
        //从左到右钉住最后一个  
        for(p=0; p<=i-1; p++)  
        {  
            Half = ((i-1)-p) / 2;  
            //如果子串是奇数个  
            if( ((i-1)-p)%2 == 0 )  
            {  
                Left = p + Half - 1;  
                Right = p + Half + 1;  
            }  
            else   //如果子串是偶数个  
            {  
                Left = p + Half;  
                Right = p + Half + 1;  
            }  
            while( Left >= p )  
            {  
                if( s[Left] == s[Right])    
                {  
                    Count++;  //发现了一个回文串  
                    Left--;  
                    Right++;  
                }  
                else  //如果不相等，立即终止，由中心向外扩散不可能会有回文串  
                {  
                    break;  
                }  
            }  
        }  
        //从右到左钉住第一个  
        for(p=i-2; p>=1; p--)  
        {  
            Half = p / 2;  
            //如果子串是奇数个  
            if( p%2 == 0 )  
            {  
                Left = Half - 1;  
                Right = Half + 1;  
            }  
            else   //如果子串是偶数个  
            {  
                Left = Half;  
                Right = Half + 1;  
            }  
            while( Left >= 0 )  
            {  
                if( s[Left] == s[Right] )  
                {  
                    Count++;  //发现了一个回文串  
                    Left--;  
                    Right++;  
                }  
                else  //如果不相等，立即终止，由中心向外扩散不可能会有回文串  
                {  
                    break;  
                }  
            }  
        }  
        printf("%d\n",Count + i);  
    }  
    return 0;  
}  
