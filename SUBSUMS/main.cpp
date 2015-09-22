#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll  long long int


int N,A,B;

int main()
{
    cin>>N>>A>>B;
    int i,temp=0,low=N/2,arr1[40]={0},arr2[40]={0};
    vector<int> a1;
    vector<int> a2;
    vector<int>::iterator t1,t2;
    for(i=0;i<low;i++)
        cin>>arr1[i];
    for(i=low;i<N;i++)
        cin>>arr2[i-low];

    /*for(i=0;i<low;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(i=0;i<(N-low);i++)
        cout<<arr2[i]<<" ";
    cout<<endl;*/

    int temp2=0,sum=0,k=0;
    temp=pow(2,low);
    //cout<<"temp="<<temp<<endl;
    for(i=0;i<temp;i++)
    {
        sum=0;
        k=0;
        for(temp2=i;temp2!=0;temp2/=2)
        {
            if(temp2%2==1)
                sum+=arr1[k];
            k++;
        }
        //if(sum>=A && sum<=B)
            a1.push_back(sum);
                //cout<<"1";
           // else
             //   cout<<"0";
        //cout<<endl;
    }
    //cout<<endl;
    //cout<<endl;
    //sort(a1.begin(),a1.end());
    temp=pow(2,N-low);
    //cout<<"temp="<<temp<<endl;
    for(i=0;i<temp;i++)
    {
        sum=0;
        k=0;
        for(temp2=i;temp2!=0;temp2/=2)
        {
            if(temp2%2==1)
                sum+=arr2[k];
            k++;
        }
        //if(sum>=A && sum<=B)
            a2.push_back(sum);
            //if(temp2%2==1)
              //  cout<<"1";
            //else
              //  cout<<"0";
      //  cout<<endl;
    }
    sort(a2.begin(),a2.end());
    //cout<<endl;
   /* for(i=0;i<a1.size();i++)
        cout<<a1[i]<<" ";
    cout<<endl;
    for(i=0;i<a2.size();i++)
        cout<<a2[i]<<" ";
    cout<<endl;*/

    ll ans=0;
    //int t1=0,t2=0;
    for(i=0;i<a1.size();i++)
    {
        t1=lower_bound(a2.begin(),a2.end(),A-a1[i]);
        t2=upper_bound(a2.begin(),a2.end(),B-a1[i]);
        ans+=(t2-t1);
    }
    cout<<ans<<endl;
    return 0;
}
