#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/c++io.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define NO(x) cout<<"Scenario #"<<x<<":\nNo suspicious bugs found!"<<endl;
#define YES(x) cout<<"Scenario #"<<x<<":\nSuspicious bugs found!"<<endl;
int graph[1001][1001],n;
//int color[1001]={-1};

bool isbarpetite(int x)
{
    queue<int> q;                       // 0 and 1 are the two colors
    int i,color[n],temp=0;
    memset(color,-1,sizeof(color));
    color[x] = 1;
    q.push(x);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        for(i=0;i<n;i++)
        {
            if(graph[temp][i] && color[i]==-1)
            {
                color[i] = 1-color[temp];
                q.push(temp);
                graph[temp][i]=0;
            }
            else if(graph[temp][i] && color[temp]==color[i])
                return false;
        }
        return true;
    }

}

int main()
{
    int t,tz=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,m,u,v;        // number of nodes = n && number of interactions = m
        scanf("%d %d",&n,&m);
        bool ans = true;
        memset(graph,0,sizeof(graph));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        queue<int> q;
        int color[n],temp=0;
        memset(color,-1,sizeof(color));
        for(i=1;i<=n;i++)
        {
            q.push(i);
            color[i] = 1;
            while(!q.empty())
            {
                temp = q.front();
                for(i=1;i<=n;i++)
                {
                    if(graph[temp][i] && color[i]==-1)
                    {
                        graph[temp][i] = 0;
                        color[i] = 1-color[temp];
                        q.push(graph[temp][i]);
                    }
                    else if(graph[temp][i] && color[i]==color[temp])
                    {
                        ans = false;
                        break;
                    }
                }
                q.pop();
                if(!ans)
                    break;
            }
            if(!ans)
                break;
        }
        if(ans)
            YES(tz)
        else
            NO(tz)
        tz++;
    }
    return 0;
}
