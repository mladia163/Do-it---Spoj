#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int b[100001];
bool visited[100001];

int main()
{
    int n,k=1;
    while(scanf("%d",&n)&&n)
    {
        int j,sum=0,i,ans=0,mini;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            b[i]=arr[i];
            visited[i]=false;
        }
        sort(b,b+n);

        map<int,int> m;
        for(i=0;i<n;i++)        // it help in making loop
            m[b[i]]=i;
        ans=0;

        for(i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                if(m[arr[i]]==i)
                {
                    visited[i]=true;
                    continue;
                }

                // we are entering in a loop
                mini=arr[i];
                sum=0;
                j=i;
                int k1=0;

                while(visited[j]==false)        // jese hi true milega loop complete ho jaeyga
                {
                    sum+=arr[j];
                    k1++;
                    visited[j]=true;
                    if(mini>arr[j])
                        mini=arr[j];
                    j=m[arr[j]];
                }
                sum-=mini;
                ans+=sum+(mini*(k1-1));

                if((2*(b[0]+mini))<((mini-b[0])*(k1-1)))
                    ans-=(mini-b[0])*(k1-1)-2*(b[0]+mini);
            }
        }

        cout<<"Case "<<k<<": "<<ans<<endl;
        k++;
        //scanf("%d",&n);
    }
    return 0;
}
