    #include <bits/stdc++.h>
    using namespace std;
    #define ll  long long int
    #define fast    ios::sync_with_stdio(0);  cin.tie(0)

    int n,arr[50010];

    struct segment
    {
        ll sum,best,lsum,rsum;
        segment(ll lsum_=0,ll rsum_=0,ll best_=0,ll sum_=0)
        {
            lsum=lsum_;
            rsum=rsum_;
            best=best_;
            sum=sum_;
        }
    }tree[200010];


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
        tree[node]=segment(max(tree[2*node].lsum,tree[2*node].sum+tree[1+2*node].lsum),
                           max(tree[1+2*node].rsum,tree[1+2*node].sum+tree[2*node].rsum),
                           max(max(tree[2*node].best,tree[1+2*node].best),tree[2*node].rsum+tree[1+2*node].lsum),
                           tree[2*node].sum+tree[1+2*node].sum);
    }

    void update(int node,int a,int b,int x)
    {
        if(a==b && a==x)
        {
            tree[node]=segment(arr[x],arr[x],arr[x],arr[x]);
            return;
        }
        if(x<=(a+b)/2)
        {
            update(2*node,a,(a+b)/2,x);
        }
        else
        {
            update(1+2*node,1+(a+b)/2,b,x);
        }
        segment left=tree[2*node];
        segment right=tree[1+2*node];
        tree[node]=segment(max(left.lsum,left.sum+right.lsum),
                     max(right.rsum,right.sum+left.rsum),
                     max(max(left.best,right.best),left.rsum+right.lsum),
                     left.sum+right.sum);
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
    	fast;
        int i,ans=0,m,choice,x,l,r,val;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        build(1,1,n);
        /*        for(i=1;i<=6;i++)
                    cout<<tree[i].lsum<<" "<<tree[i].rsum<<" "<<tree[i].sum<<" "<<tree[i].best<<" "<<"\n";
        cout<<"\n\n";
       */cin>>m;
        while(m--)
        {
            cin>>choice;
            if(choice==0)
            {
                cin>>x>>val;
                arr[x]=val;
                update(1,1,n,x);
            /*    cout<<"\n";
                for(i=1;i<=6;i++)
                    cout<<tree[i].lsum<<" "<<tree[i].rsum<<" "<<tree[i].sum<<" "<<tree[i].best<<" "<<"\n";
                cout<<"\n";
            */}
            else
            {
                cin>>l>>r;
                segment yup=query(1,1,n,l,r);
                cout<<yup.best<<"\n";
            }
        }



        return 0;
    }
