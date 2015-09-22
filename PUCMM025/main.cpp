#include <bits/stdc++.h>
using namespace std;


char ch[300];
int arr[] = {1,3,2,-1,-3,-2};
bool chq_divisibility(int a,int len)
{
    int i,temp1=0,temp2=0,temp=0;

    if(a==1)
        return true;
    else if(a==2)
    {
        temp=(ch[len-1]-'0');
        if(temp%2==0)
            return true;
        else
            return false;
    }
    else if(a==3)
    {
        temp1=0;
        for(i=0;i<len;i++)
            temp1+=(ch[i]-'0');
        if(temp1%3==0)
            return true;
        else
            return false;
    }
    else if(a==4)
    {
        temp1=((ch[len-2]-'0')*10+(ch[len-1]-'0'));
        if(temp1%4==0)
            return true;
        else
            return false;
    }
    else if(a==5)
    {
        temp1=(ch[len-1]-'0');
        if(temp1%5==0)
            return true;
        else
            return false;
    }
    else if(a==6)
    {
        temp1=temp=temp2=0;
        temp=(ch[len-1]-'0');
        for(i=0;i<len;i++)
            temp1+=(ch[i]-'0');
        if(temp1%3==0 && temp%2==0)
            return true;
        else
            return false;
    }
    else if(a==7)
    {
        long long int tees=0;
        int j=0;
        for(i=len-1;i>=0;i--)
        {
            tees = tees + (ch[i]-'0')*arr[j];
            j=(j+1)%6;
        }
        if(tees%7==0)
            return true;
        else
            return false;
    }
    else if(a==8)
    {
        temp=(ch[len-3]-'0')*100+(ch[len-2]-'0')*10+(ch[len-1]-'0');
        if(temp%8==0)
            return true;
        else
            return false;
    }
    else if(a==9)
    {
        temp1=0;
        for(i=0;i<len;i++)
            temp1+=(ch[i]-'0');
        if(temp1%9==0)
            return true;
        else
            return false;
    }
}

int main()
{
    int i,answer=0,tt,len;
    while(scanf("%s",ch)!=EOF)
    {
        answer=0;
        len = strlen(ch);
        for(i=0;i<len;i++)
        {
            tt=(ch[i]-'0');
            if(tt==0)
                continue;
            if(chq_divisibility(tt,len))
                answer+=1;
        }
        cout<<answer<<endl;
    }
    return 0;
}
