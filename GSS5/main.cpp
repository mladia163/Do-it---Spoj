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
    if(p>q) return 0;
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
// http://ideone.com/gjKnav
int main()
{
    int yup;
    cin>>yup;
    while(yup--){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
    int i,m;
    int x1,x2,y1,y2;
	ll ans=0;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);

   // for(i=1;i<=5;i++)
     //   cout<<tree[i].best<<" "<<tree[i].lsum<<" "<<tree[i].rsum<<" "<< tree[i].sum<<"\n";
       // cout<<"\n";


    cin>>m;
    while(m--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x2>y1)
        {
            segment t1=query(1,1,n,y1+1,x2-1);
            segment t2=query(1,1,n,x1,y1);
            segment t3=query(1,1,n,x2,y2);
            ans=t1.sum+t2.rsum+t3.lsum;
        }
        else
        {
            segment t1=query(1,1,n,x1,y1);
            segment t2=query(1,1,n,y1+1,y2);
            segment t3=query(1,1,n,x1,x2-1);
            segment t4=query(1,1,n,x2,y2);
            segment t5=query(1,1,n,x2,y1);
            ll a1=t1.rsum+t2.lsum;
            ans=a1;
            ll a2=t3.rsum+t4.lsum;
            ans=max(a2,ans);
            ll a3=t5.best;
            ans=max(ans,a3);
        }
        cout<<ans<<"\n";
    }
    }
    return 0;
}
