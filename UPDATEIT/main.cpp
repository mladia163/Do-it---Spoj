#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked
int a[10001];
int t[10001];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int test;
    scanint(test);
    while(test--)
    {
        int n,u,l,r,val,i,temp=0;
        scanint(n);
        scanint(u);
        for(i=0;i<n;i++)
            a[i]=t[i]=0;
        while(u--)
        {
            scanint(l);
            scanint(r);
            scanint(val);
            t[l]+=val;
            t[r+1]-=val;
        }
        for(i=0;i<n;i++)
        {
            temp+=t[i];
            a[i]=temp;
        }
        int q,q1;
        scanint(q);
        while(q--)
        {
            scanint(q1);
            printf("%d\n",a[q1]);
        }
    }
    return 0;
}
