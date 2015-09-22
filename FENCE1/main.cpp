#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
# define pi           3.14159265358979323846
int main()
{
    int t;
    cin>>t;
    while(t!=0)
    {
        float ans=0;
        ans=(t*t)/(atan(1.0)*8);
        printf("%.2f\n",ans);
        cin>>t;
    }
    return 0;
}
