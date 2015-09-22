#include <bits/stdc++.h>
using namespace std;
#define ll  long long int

ll arr[1001]={0};

int main()
{
    ll n,i,start=-1,end_=-1,j,maxi=-1,temp=-1;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];

    for(i=0;i<n;i++)
    {
        temp=arr[i];
        if(maxi<temp)                       // check if without xor we can get max value or not in this case number itself is the max value :p
            maxi=temp,start=end_=i;

        for(j=i+1;j<n;j++)                  // xor to all other and also containing max of all of them
        {
            temp=temp^arr[j];
            if(maxi<temp)
                maxi=temp,start=i,end_=j;
        }
    }

    cout<<maxi<<endl<<start+1<<" "<<end_+1<<endl;
    return 0;
}
