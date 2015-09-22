#include <bits/stdc++.h>
using namespace std;

int dp[6111][6111];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        int i,j,ans=0;
        cin>>str1;

        for(i=str1.length()-1;i>=0;i--)
            str2+=str1[i];
      //  cout<<str2<<"\n";

        for(i=0;i<str1.length();i++)    dp[0][i]=dp[i][0]=0;

        for(i=1;i<=str1.length();i++)
        {
            for(j=1;j<=str2.length();j++)
            {
                if(str1[i-1]==str2[j-1])    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<str1.length()-dp[str1.length()][str1.length()]<<"\n";
    }
    return 0;
}
