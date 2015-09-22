#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int euler_totient_funct(int n)
{
    int result=n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            result = result-result/i;
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        result = result-result/n;
    return result;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int num,result=0;
        scanf("%d",&num);
        result = euler_totient_funct(num);
        printf("%d\n",result);
    }
    return 0;
}
