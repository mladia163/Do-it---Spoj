#include <bits/stdc++.h>
using namespace std;

long long int arr[1005],a[1005][1005];
int main()
{
    long long int n,t=1;
    scanf("%lld",&n);
    while(n!=0)
    {
        bool ans=true;
        long long int i,sum=0,l=1,r=3,t1=0,t2=0,temp=3;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            a[i][i] = arr[i];
            sum+=arr[i];
            if(i!=1)
                a[i-1][i] = max(arr[i-1],arr[i]);
        }
        while(ans)
        {
            t1=arr[l],t2=arr[r];
            if(arr[l+1]>=arr[r])    t1+=a[l+2][r];
            else                    t1+=a[l+1][r-1];
            if(arr[r-1]>arr[l])     t2+=a[l][r-2];
            else                    t2+=a[l+1][r-1];
            a[l++][r++]=max(t1,t2);
            if(r>n)     ++temp,l=1,r=temp;
            if(temp>n)  break;
        }
        cout<<"In game "<<t++<<", the greedy strategy might lose by as many as "<<(2*a[1][n])-sum<<" points.\n";
        scanf("%lld",&n);
    }
    return 0;
}
