#include <bits/stdc++.h>
using namespace std;

char str[6];
int main()
{
    int i,k,t;
    scanf("%d",&t);
    str[0]='m';
    str[1]='a';
    str[2]='n';
    str[3]='k';
    str[4]='u';
    while(t--)
    {
        k=0;
        long long int n,temp=0;
        cin>>n;
        char str1[100];
        //if(n%5!=0)
        //{
            while(n!=0)
            {
                str1[k++]=str[(n-1)%5];
                n=(n-1)/5;
            }
            str1[k]='\0';
            for(i=k-1;i>=0;i--)
                cout<<str1[i];
            cout<<endl;
        /*}
        else
        {
            str1[k++]=str[5];
            n-=5;
            n/=5;
            while(n!=0)
            {
                temp=n%5;
                str1[k++]=str[temp];
                n=(n-temp)/5;
            }
            str1[k]='\0';
            for(i=k-1;i>=0;i--)
                cout<<str1[i];
            cout<<endl;
        }*/
    }

    return 0;
}
