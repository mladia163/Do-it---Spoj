#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y,i;
        bool k=true;
        cin>>n>>m;
        int a[11]={0};
        while(m--)
        {
            cin>>x>>y;
            ++a[x];
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]>1)
            {
                k=false;
                break;
            }
        }
        if(k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
