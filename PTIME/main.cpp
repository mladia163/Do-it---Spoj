#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int a[10009] = {0};

void prime_factors(int n)
{
    while(n%2==0)
    {
        a[2]++;
        n/=2;
    }

    for(int j=3;j<=sqrt(n);j++)
        while(n%j==0)
        {
            a[j]++;
            n/=j;
        }

    if(n>2)
        a[n]++;
}

int main()
{
    int n,i,k;
    scanf("%d",&n);
    for( i=2 ; i<=n ; i++)
        prime_factors(i);

    for( i=2 ; i<=n ; i++ )
        if(a[i]!=0)
            k=i;

    for( i=2 ; i<=k ; i++ )
        if( i == k )
            printf("%d^%d",i,a[i]);
        else if( a[i] != 0 )
            printf("%d^%d * ",i,a[i]);

    return 0;
}
