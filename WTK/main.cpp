#include <iostream>
#include <stdio.h>
using namespace std;

int modified_josephus(int n,int k)
{
    if(n==1)
        return 1;
    else
        return (modified_josephus(n-1,k+1)+k)%n + 1;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        ans = modified_josephus(n,0);
        printf("%d\n",ans);
    }
    return 0;
}
