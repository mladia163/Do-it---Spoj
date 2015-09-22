#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int func(char s[])
{
    int bal=0,max_bal=0,i,len=0;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='(')
            bal=bal+1;
        if(s[i]==')')
            bal=bal-1;
        max_bal = max(max_bal,bal);
    }
    return max_bal;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,temp=0;
        char s[100002];
        scanf("%s",s);
        temp=func(s);
        for(i=1;i<=temp;i++)
            cout<<"(";
        for(i=1;i<=temp;i++)
            cout<<")";
        cout<<endl;
    }
    return 0;
}
