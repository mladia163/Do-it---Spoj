#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll  long long int
#define mmod    500000002

ll fast_exp(int base,int exp,int mod1)
{
    ll ans=1;
    while(exp>0)
    {
        if(exp%2)   ans=(ans*base)%mod1;
        base=(base*base)%mod1;
        exp/=2;
    }
    return ans%mod;
}

ll fact[210100],factinv[100010];

void fac()
{
    fact[0]=1;
    factinv[0]=1;
    for(int i=1;i<=200010;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
        if(i<=100010)
            factinv[i]=fast_exp(fact[i],mod-2,mod);
    }
}

ll bcoeff(int n)
{
    return ((fact[2*n]* (factinv[n]*factinv[n])%mod)%mod);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        ll bc = bcoeff(n)%mod;

        if(n==0)
            bc=1;

        ll ans=fast_exp(bc,b,mod-2);//%(mod-2);
        ll t1=fast_exp(a,ans,mod);

        if(a==0)
            t1=0;
        if(a==0 && ans==0)
            t1=1;
        if(ans==0)
            t1=1;
        cout<<t1<<"\n";
    }


    return 0;
}
