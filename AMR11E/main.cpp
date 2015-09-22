#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int t,a[10000]={0},i,j;
    for(i=2;i<10000;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<10000;j++)
                if(j%i==0)
                    a[j]++;
        }
    }

    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=2;i<10000;i++)
        {
            if(a[i]>=3) n--;
            if(n==0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
