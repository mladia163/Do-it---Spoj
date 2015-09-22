#include <bits/stdc++.h>

using namespace std;
#define sd(a)   scanf("%d",&a)
#define mod     1000000007
int fib[1000001];

void calc_fib()
{
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<1000001;i++)
        fib[i]=((fib[i-1]%mod)+(fib[i-2]%mod));
}

int main()
{
    int t;
    sd(t);
    calc_fib();
    while(t--)
    {
        int a,b,c;
        sd(a);
        sd(b);
        c=__gcd(a,b);
        printf("%d\n",(fib[c]%mod));
    }
    return 0;
}
