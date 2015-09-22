#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll  long long int

vector<ull> v;

int check(ull num,ll pos)       // return particular number at particular position value in binary form
{
    return ((num>>pos)&1);
}

ull gaussian_elimination()
{
    ll pos,n=v.size(),index_final=0,j,i;
    for(pos=log2(v[0]);pos>=0;pos--)
    {
        ll index_temp=index_final;
        while(index_temp<n && check(v[index_temp],pos)==0)
            index_temp++;
        if(index_temp==n)
            continue;   // if number below index_final is not having 1 in their current bit position
        swap(v[index_temp],v[index_final]);

        for(j=0;j<n;j++)
        {
            if(j!=index_final)
            {
                if(check(v[j],pos))
                    v[j]=v[j]^v[index_final];
            }
        }
        index_final++;         // after every bit we have to increase the index
    }

    ull ans=v[0];
    for(i=0;i<n;i++)
        ans=max(ans,ans^v[i]);
    return ans;
}

int main()
{
    ll n,i;
    scanf("%lld",&n);
    ull x,ans=0;
    v.clear();
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.rbegin(),v.rend());

    ans=gaussian_elimination();
    cout<<ans<<endl;

    return 0;
}
