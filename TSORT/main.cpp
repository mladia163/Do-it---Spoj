#include <iostream>
#include <stdio.h>
using namespace std;
int arr[1000001];
int main()
{
    int i,t,temp=0;
    scanf("%d",&t);
    while(t--)
    {
        int num;
        scanf("%d",&num);
        arr[num]++;
        if(temp<=num)
            temp=num;
    }
    for(i=0;i<=temp;i++)
        while(arr[i]!=0)
        {
            printf("%d\n",i);
            arr[i]-=1;
        }
    return 0;
}
