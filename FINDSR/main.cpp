#include <bits/stdc++.h>
using namespace std;
#define ll  long long int

void LPS(string pat,int lps[])
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
    int M=pat.length();
    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int main()
{
    string str;
    cin>>str;
    while(str[0]!='*')
    {
        int tc=str.length();
        int len=0,lps[tc+1];
        ll ans=0;
        LPS(str,lps);
        len=str.length()-lps[str.length()-1]-1;

        if(str.length()%len==0)
            ans=1;
        else
        {

        }

        /*
        if(str.length()==1)
            ans=1;
        else if(len==1 && str[str.length()-1]==str[0])
            ans=str.length();
        else if(len!=1 && str.length()%len==0)
            ans=str.length()/len;
        else
            ans=1;
        */
        cout<<ans<<endl;
        cin>>str;
    }
    return 0;
}
