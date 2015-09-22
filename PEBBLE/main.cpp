#include <bits/stdc++.h>
using namespace std;


int main()
{
    char str[100000];
    int z=1;
    while(scanf("%s",str)!=EOF)
    {
        int ans=0,i,len = strlen(str),temp;

        for(i=0;i<len;i++)
            if(str[i]!='0')
            {
                temp=i;
                break;
            }

        for(i=temp;i<len;i++)
        {
            if(str[i]=='1' && ans%2==0)
                ans+=1;
            else if(str[i]=='0' && ans%2==1)
                ans+=1;
        }

        cout<<"Game #"<<z<<": "<<ans<<endl;
        z++;
    }
    return 0;
}
