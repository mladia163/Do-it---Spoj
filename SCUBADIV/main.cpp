#include <bits/stdc++.h>
using namespace std;
#define ll  long long int

ll dp[1011][22][80];    // n,oxygen,nitrogen
int wt[1011];
int oxygen[1011];
int nitrogen[1011];



int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int O,N,k,i,j,n;
        cin>>O>>N;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>oxygen[i]>>nitrogen[i]>>wt[i];

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=O;j++)
            {
                for(k=0;k<=N;k++)
                {
                    if(i==0)
                    {
                        dp[i][j][k]=INT_MAX;
                        if(j==0 && k==0)    dp[i][j][k]=0;
                    }
                    else
                    {
                        dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][max(0,j-oxygen[i])][max(0,k-nitrogen[i])]+wt[i]);
                    }
                }
            }
        }
        cout<<dp[n][O][N]<<"\n";
    }
    return 0;
}
