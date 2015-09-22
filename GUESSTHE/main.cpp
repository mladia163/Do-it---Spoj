#include <bits/stdc++.h>
using namespace std;
#define ll  long long int

int main()
{
    char str[22];
    scanf("%s",str);
    while(str[0]!='*')
    {
        ll i,len = strlen(str),ans=1,a[20],k=0;
        bool ans1=true;
        for(i=0;i<len;i++)
        {
            if(str[i]=='Y')
                ans = (ans)*(i+1) / (__gcd(ans,i+1));
            else
                a[k++]=i+1;
        }
        for(i=0;i<k;i++)
            if(ans%a[i]==0)
            {
                ans1=false;
                break;
            }
        if(ans1)
            printf("%lld\n",ans);
        else
            printf("-1\n");
        scanf("%s",str);
    }

    return 0;
}
