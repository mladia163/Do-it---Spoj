#include <bits/stdc++.h>
using namespace std;
#define absurd cout<<"absurd\n";
#define not_absurd  cout<<"not absurd\n";


long long int dekhlo(long long int temp)
{
    //long long int a,b,k=0;

    while(temp%10==0)
        temp/=10;

    /*a=temp;
    while(a!=0)
    {
        a/=10;
        k++;
    }

    if(temp%10==5)
        b=2*k-1;
    else
        b=2*k;*/

    return temp;
}



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int c,temp;
        long double a_,b_;
        scanf("%lld",&c);

        c=dekhlo(c);
        a_=0.95*c;
        b_=1.05*c;

        temp=c-(c%10);

        if(temp>=a_ && temp<=b_)
        {
            absurd
            continue;
        }
        temp+=5;
        if(temp>=a_ && temp<=b_ && temp!=c)
        {
            absurd
            continue;
        }
        temp+=5;
        if(temp>=a_ && temp<=b_)
        {
            absurd
            continue;
        }

        else
        {
            not_absurd

        }
    }
    return 0;
}
