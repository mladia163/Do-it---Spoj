#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int num[1000001];
char s[1000001];
bool all9s(int num[],int n)
{
    int i;
    bool temp=true;
    for(i=0;i<n;i++)
        if(num[i]!=9)
        {
            temp=false;
            break;
        }
    return temp;
}



void next_palin(int num[],int n)
{
    int mid=n/2,i,j,carry=1;
    bool left_smaller=false;
    i=mid-1;
    j=(n%2==0)?mid:mid+1;

    while(i>=0 && num[i]==num[j])   // ignore all the equal ones
    {
        i--;
        j++;
    }

    if(i<0 || num[i]<num[j])
        left_smaller=true;

    while(i>=0)
        num[j++]=num[i--];

    if(left_smaller==true)
    {
        carry=1;
        i=mid-1;
        if(n%2==1)      // mid walla if odd ko carry add krdiya
        {
            num[mid]+=carry;
            carry=num[mid]/10;
            num[mid]=num[mid]%10;
            j=mid+1;
        }
        else
            j=mid;

        while(i>=0)
        {
            num[i]+=carry;
            carry=num[i]/10;
            num[i]=num[i]%10;
            num[j++]=num[i--];
        }
    }
    for(i=0;i<n;i++)
        cout<<num[i];
    cout<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //string s;
        scanf("%s",s);
        int i,len=0;
        //len=s.length();
        len=strlen(s);
        for(i=0;i<len;i++)
            num[i]=s[i]-'0';
        if(all9s(num,len))
        {
            cout<<"1";
            for(i=1;i<len;i++)
                cout<<"0";
            cout<<"1";
            cout<<endl;
        }
        else
            next_palin(num,len);
    }
    return 0;
}
