#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)


int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int n,k;
        sd(n);
        sd(k);
        int a[n+1],i;
        for(i=1;i<=n;i++)
            sd(a[i]);
        sort(a+1,a+n+1);
        int ans=INT_MAX;
        if(k==1)
            cout<<"0"<<endl;
        else
        {
            for(i=1;i<=n-k+1;i++)
                if(ans>(a[k+i-1]-a[i]))
                    ans=a[k+i-1]-a[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
