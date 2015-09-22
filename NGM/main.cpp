#include <iostream>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    if(t%10==0)
        cout<<"2";
    else
        cout<<"1"<<endl<<t%10;
    return 0;
}
