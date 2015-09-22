#include <iostream>

using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
       long long int num,ans=0;
       cin>>num;
       while(num!=0)
       {
           num/=5;
           ans+=num;
       }
       cout<<ans<<endl;
    }
    return 0;
}
