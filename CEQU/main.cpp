#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define Yes(a)  cout<<"Case "<<a<<": Yes\n";
#define No(a)  cout<<"Case "<<a<<": No\n";

int main()
{
    int t,x=1;
    sd(t);
    while(t--)
    {
        int a,b,c;
        bool ans = false;
        sd(a);
        sd(b);
        sd(c);

        if(c%__gcd(a,b)==0)
            ans=true;

        if(ans)
            Yes(x)
        else
            No(x)
        x++;
    }
    return 0;
}
