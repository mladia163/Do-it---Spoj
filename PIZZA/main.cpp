#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,i,a,b;
    float ans=0,ans0=0,ans1=0,ans2=0;
    int k1=0,k2=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
        scanf("%d/%d",a,b);
        if(a==1&&a==4)
            ans0+=0.25;
        else if(a==3 && a==4)
        {
            ans1+=0.75;
            k1++;
        }
        else
        {
            ans2+=0.5;
            k2++;
        }
    }
    if(k1>=k2)
        k2=k1-k2;
    else
        k2=k2-k1;
    ans = ans0+ans1+ans2;
    ans = ans-k1+k2;
    cout<<ans;


    return 0;
}
