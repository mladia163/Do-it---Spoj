#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define maxn    100100

ll arr[maxn];

struct segment
{
    ll size_subtree,sum;
    segment(ll size_subtree_=0,ll sum_=0)
    {
        size_subtree=size_subtree_;
        sum=sum_;
    }
}tree[4*maxn];


void build(int node,int a,int b)
{
    if(a>b) return;
    if(a==b)
    {
        tree[node]=segment(1,arr[a]);
        return;
    }
    build(2*node,a,(a+b)/2);
    build(1+2*node,1+(a+b)/2,b);
    tree[node]=segment(tree[2*node].size_subtree+tree[1+2*node].size_subtree,tree[2*node].sum+tree[1+2*node].sum);
}

void update(int node,int a,int b,int i,int j)
{
    if(a>b || a>j || b<i)   return;
    if(tree[node].size_subtree==tree[node].sum) return;         // cecking out for 1 if its one down this tree just break it out
    if(a==b)
    {
        tree[node].sum=sqrt(tree[node].sum);
        return;
    }
    if(j<=(a+b)/2)
        update(2*node,a,(a+b)/2,i,j);
    else if(i>(a+b)/2)
        update(1+2*node,1+(a+b)/2,b,i,j);
    else
    {
        update(2*node,a,(a+b)/2,i,j);
        update(1+2*node,1+(a+b)/2,b,i,j);
    }
    tree[node]=segment(tree[node].size_subtree,tree[2*node].sum+tree[1+2*node].sum);
}

segment query(int node,int a,int b,int l,int r)
{
   // if(a>b || a>r || b<l)   return 0;

    if(l<=a && r>=b)
        return tree[node];

    if(r<=(a+b)/2)
        return query(2*node,a,(a+b)/2,l,r);
    else if(l>(a+b)/2)
        return query(1+2*node,1+(a+b)/2,b,l,r);
    else
    {
        segment q1 = query(2*node,a,(a+b)/2,l,r);
        segment q2 = query(1+2*node,1+(a+b)/2,b,l,r);
        segment Q;
        Q = segment(q1.size_subtree+q2.size_subtree,q1.sum+q2.sum);
        return Q;
    }
}


int main()
{

    int n,k=1;
    while(scanf("%d",&n)!=EOF)
    {
        int i,l,r,ch,m;

        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);

        build(1,1,n);
        scanf("%d",&m);
        printf("Case #%d:\n",k);
        while(m--)
        {
            scanf("%d %d %d",&ch,&l,&r);


            if(l>r) swap(l,r);
            if(ch==0)       // modify on l to r take sqrt of all
            {
                update(1,1,n,l,r);
        //        for(i=1;i<=10;i++)
          //          cout<<tree[i]<<" ";
            //    cout<<"\n";
            }
            else                // print the sum of range l to r
            {
                segment ans=query(1,1,n,l,r);
                printf("%lld\n",ans.sum);
            }
        }
        printf("\n");
        k++;
    }
    return 0;
}
