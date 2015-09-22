#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)


int main()
{
    int n;
    sd(n);
    int j,i,a[n][n],b[n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            sd(a[i][j]);
    if(n==2)
    {
        cout<<a[1][0]/2<<" "<<a[1][0]/2<<endl;
    }
    else
    {
        b[0]=(a[1][0]+a[2][0]-a[2][1])/2;
        for(i=1;i<n;i++)
            b[i] = a[i][0]-b[0];
        for(i=0;i<n;i++)
            cout<<b[i]<<" ";
    }
    return 0;
}
