#include <bits/stdc++.h>
using namespace std;
#define mod     1000000007
#define sd(a)   scanf("%d",&a)


void multiply(long long int f[2][2],long long int m[2][2])
{
    long long int x,y,z,w;
    x = ((f[0][0]*m[0][0])%mod+(f[0][1]*m[1][0])%mod)%mod;
    y = ((f[0][0]*m[0][1])%mod+(f[0][1]*m[1][1])%mod)%mod;
    z = ((f[1][0]*m[0][0])%mod+(f[1][1]*m[1][0])%mod)%mod;
    w = ((f[1][0]*m[0][1])%mod+(f[1][1]*m[1][1])%mod)%mod;
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
}

long long int power(long long int exp)
{
    long long int ans[2][2] = {{1,0},{0,1}};
    long long int f[2][2]={{1,1},{1,0}};
    if( exp == 0 || exp == 1)
      return 1;
    while(exp)
    {
        if(exp%2==1)
            multiply(ans,f);
        multiply(f,f);
        exp/=2;
    }
    return ans[0][0]%mod;
}

int main()
{
    int t;
    sd(t);
    while(t--)
    {
        long long int ans=0,n,a,b;
        scanf("%lld",&n);
        //cout<<power(n)<<endl;
        a = power(n);
        b = power(n+1);
        ans = ((a%mod)*(b%mod))%mod;
        ans-=1;
        cout<<"$"<<ans<<endl;
    }
    return 0;
}
