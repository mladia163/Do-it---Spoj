#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

char seq[40000];
typedef struct Node
{
    int sum;
    int minsum;
}node;

node tree[70000];

void initialise(int node,int i,int j)
{
    int mid;
    if(i==j)
    {
        tree[node].sum = tree[node].minsum = (seq[i]=='(' ? 1 : -1 );
        return;
    }
    mid = (i+j)/2;
    initialise(node*2,i,mid);
    initialise(2*node+1,mid+1,j);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    tree[node].minsum = min(tree[2*node].minsum,tree[2*node].sum+tree[2*node+1].minsum);
}

void update(int node,int i,int j,int index)
{
    if(i==j)
    {
        tree[node].sum = tree[node].minsum = -tree[node].sum;
        return;
    }
    int mid = (i+j)/2;
    if(index<=mid)
        update(2*node,i,mid,index);
    else
        update(2*node+1,mid+1,j,index);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    tree[node].minsum = min(tree[2*node].minsum,tree[2*node+1].minsum+tree[2*node].sum);
}

int main()
{
    int q,len,test=1,temp,i;
    while(scanint(len)==1)
    {
        scanf("%s",seq);
        initialise(1,0,len-1);
        printf("Test %d:\n", test++);
		scanint(q);
        for(i=0;i<q;i++)
        {
            scanint(temp);
            if(temp==0)
            {
                if(!tree[1].sum && !tree[1].minsum)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                update(1,0,len-1,temp-1);
        }
    }
    return 0;
}
