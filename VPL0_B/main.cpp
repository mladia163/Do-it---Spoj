#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];

int main()
{
    int t,k=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,u,i,temp1,temp2,j;
        scanf("%d %d",&n,&u);
        int arr[n+1];
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);

        }
        for(i=0;i<10001;i++)
            graph[i].clear();
        sort(arr,arr+n);
        //int mini=INT_MAX,maxi=INT_MIN;

        for(i=0;i<n;i++)
        {
            temp1=arr[i]/u;
            temp2=arr[i]%u;
            graph[temp1].push_back(temp2);
          //  maxi=max(maxi,temp1);
          //  mini=min(mini,temp1);
        }

        int num=0,num1=0;
        int temp11=temp1;
        while(temp1!=0)
        {
            temp1/=10;
            num+=1;
        }
        //cout<<"/////"<<num<<"/////"<<endl;

        //printf("Scenario #%d:\n",k);
        printf("Scenario #%d:\n",k) ;
        for(i=0;i<=temp11;i++)
        {
            num1=0;
            if(!graph[i].empty())
            {
                temp1=i;
                if(temp1==0)
                    num1=1;
                while(temp1!=0)
                {
                    temp1/=10;
                    num1+=1;
                }

                //cout<<"/////"<<num1<<"/////"<<endl;
                for(j=1;j<=(num-num1);j++)
                    printf(" ");

                printf("%d | ",i) ;
                for(j=0;j<graph[i].size();j++)
                    cout<<graph[i][j]<<" ";
                printf("\n");
            }
        }

        k+=1;
    }
    return 0;
}
