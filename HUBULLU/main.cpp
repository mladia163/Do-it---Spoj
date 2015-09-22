#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,temp;
        cin>>n>>temp;
        if(!temp)
            cout<<"Airborne wins."<<endl;
        else
            cout<<"Pagfloyd wins."<<endl;
    }
    return 0;
}
