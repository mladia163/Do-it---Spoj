#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,n,u,vol,c,i,j,k=0;
        cin>>V>>n;
		V/=10;
        vector< pair<int, int > > graph[n+1],con[n+1];
        vector< pair<int, int > > items;
        items.clear();
        for(i=0;i<=n;i++)
        {
            graph[i].clear();
            con[i].clear();
        }

        items.push_back((make_pair(0,0)));
        for(i=1;i<=n;i++)
        {
            cin>>vol>>c>>u;
			vol/=10;
            if(u!=0)
            {
                graph[u].push_back(make_pair(vol,vol*c));
                items.push_back(make_pair(items[u].first,items[u].second));
            }
            else
            {
                items.push_back(make_pair(vol,vol*c));
                k++;
            }
        }

        for(i=1;i<=n;i++)
        {
            if(graph[i].size()!=0)
            {
                for(j=0;j<graph[i].size();j++)      // for adding one item per head
                {
                    int t1=items[i].first+graph[i][j].first;
                    int t2=items[i].second+graph[i][j].second;
                    con[i].push_back(make_pair(t1,t2));
                }
                if(graph[i].size()==2)
                {
                    int t1=items[i].first+graph[i][0].first+graph[i][1].first;
                    int t2=items[i].second+graph[i][0].second+graph[i][1].second;
                    con[i].push_back(make_pair(t1,t2));
                }
            }
        }

        int dp[n+100][V+100],temp=0,temp1=0;

		for(i=0;i<=n;i++)
            for(j=0;j<=V;j++)
                dp[i][j]=0;

        for(i=0;i<=k;i++)
        {
            for(j=0;j<=V;j++)
            {
            	if(i>0)
        	    dp[i][j]=dp[i-1][j];
        	    if(i==0 || j==0)
                    dp[i][j]=0;
                else if(con[i].size()==0 && items[i].first<=j)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-items[i].first]+items[i].second);
                else if(con[i].size()!=0 && items[i].first>j)
                    dp[i][j]=dp[i-1][j];
                else if(con[i].size()!=0)
                {
            		temp1=0;
                    temp=max(dp[i-1][j],dp[i-1][j-items[i].first]+items[i].second);
                    for(int k1=0;k1<con[i].size();k1++)
                    {
                    	if(con[i][k1].first<=j)
                        	temp1=max(dp[i-1][j],dp[i-1][j-con[i][k1].first]+con[i][k1].second);
                        if(temp<temp1)
                            temp=temp1;
                    }
                    dp[i][j]=temp;
                }
            }
        }
        cout<<dp[k][V]*10<<"\n";
    }
    return 0;
}
