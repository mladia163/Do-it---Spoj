#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll  long long int
ll arr[2001];
bool chq_for_tri(ll a,ll b, ll c)
{
    if( a + b >= c )
        return false;
    else
        return true;
}

ll binary(ll a,ll b,ll c)
{
    while(b-a>1)
    {
        ll mid = (a+b)/2;
        if(c<arr[mid])
            b=mid;
        else
            a=mid;
    }
    if(c<arr[a])
        return a;
    return b;
}

int main()
{
    ll n;
    cin>>n;
    while(n!=0)
    {
        ll ans=0,j,i,temp=0;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        sort(arr+1,arr+n+1);

        if(n==3)
        {
            if(chq_for_tri(arr[1],arr[2],arr[3]))
                ans+=1;
        }
        else
        {
            for(i=1;i<=n-2;i++)
                for(j=i+1;j<=n-1;j++)
                {
                    if(arr[i]+arr[j]<arr[n])
                    {
                        temp=binary(i,n,arr[i]+arr[j]);
                        ans=ans+n+1-temp;
                    }
                }
        }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}
