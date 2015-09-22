#include <bits/stdc++.h>
using namespace std;

int dp[111111];
int main()
{
    string str,br;
    br.clear();
    bool pk=true;
    br+='0';
    cin>>str;
    while(str!=br)
    {
        memset(dp,0,sizeof dp);
        int i,ans=0,temp;
        dp[0]=1;

        for(i=1;i<str.length();i++)
        {
            temp=((str[i-1]-'0')*10+(str[i]-'0'));
            if(temp==0)
            {
                pk=false;
                break;
            }
            if((str[i]-'0')>0)  dp[i]=dp[i-1];
            if(temp>9 && temp<=26)  dp[i]=dp[i]+dp[i-2<0?0:i-2];
        }
        cout<<dp[str.length()-1]<<"\n";
        cin>>str;
    }
    return 0;
}
