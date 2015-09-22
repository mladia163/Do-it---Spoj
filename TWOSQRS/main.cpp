#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,a=0,b;
        bool ans=false;
        scanf("%lld",&n);
        b=sqrt(n);
        while(a<=b)
        {
            if((a*a)>n)
                break;
            else if((a*a+b*b)==n)
            {
                ans=true;
                break;
            }
            else
                if((a*a+b*b)<n)
                    a+=1;
                else
                    b-=1;
        }
        if(n<0)
        {
            printf("No\n");
            continue;
        }
        if(n==0)
        {
            printf("Yes\n");
            continue;
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
