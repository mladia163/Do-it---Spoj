#include <bits/stdc++.h>
using namespace std;
#define ll  long long int


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll a;
        int k,arr[35]={0};
        cin>>a;

        if(a%2==0)
        {
            unsigned i,temp;
            ll ans=0;

            for(i=1<<31,k=31;i>0;i=i/2,k--)
                arr[k] = (a&i)?1:0;

            for(i=31;i>=0;i--)
                if(arr[i]==1)
                {
                    temp=i;
                    break;
                }

            //for(i=0;i<=31;i++)
            //    cout<<arr[i]<<" ";
            //cout<<endl;
            //cout<<temp<<endl;

            for(i=0;i<=temp;i++)
                if(arr[i]==1)
                    ans = ans + pow(2,temp-i);

            cout<<ans<<endl;
        }
        else
            cout<<a<<endl;
    }
    return 0;
}
