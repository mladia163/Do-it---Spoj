#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define ll  long long int

int main()
{
    int t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        ll num,ans;
        scanf("%lld", &num);
        ans = sqrt(num);
        if( ans*ans == num )
            printf("Case %d: Yes\n", j);
        else
            printf("Case %d: No\n", j);

    }
    return 0;
}
