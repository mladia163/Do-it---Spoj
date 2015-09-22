#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2001];
int colour[2001],mark[2001];


bool check_bipartite(int v)
{
    int i,j,temp;
    bool ans=false;
    for(i=1;i<=v;i++)
    {
        if(mark[i]==0)
        {
            queue<int> q;
            q.push(i);
            colour[i]=1;
            while(!q.empty())
            {
                temp=q.front();
                q.pop();
                for(j=0;j<graph[temp].size();j++)
                {
                    if(colour[graph[temp][j]]==-1)
                        colour[graph[temp][j]]=1-colour[temp];
                    else if(colour[graph[temp][j]]==colour[temp])
                    {
                        ans=true;
                        break;
                    }
                    if(mark[graph[temp][j]]==0)
                        q.push(graph[temp][j]);
                }
                mark[temp]=1;
                if(ans)
                    break;
            }
        }
        if(ans)
            break;
    }
    return ans;
}


int main()
{
    int t,k=1;
    scanf("%d",&t);
    while(t--)
    {
        int v,n,i,a,b;
        for(i=0;i<2001;i++)
        {
            graph[i].clear();
            colour[i]=-1;
            mark[i]=0;
        }
        scanf("%d %d",&v,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool ans_final=check_bipartite(v);

        printf("Scenario #%d:\n",k);
        if (ans_final)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");

        k+=1;
    }
    return 0;
}
