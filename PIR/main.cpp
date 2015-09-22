#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double U,V,W,u,v,w,X,x,Y,y,Z,z;
        double ans1,ans2,ans,a,b,c,d;
        cin>>u>>w>>V>>v>>W>>U;
        X=(w-U+v)*(U+v+w);
        x=(U-v+w)*(v-w+U);
        Y=(u-V+w)*(V+w+u);
        y=(V-w+u)*(w-u+V);
        Z=(v-W+u)*(W+u+v);
        z=(W-u+v)*(u-v+W);
        a=sqrt(x*Y*Z);
        b=sqrt(y*Z*X);
        c=sqrt(z*X*Y);
        d=sqrt(x*y*z);
        ans1=192*u*v*w;
        ans2=sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d));
        ans=ans2/ans1;
        printf("%.4lf\n",ans);
    }
    return 0;
}
