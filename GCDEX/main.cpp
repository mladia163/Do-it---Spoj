#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define MAX 1000001

int phi[MAX]={0};
ll G[MAX]={0};
/*
void euler_phi()            // calculating all the phi[i] via seive and euler function :p
{
    phi[1]=1;
    ll i,j;
    for(i=2;i<MAX;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=2*i;j<MAX;j+=i)
            {
                if(!phi[j])     phi[j]=j;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
        G[i]=phi[i];
    }
}

void calc_gcd()
{
    ll j,i;
    memset(G,0,sizeof(G));
    euler_phi();

    for(i=2;i<MAX;i++)
    {
        for(j=2;i*j<MAX;j++)
			G[i*j]+=(i*phi[j]);
        if(i!=1)
            G[i]+=G[i-1];
    }
}
*/

int main()
{
    ll n,i,j;
    phi[1]=1;
    for(i=2;i<MAX;i++)
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=2*i;j<MAX;j+=i)
            {
                if(!phi[j])     phi[j]=j;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }

    for(i=1;i<MAX;i++)
        for(j=2;i*j<MAX;j++)
			G[i*j]+=(i*phi[j]);

    for(i=2;i<MAX;i++)
        G[i]+=G[i-1];

    while(scanf("%lld",&n)!=EOF)
        printf("%lld\n",G[n]);

    return 0;
}
