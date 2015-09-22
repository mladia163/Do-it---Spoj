#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <string.h>
using namespace std;
int a[100];
char s[100];
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        int i,len,temp;
        scanf("%d %s",&temp,s);
        len=strlen(s);
        for(i=0;i<len;i++)
            a[i]=s[i]-'0';
        if(next_permutation(a,a+len))
        {
            printf("%d ",j);
            for(i=0;i<len;i++)
                printf("%d",a[i]);
        }
        else
            printf("%d BIGGEST",j);
        printf("\n");
    }
    return 0;
}
