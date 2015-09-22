#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
int treats[2001];
int pay[2001][2001];

int main()
{
    int i,j,n,age=0;
    sd(n);
    for(i=0;i<n;i++)
        sd(treats[i]);

    for(i=0;i<n;i++)
        pay[i][i] = n*treats[i];

    for(i=n-2;i>=0;i--)
        for(j=i+1;j<n;j++)
        {
            age = n-j+i;
            pay[i][j] = max( pay[i+1][j] + age*treats[i] , pay[i][j-1] + age*treats[j] );
        }

    cout<<pay[0][n-1]<<endl;
    return 0;
}
