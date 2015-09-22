#include <iostream>
#include <stdio.h>
using namespace std;
/*
int subarraysum(int a[],int n,int sum)
{
    int i,j,temp = 0;
    for(i=0;i<n;i++)
    {
        temp = a[i];
        for(j=i+1;j<n;j++)
        {
            if(temp==sum)
                return i;
            if(temp>sum || j==n)
                break;
            temp += a[j];
        }
    }
    return 0;
}*/

long long int subarraysum(long long int a[],long long int n,long long int sum)
{
    long long int i=1,curr_sum=a[0],start=0,max_sum=0;
    for(i=1;i<=n;i++)
    //while(n--)
    {
        while(curr_sum>sum && start<i-1)
        {
            curr_sum = curr_sum - a[start];
            start++;
        }
        if(max_sum<curr_sum)
            max_sum=curr_sum;
        curr_sum += a[i];
    //    i++;
    }
    return max_sum;
}


int main()
{
    long long int n,m;
    //cin>>n>>m;
    scanf("%lld %lld",&n,&m);
    long long int a[n],i;
    for(i=0;i<n;i++)
        //cin>>a[i];
        scanf("%lld",&a[i]);
    //cout<<subarraysum(a,n,m)<<endl;
    printf("%lld",subarraysum(a,n,m));
    return 0;
}
