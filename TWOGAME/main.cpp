#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define sd(a)   scanf("%d",&a)
#define Y       printf("Y\n");
#define N       printf("N\n");

int main()
{
    int t;
    sd(t);
    while(t--)
    {
        ll a,b,ans=0;
        scanf("%lld %lld",&a,&b);

        if(a<b)
            swap(a,b);
        while(b)
            ans=a,a=b,b=ans%b;
        while(a%2==0)
            a/=2;

        if(a==1)    Y
        else    N
    }
    return 0;
}
