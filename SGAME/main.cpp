#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,temp=-1,a,b,n,arr[310]={0};
        bool ans=true;
        cin>>n;
        cin>>a>>b;
        while(a!=-1 && b!=-1)
        {
            arr[a]++;
            arr[b]++;
            cin>>a>>b;
            temp=max(temp,max(a,b));
        }
        for(i=0;i<temp;i++)
            if(arr[i]%2==1)
            {
                ans=false;
                break;
            }
        if(!ans)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
