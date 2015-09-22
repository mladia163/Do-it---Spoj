#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int temp,i,count1=0,n,ans=0,count=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            if(temp!=0)
                count++;
            else
                count1++;
        }
        ans = pow(2,count)-1+count1;
        cout<<ans<<endl;
    }
    return 0;
}
