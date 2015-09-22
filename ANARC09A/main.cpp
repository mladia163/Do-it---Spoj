#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main()
{
    stack<char> s;
    string str;
    cin>>str;
    int k=1;
    while(str[0]!='-')
    {
        int i,ans=0;
        char temp;
        for(i=0;i<str.length();i++)
            if(s.empty())   s.push(str[i]);
            else
                if(str[i]=='}')
                    if(s.top()=='{')    s.pop();
                    else    s.push(str[i]);
                else    s.push(str[i]);
        if(s.empty())   cout<<k++<<". 0"<<endl;
        else
        {
            while(!s.empty())
            {
                temp=s.top();
                s.pop();
                if(temp==s.top())   ans+=1;
                else    ans+=2;
                s.pop();
            }
            cout<<k++<<". "<<ans<<endl;
        }
        str.clear();
        cin>>str;
    }
    return 0;
}
