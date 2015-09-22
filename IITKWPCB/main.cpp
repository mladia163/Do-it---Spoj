#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,temp,ans;
        cin>>n;
        temp=floor(n/2);
        //cout<<temp;
        while(temp!=1)
        {
            if(__gcd(temp,n)==1)
            {
                ans=temp;
                break;
            }
            temp--;
        }

        if(temp==1)
            cout<<temp<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
