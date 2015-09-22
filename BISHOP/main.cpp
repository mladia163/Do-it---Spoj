#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char str[101];
    int arr[101]={0},j=0,i,carry=0,temp,k=0,add=2;
    while(scanf("%s",str)!=EOF)
    {
        j=0;
        if(strlen(str)==1 && str[0]=='1')
            printf("1\n");
        else if(strlen(str)==1 && str[0]=='0')
            printf("0\n");
        else
        {
            for(i=strlen(str)-1;i>=0;i--)
                arr[j++]=str[i]-'0';
            carry=0;
            for(i=0;i<j;i++)
            {
                temp=arr[i]*2+carry;
                carry=temp/10;
                arr[i]=temp%10;
            }
            if(carry>0)
            {
                arr[i]=carry;
                k=i;
            }
            else
                k=i-1;
            add=2;
            for(i=0;i<=k;i++)
                if(arr[i]>=add)
                {
                    arr[i]=arr[i]-add;
                    break;
                }
                else
                {
                    arr[i]=10+arr[i]-add;
                    add=1;
                }
            if(arr[k]>0)
                printf("%d",arr[k]);
            for(i=k-1;i>=0;i--)
                printf("%d",arr[i]);
            printf("\n");
        }
    }
    return 0;
}
