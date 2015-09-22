#include <bits/stdc++.h>
using namespace std;

char str[1000001];
char arr[]={'2','3','5','7'};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k=0;
        cin>>n;
        while(n!=0)
        {
            str[k++]=arr[(n-1)%4];
            n=(n-1)/4;
        }
        str[k]='\0';
        for(int i=k-1;i>=0;i--)
            cout<<str[i];
        cout<<endl;
    }

    return 0;
}
