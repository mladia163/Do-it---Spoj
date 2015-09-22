#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define sd(a)   scanf("%d",&a)

ll find_(ll temp,ll arr[],int n)
{
    ll total=0,i;
    for(i=0;i<n;i++)
        total=total+(temp/arr[i]);
    return total;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,T,i;
        sd(n);
        sd(T);
        ll a[n+1],maxi=INT_MIN,mini=INT_MAX,mid=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
        }

        ll low=1,high=maxi*T,hum=0;
        while(low<high)
        {
            mid=(low+high)/2;
            hum=find_(mid,a,n);
            if(hum<T)
                low=mid+1;
            else if(hum>=T)
                high=mid;
        }
        cout<<high<<endl;
    }
    return 0;
}
