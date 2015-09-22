#include <bits/stdc++.h>
using namespace std;

char str[1000001];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int k=0,i=0,n;
        cin>>n;
        while(n!=0)
        {
            if((n-1)%2==1)
                str[k++]='6';
            else
                str[k++]='5';
            n=(n-1)/2;
        }
        str[k]='\0';
        for(i=k-1;i>=0;i--)
            cout<<str[i];
        cout<<endl;
    }
    return 0;
}
