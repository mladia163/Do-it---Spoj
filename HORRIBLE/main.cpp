#include <bits/stdc++.h>
using namespace std;
#define ll  long long int

ll n;
ll arr[100010];
ll tree[400010];//400000
ll lazy[400010];

// not in use this time as initially all set to 0 itself  :p
void build_tree(ll node,ll a,ll b)
{
    if(a>b)
        return;

    if(a==b)
    {
        tree[node] = arr[a];
        return;
    }

    build_tree(node*2,a,(a+b)/2);
    build_tree(node*2+1,((a+b)/2)+1,b);

    tree[node] = tree[node*2]+tree[node*2+1];
}


void update_tree(ll node,ll a,ll b,ll p,ll q,ll val)
{
    if(a>b) return;
    if(lazy[node]!=0)
    {
        tree[node]+=(lazy[node]*(b-a+1));

        if(a!=b)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(a>b || a>q || b<p)
        return;

    if(a>=p && b<=q)
    {
        tree[node]+=val*(b-a+1);

        if(a!=b)
        {
            lazy[node*2]+=val;
            lazy[(2*node)+1]+=val;
        }
        return;
    }

    update_tree(node*2,a,(a+b)/2,p,q,val);
    update_tree(node*2+1,(a+b)/2+1,b,p,q,val);

    tree[node] = tree[node*2]+tree[(node*2)+1];
}


ll query(ll node,ll a,ll b,ll p,ll q)
{
    if(a>b || a>q || b<p)
        return 0;

    if(lazy[node]!=0)
    {
        tree[node]+=(lazy[node]*(b-a+1));

        if(a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }


    if(a>=p && b<=q)
        return tree[node];

    ll q1 = query(node*2,a,(a+b)/2,p,q);
    ll q2 = query((node*2)+1,((a+b)/2)+1,b,p,q);
    ll ans = q1+q2;
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll c,val,p,q,choice,answer=0,i;
        scanf("%lld %lld",&n,&c);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));

        for(i=0;i<c;i++)
        {
            scanf("%lld",&choice);
            if(choice==0)
            {
                scanf("%lld %lld %lld",&p,&q,&val);
               // p-=1,q-=1;
                update_tree(1,1,n,p,q,val);
            }
            else //if(choice==1)
            {
                scanf("%lld %lld",&p,&q);
                //p-=1,q-=1;
                answer=query(1,1,n,p,q);
                printf("%lld\n",answer);
                //cout<<answer<<endl;

              //  for(i=8;i<=15;i++)
                //    cout<<tree[i]<<" ";
                //cout<<endl;
            }
        }
    }
    return 0;
}
