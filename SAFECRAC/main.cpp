#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll  long long int
#define pb  push_back

ll dp[100001][11];
vector<int> graph[12];

void preprocess()
{
    int i,j,k;
    long long int temp=0,ans1=0;
    // enter all the adjacent ones
    for(i=0;i<11;i++)
        dp[0][i]=0;

    for(i=0;i<=9;i++)
        dp[1][i]=1;
    dp[1][10]=10;

    graph[0].pb(7);

    graph[1].pb(2);
    graph[1].pb(4);

    graph[2].pb(1);
    graph[2].pb(5);
    graph[2].pb(3);

    graph[3].pb(6);
    graph[3].pb(2);

    graph[4].pb(1);
    graph[4].pb(5);
    graph[4].pb(7);

    graph[5].pb(2);
    graph[5].pb(4);
    graph[5].pb(6);
    graph[5].pb(8);

    graph[6].pb(3);
    graph[6].pb(5);
    graph[6].pb(9);

    graph[7].pb(4);
    graph[7].pb(8);
    graph[7].pb(0);

    graph[8].pb(5);
    graph[8].pb(7);
    graph[8].pb(9);

    graph[9].pb(6);
    graph[9].pb(8);


    for(i=2;i<100001;i++)
    {
        ans1=0;
        for(j=0;j<=9;j++)
        {
            temp=0;
            for(k=0;k<graph[j].size();k++)
                temp=temp+dp[i-1][graph[j][k]];
            dp[i][j]=temp%mod;
            ans1=(ans1+dp[i][j]);
        }
        dp[i][10]=ans1%mod;
    }
}


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    preprocess();
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        //for(i=0;i<=9;i++)
          //  cout<<dp[n][i]<<" ";
        //cout<<endl;
        cout<<dp[n][10]<<endl;
    }
    return 0;
}
