#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define NO      printf("Box cannot be dropped.\n");
#define YES     printf("Escape is possible.\n");
#define ll  long long int

int main()
{
    int t;
    sd(t);
    while(t--)
    {
        ll a,b,p,q;
        double temp1;
        cin>>a>>b>>p>>q;

        if(a<b)
            swap(a,b);
        if(p<q)
            swap(p,q);
        double d_b=(double)b,d_a=(double)a,d_p=(double)p,d_q=(double)q;
        temp1 = (2.0*d_p*d_q*d_a) + (pow(d_p,2)-pow(d_q,2))*(sqrt(pow(d_p,2)+pow(d_q,2)-pow(d_a,2)));
        temp1 = temp1 / (pow(d_p,2)+pow(d_q,2));

        if(a>p && b>q)
        {
            YES
            continue;
        }
        if((d_b-temp1)>0.0000001)
            YES
        else
            NO
    }

    return 0;
}
