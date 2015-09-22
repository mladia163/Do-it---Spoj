#include <iostream>

using namespace std;


int LIS_BEST(int a[],int n)
{
    int i,j,lis[n],max=0;
    //lis[0]=1;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
        for(j=0;j<=i;j++)
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i] = lis[j] + 1;
    }
    for(i=0;i<n;i++)
         if(max<lis[i])
             max=lis[i];
    return max;
}
int main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<LIS_BEST(a,n)<<endl;
    return 0;
}


