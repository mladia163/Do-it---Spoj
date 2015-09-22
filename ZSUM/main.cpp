#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define sdl(a)  scanf("%lld",&a)
#define mod     10000007
#define ll      long long int


ll exp_mul(ll base,ll exp)
{
    ll res = 1;
    while(exp>0)
    {
        if(exp%2==1)
            res = ( res * base ) % mod;
        base = ( base * base ) % mod;
        exp/=2;
    }
    return ( res % mod );
}


int main()
{
    ll n,k;
    sdl(n);
    sdl(k);
    while(n!=0 && k!=0)
    {
        ll ans=0,pn2=0,sn2=0,sn1=0,pn1=0,sn=0,pn=0,zn=0,zn1=0,zn2=0;

        //for(i=1;i<=(n-2);i++)
        //{
         //   sn2 += exp_mul(i,k);
          //  pn2 += exp_mul(i,i);
            //sn2 = sn2 % mod;
           // pn2 = pn2 % mod;
        //}

        //sn2 = exp_mul(n-2,k);
        //pn2 = exp_mul(n-2,n-2);

        sn1 = exp_mul(n-1,k);
        pn1 = exp_mul(n-1,n-1);
        //sn1 = sn1 % mod;
        //pn1 = pn1 % mod;
        sn = exp_mul(n,k);
        pn = exp_mul(n,n);
        //sn = sn % mod;
        //pn = pn % mod;

        //zn2 = ( sn2 + pn2 ) % mod;
        //zn1 = ( sn1 + sn ) % mod;
        //zn = ( pn1 + pn ) % mod;

        ans = ( sn + 2*sn1 + pn + 2*pn1 ) %mod;

        cout<<ans<<endl;
        sdl(n);
        sdl(k);
    }
    return 0;
}
