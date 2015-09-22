#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int visited[10001]={0},ans=0;



int bfs(int temp,int n)
{
    int i;

    list<int> q;
    memset(visited, -1, sizeof(visited));
    visited[temp]=0;

    q.push_back(temp);

    while(!q.empty())
    {
        int temp2=q.front();
        //cout<<temp2<<" ";
        q.pop_front();
        for(i=0;i<tree[temp2].size();i++)
        {
            if(visited[tree[temp2][i]]==-1)
            {
                q.push_back(tree[temp2][i]);
                visited[tree[temp2][i]]=visited[temp2]+1;
            }
        }
    }

    int maxi=visited[temp],maxi_pos=temp;
    for(i=0;i<n;i++)
    {
        if(maxi<visited[i])
        {
            maxi=visited[i];
            maxi_pos=i;
        }
    }

    return maxi_pos;
}



int main()
{
    int n,i,a,b;
    cin>>n;

    for(i=1;i<n;++i)
    {
        cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    int ans;
    ans=bfs(0,n);
    ans=bfs(ans,n);
    cout<<visited[ans]<<endl;


    return 0;
}
