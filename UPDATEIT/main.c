#include <stdio.h>

//using namespace std;
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,u,l,r,val,i,temp;
        scanint(n);
        scanint(u);
        int a[10001]={0};
        while(u--)
        {
            scanint(l);
            scanint(r);
            scanint(val);
            for(i=l;i<=r;i++)
                a[i]+=val;
        }
        int q;
        scanint(q);
        while(q--)
        {
            scanint(temp);
            printf("%d\n",a[temp]);
        }
    }
    return 0;
}
