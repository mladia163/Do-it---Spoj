#include <iostream>
#include <stdlib.h>
using namespace std;
int cmpfnc(const void *a,const void *b)
{
    return ((*(int*)a)-(*(int*)b));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int arr[n+10];
        long long int res=1;
        bool k=true;
        for(i=0;i<n;i++)
            cin>>arr[i];
        qsort(arr,n,sizeof(int),cmpfnc);
        for(i=n-1;i>=0;i--)
        {
            if((arr[i]-i)<=0)
            {
                k=false;
                break;
            }
            res=(res*(arr[i]-i))%1000000007;
        }
        if(k)
            cout<<res<<endl;
        else
            cout<<"0"<<endl;
    }
    cout<<"KILL BATMAN\n";
    return 0;
}
