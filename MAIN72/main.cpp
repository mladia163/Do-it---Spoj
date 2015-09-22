#include <iostream>
bool sumset[500000][101];

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=0,i,j,hi=0,a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            hi+=a[i];
        }
        //bool sumset[hi+1][n+1];
        for(i=0;i<=n;i++)
            sumset[0][i] = true;
        for(i=1;i<=hi;i++)
            sumset[i][0] = false;
        for(i=1;i<=hi;i++)
        {
            for(j=1;j<=n;j++)
            {
                sumset[i][j] = sumset[i][j-1];
                if(i>=a[j-1])
                    sumset[i][j] = sumset[i][j] || sumset[i-a[j-1]][j-1];
            }
        }
        for(i=0;i<=hi;i++)
            if(sumset[i][n])
                res+=i;
        cout<<res<<endl;
    }
    return 0;
}
