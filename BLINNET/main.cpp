#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)

vector< pair< long long int , pair< int , int > > > graph;
long long int parent[10002];

void reset()
{
    for(int i=0;i<=10001;i++)
        parent[i] = i;
}

long long int find_set(long long int parent[],int p)
{
    if(p!=parent[p])
        parent[p] = find_set(parent,parent[p]);
    return parent[p];
}

unsigned long long int kruskal(int n)
{
    long long int i,pu,pv;
    unsigned long long int total=0;
    sort(graph.begin(),graph.end());
    for(i=0;i<(int)graph.size();i++)
    {
        pu = find_set(parent,graph[i].second.first);
        pv = find_set(parent,graph[i].second.second);
        if(pu!=pv)
        {
            total+=graph[i].first;
            parent[pu] = parent[pv];
        }
    }
    return total;
}

int main()
{
    int t;
    sd(t);
    while(t--)
    {
        graph.clear();
        int n;
        unsigned long long int ans=0,c;
        sd(n);
        string temp;
        reset();
        int i,m,u,v;
        for(u=1;u<=n;u++)
        {
            cin>>temp;
            sd(m);
            for(i=0;i<m;i++)
            {
                sd(v);
                cin>>c;
                graph.push_back(pair< long long int,pair< int,int > >(c,pair< int ,int >(u,v)));
            }
        }
        ans = kruskal(n);
        cout<<ans<<endl;
    }
    return 0;
}
