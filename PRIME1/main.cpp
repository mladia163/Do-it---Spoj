#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void mark_multiples(bool arr[],long long int n,long long int p)
{
    long long int i,num;
    while((num=i*p)<=n)
    {
        arr[num-1]=1;
        ++i;
    }
}


void seive_of_eras(long long int n)
{
    if(n>=2)
    {
        bool arr[n+1];
        memset(arr,0,sizeof(arr));
        long long int i;
        for(i=1;i<=n;i++)
            if(arr[i]==0)
                mark_multiples(arr,n,i+1);
    }
}





int main()
{
    int n,i;
    cin>>n;
    seive_of_eras(n);
    for(i=0;i<1000;i++)
        if(arr[i]==0)
            cout<<i+1<<"\t";

    return 0;
}
