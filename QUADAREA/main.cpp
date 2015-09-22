#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double a,b,c,d,s,area=0;
        cin>>a>>b>>c>>d;
        s = (a+b+c+d)/2;
        area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
        printf("%0.2lf\n",area);
    }
    return 0;
}
