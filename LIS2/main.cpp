#include <iostream>
using namespace std;
long long int LIS_BEST(long long int a[][2],long long int n)
{
    long long int m[n+1];
    long long int l=0,i,lo,hi,mid,newl;
    for(i=0;i<n;i++)
    {
        lo=1;hi=l;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(a[m[mid]][0]<a[i][0] && a[m[mid]][1]<a[i][1])
                lo = mid+1;
            else
            hi = mid-1;
        }
        newl = lo;
        m[newl]=i;
        if(newl>l)
            l=newl;
    }
    return l;
}
int main()
{
    long long int n,y;
    cin>>n;
    long long int a[n][2],i;              // a[][0] for x coordinate and a[][1] for y coordinate
    for(i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1];
    y=LIS_BEST(a,n);
    cout<<y<<endl;
    return 0;
}

