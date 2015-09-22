#include <iostream>

using namespace std;

bool chqby2(unsigned long long int n)
{
    if(n==0)
        return false;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            return false;
    }
    return true;
}


int main()
{
    unsigned long long int n;
    cin>>n;
    if(chqby2(n))
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    return 0;
}
