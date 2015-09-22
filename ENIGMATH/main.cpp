#include <iostream>

using namespace std;
long long int gcd(long long int a,long long int b)
{
    long long int temp;
    while(b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,x,y,gcd_2;
        cin>>a>>b;
        gcd_2=gcd(a,b);
        if(gcd_2>=a && gcd_2>=b)
        {
            x=gcd_2/a;
            y=gcd_2/b;
        }
        else
        {
            x=b/gcd_2;
            y=a/gcd_2;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
