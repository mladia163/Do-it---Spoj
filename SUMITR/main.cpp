#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,n;
        cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                cin>>a[i][j];
        for(i=n;i>=2;i--)
            for(j=1;j<i;j++)
                a[i-1][j] += max(a[i][j],a[i][j+1]);
        cout<<a[1][1]<<endl;
    }
    return 0;
}
