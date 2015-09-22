#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long int sum(long long int m,long long int n)
{
    long long int temp=0,i,a[4]={0,0,0,1},res=0,k=0;
    for(i=4;i<=n;i++)
    {
        temp=a[0]+a[1]+a[2]+a[3];
        temp=temp%1000000007;
        if(k>3)
            k=0;
        a[k++]=temp;
        if(i>=m)
        {
            res+=temp;
            res=res%1000000007;
        }
    }
    return res%1000000007;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int m,n;
        unsigned long long int res=0;
        cin>>m>>n;
        res = sum(m,n);
        cout<<res%1000000007<<endl;
    }
    return 0;
}
