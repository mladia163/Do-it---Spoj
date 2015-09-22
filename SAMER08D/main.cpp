#include <bits/stdc++.h>
using namespace std;

int segment[1010][1010],dp[1010][1010];

int main()
{
    int k;
    cin>>k;
    while(k!=0)
    {
        string a,b;
        cin>>a>>b;
        int lena=a.length(),lenb=b.length(),i,j,ans=0;
        for(i=0;i<=lena;i++)
            dp[i][0]=0,segment[i][0]=0;
        for(i=0;i<=lenb;i++)
            dp[0][i]=0,segment[0][i]=0;

        for(i=1;i<=lena;i++)
        {
            for(j=1;j<=lenb;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1]==b[j-1])
                {
                    segment[i][j]=segment[i-1][j-1]+1;
                }
                else
                    segment[i][j]=0;

                if(segment[i][j]>=k)    // jab bhi segment bdda ho jaye k se tbhi pdate krdo lcs ko
                {
                    for(int p=k;p<=segment[i][j];p++)
                        dp[i][j]=max(dp[i][j],dp[i-p][j-p]+p);
                }
            }
        }

        cout<<dp[lena][lenb]<<"\n";

        cin>>k;
    }


    return 0;
}
