#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

const int N=10001;
int n;
bool visited[N];
bool ans=true;
vector<int> graph[N];

void dfs(int x)
{
    int i;
    for(i=0;i<graph[x].size();i++)
    {
        if(!visited[graph[x][i]])
        {
            visited[graph[x][i]]=true;
            dfs(graph[x][i]);
        }
    }
}

bool chq_extr_funct()
{
    int temp=0,i,j;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<graph[i].size();j++)
            if(visited[graph[i][j]])
                temp+=1;

        if(temp>1)
            return false;
    }
    return true;
}

int main()
{
    int m,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if((n-1)!=m)
        ans=false;
    else if(!chq_extr_funct())
        ans=false;
    else
    {
        visited[1]=true;
        dfs(1);
        for(i=1;i<=n;i++)
            if(!visited[i])
            {
                ans=false;
                break;
            }
    }

    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
