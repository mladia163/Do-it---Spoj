#include <iostream>

using namespace std;
int n,i,a[100];
bool chq(int temp,int loc)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(a[mid]==temp && mid!=loc)
            return true;
        if(temp<a[mid])
            hi=mid-1;
        else
            lo=lo+1;
    }
    return false;
}


int main()
{
    int ans=-1;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        int temp = a[i];
        if(chq(temp,i))
            ans=i;
        else
            continue;
    }
    cout<<ans<<endl;
    return 0;
}
