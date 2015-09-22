#include <iostream>

using namespace std;

long long int getone(long long int a[],long long int n)
{
    int i,dp[n][2],j,maxi=0;
    for(i=0;i<n;i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 0;
        for(j=0;j<i;j++)
        {
            if(a[i]>=a[j] && dp[i][0]<dp[j][0]+1 && dp[j][1]!=1)
                dp[i][j]
        }
    }
    for(i=0;i<n;i++)
        if(maxi<dp[i])
            maxi = dp[i];
    maxi = maxi+1;
    return maxi;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,i;
        cin>>n;
        long long int a[n],ans=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        ans = getone(a,n);
        cout<<ans<<endl;
    }
    return 0;
}
