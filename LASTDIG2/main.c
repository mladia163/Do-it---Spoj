#include <stdio.h>
#include <string.h>
char arr[1001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int b;
        scanf("%s %lld",arr,&b);
        if(b==0)
            printf("1\n");
        else
        {
            int base=arr[strlen(arr)-1]-'0',res=1;
            b%=4;
            if(b==0)
                res=(base*base*base*base)%10;
            else if(b==1)
                res=(base)%10;
            else if(b==2)
                res=(base*base)%10;
            else if(b==3)
                res=(base*base*base)%10;
            printf("%d\n",res);
        }
    }
    return 0;
}
