#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define ll   long long int

vector<int> gg;
void calc(ll n)
{
    int temp=0;
    while(n%2==0)
        temp++,n/=2;
    if(temp>0)  gg.push_back(temp);
    ll k;
    for(k=3;k<=sqrt(n);k+=2)
    {
        temp=0;
        while(n%k==0)
            temp++,n/=k;
        if(temp>0)  gg.push_back(temp);
    }
    if(n>2) gg.push_back(1);
}
// as a^2 = (c-b)*(c+b)         and (c-b) wld be smallest factor so ans = (factors of n^2)/2
int main()
{
    int t;
    sd(t);
    while(t--)
    {
        ll n,ans=1,i;
        double ans1=0;
        gg.clear();
        scanf("%lld",&n);
        calc(n);
        for(i=0;i<gg.size();i++)
            ans=ans*(2*gg[i]+1);
        ans1=ans/2;
        cout<<ceil(ans1)<<endl;
    }
    return 0;
}
