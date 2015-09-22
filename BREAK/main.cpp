//if cycle then in degree + cycle if connects else just play from in degree ;) :p
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
vector<int> rgraph[10000];
int k=0,visit[10000];
int indegree[10000];
//int indegree1[10000];
vector<int> scc[10000];
stack<int>  finishing_time;
vector<int> ggraph[10000];

void fdfs(int v)
{
    visit[v]=1;
    cout<<v<<" ";
    for(int i=0;i<graph[v].size();i++)
        if(!visit[graph[v][i]])
            dfs(graph[v][i]);
    finishing_time.push(v);
}

void rdfs(int v)
{
    visit[v]=1;
    scc[k].push_back(v);
    for(int i=0;i<rgraph[v].size();i++)
        if(!visit[rgraph[v][i]])
            rdfs(rgraph[v][i]);
}


int main()
{
    int t;
    cin>t;
    while(t--)
    {
        int u,v,i,j,n,m,k=0,maxi=-1;
        cin>>n>>m;
        memset(visit,0,sizeof visit);
        memset(indegree1,0,sizeof indegree1);
        memset(indegree,0,sizeof indegree);
        for(i=0;i<=n;i++)
        {
            ggraph[i].clear();
            scc[i].clear();
            graph[i].clear();
            rgraph[i].clear();
        }
        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            indegree[v]++;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }

        for(i=1;i<=n;i++)
        {
            // taking out the maximum importance
            if(indegree[i]!=0)
                maxi=max(maxi,indegree[i]);

            if(visit[i]==0)
                fdfs(i);
        }
        memset(visit,0,sizeof 0);
        bool tree=true;
        while(!finishing_time.empty())
        {
            int temp=finishing_time.top();
            finishing_time.pop();
            if(visit[temp]==0)
            {
                rdfs(temp);
                if(scc[k].size()>1)
                    tree=false;
                k++;
            }
        }

        if(tree)
        {

        }
        else
        {
            for(i=0;i<k;i++)
            {




            }

        }

    }
    return 0;
}
