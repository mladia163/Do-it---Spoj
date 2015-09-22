#include <iostream>
#include <stdio.h>
using namespace std;
long long int i,j,a[10000001];
void test()
{
    for(i=2;i<10000001;i++)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<10000001;j+=i)
                if(a[j]==0)
                    a[j]=i;
            a[j]=i+a[j-1];
        }
        else
            a[j]=a[j-1]+a[j];
    }
}
int main()
{
    test();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int num;
        scanf("%lld",&num);
        printf("%lld\n",a[num]);
    }
    return 0;
}
