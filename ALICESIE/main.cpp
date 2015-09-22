#include <iostream>
#include <math.h>
using namespace std;
int a[1000002];
/*
int calc(int n)
{
    int j,i,temp,ans=0;
    for(i=n;i>=2;i--)
    {

    }
    for(i=2;i<=n;i++)
        if(a[i]==0)
            ans++;
    return ans;
}*/


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,num,ans=0;
        cin>>num;
        /*for(i=0;i<=num;i++)
            a[i]=0;
        if(num==2)
            cout<<"1"<<endl;
        else if(num==3)
            cout<<"2"<<endl;
        else
        {
            ans=calc(num);
            cout<<ans<<endl;
        }*/
        cout<<(num+1)/2<<endl;
    }
    return 0;
}
