#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int m,n,ans=0;
    scanf("%d %d",&n,&m);
    while(n!=-1 && m!=-1)
    {
        if(n==0 && m==0)
            printf("0\n");
        else if(n==m)
            printf("1\n");
        else if(n==0 && m!=0)
            printf("%d\n",m);
        else if(m==0 && n!=0)
            printf("%d\n",n);
        else
        {
            if(n>m)
                printf("%d\n",((n+m)/(m+1)));
            else
                printf("%d\n",((n+m)/(n+1)));
        }
        cin>>n>>m;
    }
    return 0;
}
