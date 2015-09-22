#include <bits/stdc++.h>
using namespace std;
#define pb  push_back

int n;
vector<int> a;

int ncoin(int sum)
{
    int i,j,kp[sum+1][n];
    for(i=0;i<n;i++)
        kp[0][i]=1;

    for(i=1;i<=sum;i++)
    {
        for(j=0;j<n;j++)
        {
            int inc = ((i-a[j])>=0)?kp[i-a[j]][j]:0;
            int exc = (j>=1)?kp[i][j-1]:0;
            kp[i][j]=inc+exc;
        }
    }


    cout<<endl;
    for(i=0;i<=sum;i++)
    {
        for(j=0;j<n;j++)
            cout<<kp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return kp[sum][n-1];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int i,temp,sum=0;
    cin>>n>>sum;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        a.pb(temp);
    }
    int ans=ncoin(sum);

    cout<<ans<<endl;
    return 0;
}
