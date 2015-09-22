#include <bits/stdc++.h>
using namespace std;


int main()
{
    int i,n;
    double temp,ans=INT_MAX;
    cin>>n;
    pair < long long int , long long int > l[n+1];
    for(i=0;i<n;i++)
        cin>>l[i].first>>l[i].second;
    sort(l,l+n);
    //for(i=0;i<n;i++)
    //    cout<<l[i].first<<" "<<l[i].second<<endl;

    for(i=0;i<n-1;i++)
    {
        temp = sqrt(pow((l[i+1].second-l[i].second),2) + pow((l[i+1].first-l[i].first),2));
        if(ans>temp)
            ans=temp;
    }
    printf("%0.6lf\n",ans);
    return 0;
}
