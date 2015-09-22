#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
#define ll  long long int

map<ll,ll> yay;

ll solve(ll n)
{
    ll num;
    if(n==0)
        return 0;
    num = yay[n];
    if(num==0)
    {
        num = max(n,solve(n/2)+solve(n/3)+solve(n/4));
        yay[n]=num;
    }
    return num;
}
int main()
{
    ll t;
    while(cin>>t)
    {
       // yay.clear();
        ll ans;
        ans = solve(t);
        cout<<ans<<endl;
    }
    return 0;
}
