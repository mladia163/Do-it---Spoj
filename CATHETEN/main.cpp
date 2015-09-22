#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define sd(a)   scanf("%d",&a)

vector<ll> v;
ll calc_no_of_divisors(ll n)
{
    v.clear();
    ll i,temp=0,take_care_of_2=0;
    while(n%2==0)
        n/=2,take_care_of_2+=1;
    //v.push_back(take_care_of_2);

    temp=0;
    for(i=3;i<=sqrt(n);i+=2)
    {
        temp=0;
        while(n%i==0)
            n/=i,temp++;
        if(temp!=0)
            v.push_back(temp);
    }
    if(n>2)
        v.push_back(1);

    ll ans=1;
    if(take_care_of_2>0)
        ans=ans*(2*take_care_of_2-1);
    for(i=0;i<v.size();i++)
        ans=ans*(2*v[i]+1);
    ans-=1;
    ans=ans/2;
    return ans;
}




int main()
{
    int t;
    sd(t);
    while(t--)
    {
        ll n,ans_f=0;
        scanf("%lld",&n);
        ans_f=calc_no_of_divisors(n);
        cout<<ans_f<<endl;
    }
    return 0;
}
