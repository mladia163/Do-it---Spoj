#include <bits/stdc++.h>
using namespace std;

#define fast    ios::sync_with_stdio(0); cin.tie(0)
#define pii pair < int , int >
#define pb  push_back
#define mp  make_pair
#define ll  long long int
#define vi  vector < int >
#define vvi vector < vector < int > >
#define maxn    1000100
#define mod 1000000007
#define mem(a,b)    memset(a,b,sizeof(a))
#define FOR(i,a,b)  for(i=a;i<=b;i++)
#define rep(i,b)   for(i=0;i<b;i++)
#define ff  first
#define ss  second
#define all(v)  v.begin(),v.end()
#define inp  int t; cin>>t; while(t--)          // taking input test cases always :p

struct node
{
    int one,zero,two,lazy;
}tree[4*maxn];


void build(int node,int a,int b)
{
    if(a>b) return;

    if(a==b)
    {
        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=1;
        tree[node].lazy=0;
    }
    else
    {
        build(2*node,a,(a+b)/2);
        build(1+2*node,1+(a+b)/2,b);

        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=tree[2*node].zero+tree[1+2*node].zero;
        tree[node].lazy=0;
    }
}

void sweep(int node)
{
    if(tree[node].lazy%3==0)
        return;
    if(tree[node].lazy%3==1)
    {
        tree[2*node].lazy+=tree[node].lazy;
        tree[1+2*node].lazy+=tree[node].lazy;
        int tc=tree[node].one;
        tree[node].one=tree[node].two;
        tree[node].two=tree[node].zero;
        tree[node].zero=tc;
        tree[node].lazy=0;
    }
    else if(tree[node].lazy%3==2)
    {
        tree[2*node].lazy+=tree[node].lazy;
        tree[1+2*node].lazy+=tree[node].lazy;
        int tc=tree[node].two;
        tree[node].two=tree[node].one;
        tree[node].one=tree[node].zero;
        tree[node].zero=tc;
        tree[node].lazy=0;
    }
    else
        return ;
}

void update(int node,int a,int b,int l,int r,int val)
{
    sweep(node);

    if(a>b || a>r || b<l || l>r)   return;

    if(a>=l && b<=r)
    {
        tree[node].lazy=tree[node].lazy+1;
        sweep(node);
        return ;
    }

        update(2*node,a,(a+b)/2,l,r,val);
        update(1+2*node,1+(a+b)/2,b,l,r,val);

        tree[node].one=tree[2*node].one+tree[1+2*node].one;
        tree[node].two=tree[2*node].two+tree[1+2*node].two;
        tree[node].zero=tree[2*node].zero+tree[1+2*node].zero;
    return ;
}

ll query(int node,int a,int b,int l,int r)
{
    sweep(node);
    if(a>b || a>r || b<l)   return 0;

    if(a>=l && b<=r)
    {
        return tree[node].zero;
    }
    else
    {
        return query(2*node,a,(a+b)/2,l,r)+query(1+2*node,1+(a+b)/2,b,l,r);
    }
}


int main()
{
	//fast;
    int type,a,b,n,q,ans=0;
    cin>>n>>q;
    build(1,1,n);

   // rep(int i,n+1)
    //    cout<<tree[i].zero<<" ";
  //  cout<<"\n";
    while(q--)
    {
        cin>>type>>a>>b;
        a+=1;
        b+=1;
        if(type==0)
        {
            update(1,1,n,a,b,1);
        }
        else if(type==1)
        {
            ans=query(1,1,n,a,b);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
