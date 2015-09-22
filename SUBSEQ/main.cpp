#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll  long long int
#define maxn    1000100

//ll tree[4*maxn];
ll arr[maxn];
ll sum[maxn];

/*void build(int node,int a,int b)
{
    if(b>a) return;

    if(a==b)
    {
        tree[a]=arr[a];
        return;
    }

    build(2*node,a,(a+b)/2);
    build(1+2*node,1+(a+b)/2,b);
    tree[node]=tree[2*node]+tree[1+2*node];
}*/

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(sum,0,sizeof sum);
        map<ll,ll> str;
        int n,i,j,ans=0,k=0;
        sum[0]=0;
        str[0]++;           // if there is a number of 47 then it shd be included na
        cin>>n;

        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
            k=str[sum[i]-47];
            ans+=k;
            str[sum[i]]++;
        }

        cout<<ans<<"\n\n";
    }
    return 0;
}
