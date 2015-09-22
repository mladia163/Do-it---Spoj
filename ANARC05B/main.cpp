#include <bits/stdc++.h>
using namespace std;
#define pb  push_back

int a[10011],b[10011];

int main()
{
    bool ans1=true;
    while(ans1)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        int i,j,na,nb;
        cin>>na;
        if(na==0)
        {
            ans1=false;
            continue;
        }
        for(i=0;i<na;i++)
            cin>>a[i];

        cin>>nb;
        for(i=0;i<nb;i++)
            cin>>b[i];

        for(i=j=0;i<na || j<nb;)
        {
            if(a[i]==b[j] && i<na && j<nb)
            {
                a[i]+=a[i-1];
                b[j]+=b[j-1];
                a[i]=b[j]=max(a[i],b[j]);
                i++,j++;
            }
            else if(i>na)
            {
                b[j]+=b[j-1];
                j++;
            }
            else if(j>nb)
            {
                a[i]+=a[i-1];
                i++;
            }
            else if(a[i]<b[j])
            {
                a[i]+=a[i-1];
                i++;
            }
            else if(a[i]>b[j])
            {
                b[j]+=b[j-1];
                j++;
            }
        }
        cout<<max(a[na-1],b[nb-1])<<"\n";
    }
    return 0;
}
