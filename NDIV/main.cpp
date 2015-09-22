#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
//#define sd(a)   scanf("%d",&a)

int solve(int n)
{
    int i,ans=1,k=0;
    while(n%2==0)
    {
        n/=2;
        //if(2>=a && 2<=b)
        k+=1;
    }
    if(k!=0)
        ans=ans*(k+1);
    k=0;
    for(i=3;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            //if(i>=a && i<=b)
            k+=1;
            n/=i;
        }
        if(k!=0)
            ans=ans*(k+1);
        k=0;
    }
    k=0;
    if(n>2)// && (n>=a && n<=b))
    {
        ++k;
        ans=ans*(k+1);
    }
    return ans;
}

int main()
{
    int a,b,n,ans=0,temp;
    cin>>a>>b>>n;
    for(int i=a;i<=b;i++)
    {
        temp = solve(i);
        if(temp == n)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
