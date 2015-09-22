#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
/*
typedef struct graph
{
    list<int> ad;
    bool visited;
    graph()
    {
        visited=false;
    }
}graph;
*/

int visited[100001];
vector<int> tree[100001];

void dfs(int v)
{
    int i;
    visited[v]=true;
    //cout<<v<<" ";
    for(i=0;i<tree[v].size();i++)
        if(!visited[tree[v][i]])
            dfs(tree[v][i]);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e,ans=0,n,a,b,i;
        cin>>n>>e;
        for(i=0;i<n;i++)
        {
            tree[i].clear();
            visited[i]=0;
        }
        for(i=0;i<e;i++)
        {
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
