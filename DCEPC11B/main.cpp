#include <iostream>
#include <stdio.h>
using namespace std;
#define ll  long long int
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll i,n,p,ans=1;
        scanf("%lld %lld",&n,&p);
        for(i=n;i>=2;i--)
        {
            ans=((ans)*(i%p))%p;
        }
        cout<<ans%p<<endl;
    }
    return 0;
}
