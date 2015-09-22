#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
int arr[50010],n;

struct segment
{
    ll lsum,rsum,best,sum;
    segment(ll lsum_=0,ll rsum_=0,ll best_=0,ll sum_=0)
    {
        lsum=lsum_;
        rsum=rsum_;
        best=best_;
        sum=sum_;
    }
}tree[200100];

void build(int node,int a,int b)
{
    if(a>b) return;

    if(a==b)
    {
        tree[node]=segment(arr[a],arr[a],arr[a],arr[a]);
        return;
    }
    build(2*node,a,(a+b)/2);
    build(1+2*node,1+(a+b)/2,b);
    tree[node]=segment(max(tree[2*node].lsum,tree[1+2*node].lsum+tree[2*node].sum),
                       max(tree[1+2*node].rsum,tree[1+2*node].sum+tree[2*node].rsum),
                       max(max(tree[2*node].best,tree[1+2*node].best),tree[2*node].rsum+tree[1+2*node].lsum),
                       tree[2*node].sum+tree[1+2*node].sum);
}

segment query(int node,int a,int b,int p,int q) // 1,1,3,p=2,q=3
{
    if(p <= a && q >= b)
        return tree[node];

    if(q<=(a+b)/2)
        return query(2*node,a,(a+b)/2,p,q);
    if(p>(a+b)/2)
        return query(1+2*node,1+(a+b)/2,b,p,q);

    segment left = query(2*node,a,(a+b)/2,p,q);
    segment right = query(1+2*node,1+(a+b)/2,b,p,q);

    segment temp;
    temp = segment(max(left.lsum,right.lsum+left.sum),
                   max(right.rsum,right.sum+left.rsum),                        // max - best ....
                   max(max(left.best,right.best),left.rsum+right.lsum),
                   left.sum+right.sum);
    return temp;
}
int main()
{
    int i,m;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);

    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        segment ans=query(1,1,n,l,r);
        cout<<ans.best<<"\n";
    }
    return 0;
}
