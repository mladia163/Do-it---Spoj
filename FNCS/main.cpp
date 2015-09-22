#include <iostream>

using namespace std;

typedef struct node
{
    long long int li;
    long long int ri;
    long long int f;
}node;


int main()
{
    long long int n,i,ans=0,j,temp=0;
    cin>>n;
    long long int a[n+1];
    for(i=1;i<=n;i++)
        cin>>a[i];
    node z[n+1];

    for(i=1;i<=n;i++)
    {
        z[i].f=0;
        cin>>z[i].li>>z[i].ri;
        for(j=z[i].li;j<=z[i].ri;j++)
            z[i].f += a[j];
    }

    //for(i=1;i<=n;i++)
      //  cout<<z[i].f<<endl;

    long long int t,q,x,y,m,n1;
    cin>>t;
    while(t--)
    {
        cin>>q;
        if(q==1)
        {
            cin>>x>>y;
            temp=a[x];
            a[x]=y;
            temp=y-temp;
            for(i=1;i<=n;i++)
            {
                if(x>=z[i].li && x<=z[i].ri)
                {
                    z[i].f+=temp;
                    //z[i].f=0;
                    //for(j=z[i].li;j<=z[i].ri;j++)
                     //   z[i].f += a[j];

                }
            }
        }
        if(q==2)
        {
            cin>>m>>n1;
            ans=0;
            for(i=m;i<=n1;i++)
                ans+=z[i].f;
            cout<<ans<<endl;
        }
    }


    return 0;
}
