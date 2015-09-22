#include<bits/stdc++.h>
using namespace std;
int main()
{long long int n,a[200100],dp[200100],i,j;cin>>n;
    for(i=1;i<=n;i++)
    {cin>>a[i];
        dp[i]=9999999999;}dp[0]=dp[1]=0;
    for(i=2;i<=n;i++)
        for(j=1;j<=i;j=j*2)
            dp[i] = min(dp[i],abs(a[i]-a[i-j])+dp[i-j]);
    cout<<dp[n]<<endl;return 0;}
