#include <iostream>
#include <stdio.h>
using namespace std;
#define yes cout<<"Yes\n";
#define no  cout<<"No\n";
int main()
{
    // Five fermat's prime 3,5,17,257,65537
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int temp;
        scanf("%d",&temp);
        while(temp%2==0)
            temp/=2;
        if(temp%3==0)
            temp/=3;
        if(temp%5==0)
            temp/=5;
        if(temp%17==0)
            temp/=17;
        if(temp%257==0)
            temp/=257;
        if(temp%65537==0)
            temp/=65537;
        if(temp==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
