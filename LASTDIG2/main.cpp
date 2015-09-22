#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int b;
        int base,base1,res=1;
        string arr;
        scanf("%s %llu",arr,&b);
        base=base1=arr[arr.length()-1]-'0';
        if(base==0)
            printf("0\n");
        else
        {
            while(b>0)
            {
                if(b%2!=0)
                {
                    res=res*base;
                        res=res%10;
                }
                base=base*base1;
                base=base%10;
                b=b/2;
            }
            printf("%d\ n",res);
        }
    }
    return 0;
}
