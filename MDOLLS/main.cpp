#include <bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
#define pb  push_back
#define mp  make_pair
#define ll  long long int
#define vi  vector < int >
#define vvi vector < vector < int > >
#define maxn    100010
#define mod 1000000007
#define mem(a,b)    memset(a,b,sizeof(a))
#define FOR(i,a,b)  for(i=a,i<=b;i++)
#define FOR0(i,b)   for(i=0;i<b;i++)
#define ff   first
#define ss  second
#define all(v)  v.begin(),v.end()


set< pii > arr,ac;
set< pii > ::iterator itr,itr1,k;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ac.clear();
        arr.clear();
        int m,a,b,w,h,ans=0,cnt=0,i,j;

        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>w>>h;
            arr.insert(mp(w,h));
        }

        while(arr.size()!=0)
        {
            cout<<"\n\n";
            ac.clear();
            for(itr=arr.begin();itr!=arr.end();itr++)
            {
                itr1=ac.end();
                cout<<"itr1 -"<<itr1->ff<<" "<<itr1->ss<<"\n";
                ac.insert(*itr);
                if(itr->ff>itr1->ff && itr->ss>itr1->ss)
                {
                    k=ac.find(*itr);
                    k++;                    // make it to next index
                    if(k!=ac.end())          // if at ast index the a[i] is not present delete it ;)
                        ac.erase(k);
                    cout<<itr->ff<<" "<<itr->ss<<"\n";
                }
                else
                    ac.erase(*itr);
            }
            for(itr=ac.begin();itr!=ac.end();itr++)
                arr.erase(*itr);
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
