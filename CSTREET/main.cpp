#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
#define sd(a)   scanf("%d",&a)
int parent[1001],n,m,p;

vector< pair< int , pair< int , int > > > graph;    // (c,a,b) format

void reset()
{
    for(int i=1;i<=1001;i++)
        parent[i] = i;
}

int find_set(int parent[],int p)
{
    if(p!=parent[p])
        parent[p] = find_set(parent,parent[p]);
    return parent[p];
}

int kruskal()
{
    int i,pa,pb,temp=0;
    sort(graph.begin(),graph.end());
    for(i=0;i<m;i++)
    {
        pa = find_set(parent,graph[i].second.first);
        pb = find_set(parent,graph[i].second.second);
        if(pa!=pb)
        {
            temp+=graph[i].first;
            parent[pa]=parent[pb];      //union yhin pr ho ja rha hai :p
        }
    }
    return temp;
}

int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int i,a,b,c,ans=0;
        sd(p);
        sd(n);
        sd(m);
        reset();
        for(i=0;i<m;i++)
        {
            sd(a);
            sd(b);
            sd(c);
            graph.push_back(pair< int , pair< int ,int > > (c,pair< int ,int >(a,b)));
        }
        ans = kruskal();
        cout<<ans*p<<endl;
    }
    return 0;
}
