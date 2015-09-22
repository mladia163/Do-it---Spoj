#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int coor;
        int t1,t2,t3,t_cx=0,area=0,cx=0;
        cin>>coor;
        int i,x[coor],y[coor];
        for(i=0;i<coor;i++)
            cin>>x[i]>>y[i];
        for(i=0;i<coor-1;i++)
        {
            t1 = x[i]+x[i+1];
            t2 = x[i]*y[i+1]-x[i+1]*y[i];
            t3 = t1*t2;
            area += t2;
            t_cx = t_cx+t3;
        }
        cx = t_cx/(area*6);
        cout<<area;
        cout<<cx;
        cout<<endl;
    }
    return 0;
}
