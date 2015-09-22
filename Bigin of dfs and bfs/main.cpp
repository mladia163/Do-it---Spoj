#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;


int main()
{
    int u,v,n,m,i;
    cin>>n>>m;
    vector<int> graph[n+1];

    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[v].push_back(v);
        graph[u].push_back(u);
    }
    bool visited[n+1];
    for(i=0;i<n;i++)
        visited[i]=false;

    q.push(0);
    while(!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        visited[curr]=true;
        q.pop();
        for(i=0;i<graph[curr].size();i++)
        {
            if(visited[graph[curr][i]]==false)
            {
                q.push(graph[curr][i]);
                visited[graph[curr][i]]=true;
            }
        }
    }


    return 0;
}
