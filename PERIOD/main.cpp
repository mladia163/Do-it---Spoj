#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
/*
void LPS(string p,int lps[])
{
    int j=2,curr=0;
    lps[0]=lps[1]=0;
    for(j=2;j<p.length();j++)
    {
        while(curr!=0 && p[curr]!=p[j-1])
            curr=lps[curr];
        if(p[curr]==p[j-1])
            curr+=1;
        lps[j]=curr;
    }
}
*/
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
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int len_str,i;
        cin>>len_str;
        string str;
        cin>>str;
        int lps[len_str+1];
        LPS(str,lps);
        cout<<"Test case #"<<z++<<endl;
        for(i=1;i<len_str;i++)
        {
           // cout<<i<<" "<<lps[i]<<endl;
            if(lps[i]>0)
            {
                int temp=i+1-lps[i];
                if((i+1)%temp==0)
                    cout<<i+1<<" "<<(i+1)/temp<<endl;
            }
        }
    }
    return 0;
}
