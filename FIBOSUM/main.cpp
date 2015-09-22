#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define ll  long long int
#define mod     1000000007

/* function that returns nth Fibonacci number */

void multiply(ll f[2][2],ll m[2][2])
{
    ll x = ((f[0][0]*m[0][0])%mod+(f[0][1]*m[1][0])%mod)%mod;
    ll y = ((f[0][0]*m[0][1])%mod+(f[0][1]*m[1][1])%mod)%mod;
    ll w = ((f[1][0]*m[0][0])%mod+(f[1][1]*m[1][0])%mod)%mod;
    ll z = ((f[1][0]*m[0][1])%mod+(f[1][1]*m[1][1])%mod)%mod;

    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = w;
    f[1][1] = z;
}

ll power(ll exp)
{
    ll ans[2][2] = {{1,0} , {0,1}};
    ll m[2][2] = {{0,1} , {1,1}};
    exp--;
    while(exp)
    {
        if(exp%2==1)
            multiply(ans,m);
        multiply(m,m);
        exp/=2;
    }
    return ans[0][1]%mod;
}

ll sum(ll n)
{
    return power(n+2)-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,ans=0;
        cin>>n>>m;
        //cout<<power(n);
        ans = (sum(m+1)-sum(n))%mod;
        if(ans<0)
            ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
