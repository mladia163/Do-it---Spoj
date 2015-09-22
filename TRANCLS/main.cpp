#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t,k1=1;
    cin>>t;
    while(t--)
    {
        int a,b,i,j,k,n,ans=0,z;
        int graph[101][101];

        for(i=0;i<101;i++)
            for(j=0;j<101;j++)
                graph[i][j]=0;

        cin>>n;
        for(z=0;z<n;z++)
        {
            cin>>a>>b;
            graph[a][b]=1;
        }
        /*cout<<endl;
        cout<<"case:0"<<endl;
        for(int i1=0;i1<n;i1++)
        {
            for(int j1=0;j1<n;j1++)
                if(graph[i1][j1]==1e5)
                    cout<<"0"<<" ";
                else
                    cout<<graph[i1][j1]<<" ";
                cout<<"\n";
        }*/

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    graph[j][k] = graph[j][k] || (graph[j][i] && graph[i][k]);
                }
            }
           /*  cout<<endl;
            cout<<"case:"<<i+1<<endl;
            for(int i1=0;i1<n;i1++)
            {
                for(int j1=0;j1<n;j1++)
                    if(graph[i1][j1]==1e5)
                        cout<<"0"<<" ";
                    else
                        cout<<graph[i1][j1]<<" ";
                cout<<"\n";
            }*/
        }


        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(graph[i][j]==1)
                    ans++;

        ans-=n;
        cout<<"Case #"<<k1<<": "<<ans<<endl;
        k1++;

    }
    return 0;
}
