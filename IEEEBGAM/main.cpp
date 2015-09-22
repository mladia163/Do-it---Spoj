#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    double ans=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = n/(n+1);
        printf("%0.8lf\n",ans);
    }
    return 0;
}
