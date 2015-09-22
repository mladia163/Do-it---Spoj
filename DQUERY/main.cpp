#include <bits/stdc++.h>
using namespace std;
/// Implementation of MO ( Query square root decomposition ) yo!!!!
///Use fast io to AC
#define sd(a)   scanf("%d",&a)
#define blk     174
#define N       30010
int count_[1000001],arr[N],ans[200001],answer=0;

struct node
{
    int l;
    int r;
    int pos;
}dquery[200001];

bool cmpf( node a,node b )
{
    if((a.l/blk)!=(b.l/blk))
        return (a.l/blk)<(b.l/blk);
    return a.r<b.r;
}

void add(int pos)
{
    count_[arr[pos]]++;
    if(count_[arr[pos]]==1)
        answer++;
}

void remove_(int pos)
{
    count_[arr[pos]]--;
    if(count_[arr[pos]]==0)
        answer--;
}

int main()
{
    int i,n,q,currentl=0,currentr=0;

    sd(n);
    for(i=0;i<n;i++)
        sd(arr[i]);
    sd(q);
    for(i=0;i<q;i++)
    {
        sd(dquery[i].l);
        sd(dquery[i].r);
        dquery[i].l--;
        dquery[i].r--;
        dquery[i].pos = i;
    }
    sort(dquery,dquery+q,cmpf);

    for(i=0;i<q;i++)
    {
        //answer=0;
        while(currentl<dquery[i].l)
        {
            remove_(currentl);
            currentl++;
        }
        while(currentl>dquery[i].l)
        {
            add(currentl-1);
            currentl--;
        }
        while(currentr<=dquery[i].r)
        {
            add(currentr);
            currentr++;
        }
        while(currentr>(dquery[i].r+1))
        {
            remove_(currentr-1);
            currentr--;
        }
        ans[dquery[i].pos]=answer;
    }

    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);

    return 0;
}
