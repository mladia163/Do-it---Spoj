#include <bits/stdc++.h>
using namespace std;
#define sd(a,b,c)   scanf("%d %d %d",&a,&b,&c)
#define AP   printf("AP");
#define GP   printf("GP");

int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    while(a!=0 && b!=0 && c!=0)
    {
        bool ap=false;
        float temp=0;
        if((2*b)==(a+c))
            ap=true;

        //if(ap==true)
          //  if((c-b)==0)
            //    ap=false;

        if(ap)
        {
            temp = c + (c-b);
            cout<<"AP "<<temp<<endl;
        }
        else
        {
            temp = c * (c/b);
            cout<<"GP "<<temp<<endl;
        }
        cin>>a>>b>>c;
    }
    return 0;
}
