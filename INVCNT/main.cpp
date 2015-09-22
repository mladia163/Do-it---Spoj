#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define sd(a)   scanf("%d",&a)
ll arr[200001],temp[200001],n;
int merge_(int left,int mid,int right);
int mergesort(int left,int right)
{
    int mid=0,inv_cnt=0;
    while(left<right)
    {
        mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge_(left,mid+1,right);
    }
    return inv_cnt;
}

int merge_(int left,int mid,int right)
{
    int i=left,j=mid,k=left,inv_cnt=0;
    while((i<=(mid-1)) && (j<=right))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inv_cnt=inv_cnt+(mid-i);
        }
    }
    while(i<=(mid-1))
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(i=left;i<=right;i++)
        arr[i]=temp[i];
    return inv_cnt;
}


int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int i;
        sd(n);
        for(i=0;i<n;i++)
            sd(arr[i]);
        cout<<mergesort(0,n-1)<<endl<<endl;
    }
    return 0;
}
