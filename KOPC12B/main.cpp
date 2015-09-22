#include <iostream>
#include <stdio.h>
using namespace std;
#define mod 1000000007
#define ll long long int

ll binomial(ll n,ll r)
{
    ll i,res=1;
    if(r>n-r)   r=n-r;
    for(i=1;i<=r;i++)
        res=(res*(n-i+1))/i;
    return ((res%mod)*(res%mod))%mod;
}

int main()
{
    int t;
    scanf("%d",&t);
    //cin>>t;
    while(t--)
    {
        ll n,ans=0,i;
        scanf("%lld",&n);
        //cin>>n;
        for(i=1;i<=n;i++)
        {
            ans = ans + ((i%mod)*binomial(n,i))%mod;
            ans = ans%mod;
        }
        ans=ans%mod;
        //cout<<ans<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}
