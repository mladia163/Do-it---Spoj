#include <iostream>
#include <stdio.h>
using namespace std;
long long int binomial(long long int n,long long int k)
{
    long long int res=1,i;
    //as we know nCk=nCn-k so
    if(k>n-k)
        k=n-k;
    //n-k+1 tak nikalna h
    for(i=1;i<=k;i++)
    {
        res=res*(n-i+1);
        res=res/i;
    }
    return res;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        printf("%lld\n",binomial(n-1,k-1));
    }
    return 0;
}
