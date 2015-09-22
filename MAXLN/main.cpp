#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        long long int r;
        double ans=0;
        cin>>r;
        ans = r*r*4 + 0.25;
        //cout<<"Case "<<i<<" "<<ans<<endl;
        printf("Case %d: %.2lf\n",i,ans);
    }
    return 0;
}
