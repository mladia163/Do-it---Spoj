#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define ll  long long int
ll ans[1001][1001][3];

ll k(ll h,ll a,ll temp)
{
    if(temp==0)
        h+=3,a+=2;
    else if(temp==1)
        h-=5,a-=10;
    else
        h-=20,a+=5;

    if(h<=0 || a<=0)
        return 0;

    if(ans[h][a][temp]!=0)
        return ans[h][a][temp];

    if(temp == 0)
    {
        ans[h][a][temp] = max(k(h,a,1),k(h,a,2)) + 1;
        return ans[h][a][temp];
    }
    else if(temp == 1)
    {
        ans[h][a][temp] = k(h,a,0) + 1;
        return ans[h][a][temp];
    }
    else
    {
        ans[h][a][temp] = k(h,a,0) + 1;
        return ans[h][a][temp];
    }
}



int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll h,a;
        scanf("%lld %lld",&h,&a);
        ll answer=0;
        answer = k(h,a,0);
        printf("%lld\n",answer);
    }
    return 0;
}
