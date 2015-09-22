#include <bits/stdc++.h>
using namespace std;
#define YES cout<<"Yes";
#define NO  cout<<"No";
char str[50001];
int arr[] = {1,3,2,-1,-3,-2};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int temp1=0,len=0,i;
        scanf("%s",str);
        len=strlen(str);
        bool chq7=false,chq25=false,chq4=false,chq9=false,chq3=false;

        temp1=((str[len-2]-'0')*10+(str[len-1]-'0'));
        if(temp1%4==0)
            chq4 = true;
        if(temp1%25==0)
            chq25 = true;

        temp1=0;
        for(i=0;i<len;i++)
            temp1+=(str[i]-'0');
        if(temp1%3==0)
            chq3 = true;
        if(temp1%9==0)
            chq9 = true;

        long long int tees=0;
        int j=0;
        for(i=len-1;i>=0;i--)
        {
            tees = tees + (str[i]-'0')*arr[j];
            j=(j+1)%6;
        }
        if(tees%7==0)
            chq7 = true;

        if(chq4 && chq9 && chq7)
            YES
        else
            NO
        cout<<" ";
        if(chq3 && chq25 && chq7)
            YES
        else
            NO
        cout<<endl;
    }
    return 0;
}
