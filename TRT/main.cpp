#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)

int treats[2001];
int temp[2001][2001];

int main()
{
    int ans=0,n,i,j;
    sd(n);
    int age=1;
    for(i=0;i<n;i++)
        sd(treats[i]),temp[i][i]=n*treats[i];

    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            age = n-j+i;
            temp[i][j] = max(temp[i+1][j]+age*treats[i],temp[i][j-1]+age*treats[j]);
        }
    }
    ans = temp[0][n-1];
    cout<<ans<<endl;
    return 0;
}
