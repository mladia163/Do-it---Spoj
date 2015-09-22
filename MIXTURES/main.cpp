#include <bits/stdc++.h>
using namespace std;
#define mod 100
#define ll  long long int

int p[200];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>p[i];
        int ans[n+1][n+1],sum[n+1][n+1];


        for(i=0;i<n;i++)
            sum[i][i]=a[i];

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                sum[i][j]=sum[i][j-1]+a[j];
                if(sum[i][j]>=100)
                    sum[i][j]=sum[i][j]%100;
            }
        }


        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {

            }
        }

    }
    return 0;
}
