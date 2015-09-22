#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define pb  push_back
#define mp  make_pair
#define maxn    1010
#define lgmaxn  16
vector<int> graph[maxn];
vector<int> ans;
// T[i] -> parent of ith node
// P[i] -> just above section ki last row wala & for 1st section its 1
// L[i] -> level of node i
// nr   -> something like number of sections (sqrt(N))
// via dfs we make our array P[] then apply LCA of P[]
/*void dfs(int node,int T[],int N,int P[],int L[],int nr)
{
    // if node at 1st section P[node]=1
    // if at beginning of some section then P[node]=T[node]
    // none of above 2 cases then P[node]=P[T[node]]

    if(L[node]<nr)
    {
        P[node]=1;
    }
    else
    {
        if(!(L[node]%nr))      // check beginning of any of the section or not
        {
            P[node]=T[node];
        }
        else
        {
            P[node]=P[T[node]];
        }
    }
    int pik=graph[node].size();
    for(int k=0;k<pik;k++)
    {
        if(!visited[graph[node][k]])
        {
            visited[graph[node][k]]=1;
            dfs(graph[node][k],T,N,P,L,nr);
        }
    }

}

int LCA(int T[],int P[],int L[],int x,int y)
{
    // as long as the node in the next section of
    // x and y is not one common ancestor
    // we get the node situated on the smaller
    // lever closer

    while(P[x]!=P[y])
    {
        if(L[x]>L[y])
            x=P[x];
        else
            y=P[y];
    }

    // now they are in the same section, so we trivially compute the LCA

    while(x!=y)
    {
        if(L[x]>L[y])
            x=T[x];
        else
            y=T[y];
    }
    return x;
}
*/
void dfs(int T[],int N,int P[][lgmaxn])
{
    int i,j;
    // initialise by -1 all
    for(i=0;i<=N;i++)
        for(j=0;j<=N;j++)
            P[i][j]=-1;
    // all the 2^0 i.e first ancestor will be itself
    for(i=1;i<=N;i++)
        P[i][0]=T[i];

    // bottom up dp
    for(j=1;1<<j<N;j++)
    {
        for(i=0;i<N;i++)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }

    /*for(j=0;1<<j<=N;j++)
    {
        cout<<j<<" : ";
        for(i=1;i<=N;i++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}

int LCA(int T[],int P[][lgmaxn],int L[],int p,int q)
{
    int log,i;

    // without any loss in generality we always take p at higher level
    // if its not so just swap them
    if(L[p]<L[q])
        swap(p,q);

    // finding [log[L[p]]] ie ceil of it

    //for(log=1;(1<<log)<=L[p];log++)
     //   log--;

    // now ie if not in same level then we have to find ancestor of p
    // at the same level as that of q from P[][lgmaxn]
    for(i=16;i>=0;i--)
    {
        if(L[p]-(1<<i) >= L[q])
            p=P[p][i];
    }

    // we have find ancestor
    if(p==q)
        return q;


        for(i=16;i>=0;i--)
        {
            if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            {
                p=P[p][i];
                q=P[q][i];
            }
        }
        return T[p];
}


void bfs(int node,int T[],int L[])
{
    int visited[maxn]={0};
    int i,temp;
    memset(visited,0,sizeof visited);
    queue<int> Q;
    temp=node;
    Q.push(node);
    visited[node]=true;
    T[node]=node;
    L[node]=0;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        int pik=graph[temp].size();
        for(i=0;i<pik;i++)
        {
            if(!visited[graph[temp][i]])
            {
                L[graph[temp][i]]=L[temp]+1;
                Q.push(graph[temp][i]);
                T[graph[temp][i]]=temp;
                visited[graph[temp][i]]=1;
            }
        }
    }
}

int main()
{
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int visited[maxn]={0},P[maxn][lgmaxn],T[maxn],L[maxn];
        int i,u,v,edges,x,y,q,nr,N;
        cin>>N;
        for(i=0;i<=N;i++)
        {
            graph[i].clear();
            visited[i]=0;
            T[i]=0;
            L[i]=0;
        }
        //memset(visited,0,sizeof visited);
        //memset(T,0,sizeof T);
        //memset(P,0,sizeof P);
        //memset(L,0,sizeof L);
        ans.clear();

        for(u=1;u<=N;u++)
        {
            cin>>edges;
            for(int j=0;j<edges;j++)
            {
                cin>>v;
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
        bfs(1,T,L);

       /* int np=-1;
        for(i=1;i<=N;i++)
        {
            np=max(nr,L[i]);
            visited[i]=0;
        }
        //nr=(int)sqrt(nr);
        nr=sqrt(np);
        //memset(visited,0,sizeof visited);
        visited[1]=1;
        */
        dfs(T,N,P);

        cin>>q;
        while(q--)
        {
            cin>>x>>y;
            ans.pb(LCA(T,P,L,x,y));
        }
        int pik=ans.size();
        cout<<"Case "<<z<<":\n";
        for(i=0;i<pik;i++)
            cout<<ans[i]<<"\n";
        z++;
    }
    return 0;
}
