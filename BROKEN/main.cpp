#include <bits/stdc++.h>
using namespace std;

int chq[1000011];
char str[1000001];

int main()
{
    int m;
    while(scanf("%d",&m)&&m)
    {
        getchar();
        gets(str);
        int len = strlen(str);
        int i=0,j=1,cur=1,ans=0;
        memset(chq,0,sizeof(chq));
        chq[(int)str[i]]++;
        while(j<len)
        {
            if(cur==m)
            {
                if(chq[(int)str[j]]==0)
                {
                    chq[(int)str[i]]--;
                    if(chq[(int)str[i]]==0)
                        chq[(int)str[j]]++,j++;
                    i++;
                }
                else
                {
                    if(chq[(int)str[j]]==0)
                        chq[(int)str[j]]++,j++,cur++;
                    else
                        chq[(int)str[j]]++,j++;
                }
            }
            ans=max(ans,j-i);
        }
        cout<<ans<<endl;
        cin>>m;
    }
    return 0;
}
