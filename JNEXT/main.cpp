#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,i,temp;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        for(i=n-1;i>=1;i--)
            if(a[i]>a[i-1])
            {
                swap(a[i],a[i-1]);
                temp=i;
                break;
            }
        sort(a+temp,a+n);
        for(i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
