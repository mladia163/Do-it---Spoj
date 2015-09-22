#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define sd(a)   scanf("%d",&a)

ll arr[100001];
bool all_stable(int x,int cow,int n)
{
    ll i,pos=arr[0];
    cow-=1;
    for(i=1;i<n;i++)
    {
        if((pos+x)<=arr[i])
           --cow,pos=arr[i];
        if(cow==0)
            return true;
    }
    return false;
}



int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int n,c,i;
        sd(n);
        sd(c);
        ll low=0,high=1000000000;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n);
		high=arr[n-1]-arr[0];
        if(c==2)
            cout<<high<<endl;
        else
        {
            while(high>low+1)
            {
                ll mid = (low+high)/2;
                if(all_stable(mid,c,n))
                    low=mid;
                else
                    high=mid;
            }

            if(all_stable(high,c,n))
                cout<<high<<endl;
            else
                cout<<low<<endl;
        }
    }
    return 0;
}
