#include <iostream>

using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,ans;
        bool k=true;
        cin>>x>>y;
        if(y==x)
            k=true;
        else if(y==(x-2))
            k=true;
        else
            k=false;
        if(k)
        {
            if(x%2==0)
                ans=x+y;
            else
                ans=x+y-1;
            cout<<ans<<endl;
        }
        else
            cout<<"No Number"<<endl;
    }
    return 0;
}
