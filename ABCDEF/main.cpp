#include <bits/stdc++.h>
using namespace std;

int v[2000000];

int main()
{
    int n,i;
    cin>>n;
    int a[n+1],j,k,p=0;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    v[p++]=(a[i])*(a[j]+a[k]);
        }
    }
    sort(v,v+p);
    int tc=0;
    long long int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                tc=a[i]*a[j]+a[k];
                ans+=(upper_bound(v,v+p,tc)-lower_bound(v,v+p,tc));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
