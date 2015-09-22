#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int x,y,z,temp;
        cin>>x>>y>>z;
        temp=__gcd(x,y);
        if(x<z && y<z)
            cout<<"NO\n";
        else
        {
            if(z%temp==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
