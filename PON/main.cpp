#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;
#define ll  long long int


ll mul(ll a,ll b,ll c)
{
    ll x=0,y=a%c;
    while(b>0)
    {
        if(b%2==1)  x=(x+y)%c;
        y=(y+y)%c;
        b/=2;
    }
    return x%c;
}

ll modexpo(ll a,ll b,ll c)          // this is mulmod when u are using powers upto 10^18
{
    ll x=1,y=a;
    while(b>0)
    {
        if(b&1)     x=mul(x,y,c);   // checking b%2==1
        y=mul(y,y,c);
        b/=2;
    }
    return x%c;
}

bool miller_rabin(ll p,ll it)
{
    if(p<2)     return false;
    if(p!=2 && p%2==0)      return false;

    ll s=p-1,i,a,temp,mod;
    while(s%2==0)   s/=2;
    for(i=0;i<it;i++)
    {
        a = rand()%(p-1)+1;
        temp=s;
        mod = modexpo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
            mod=mul(mod,mod,p),temp*=2;
        if(mod!=p-1 && temp%2==0)   return false;
    }
    return true;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll num;
        bool ans;
        scanf("%lld",&num);
        ans = miller_rabin(num,18);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
