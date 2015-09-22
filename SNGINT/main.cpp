#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        if(n==0)
        {
            printf("10\n");
            continue;
        }
        if(n<10)
        {
            printf("%lld\n",n);
            continue;
        }
        int i,j,m[10]={0};

        for(i=9;i>1;i--)
            while(n%i==0)
            {
                n/=i;
                m[i]++;
            }

        if(n!=1)
        {
            printf("-1\n");
            continue;
        }
        for(i=2;i<10;i++)
            while(m[i]!=0)
            {
                printf("%d",i);
                m[i]--;
            }
        printf("\n");
    }
    return 0;
}
