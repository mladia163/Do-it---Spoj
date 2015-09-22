#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    do
    {
        long long int ans;
        ans = (n*(n+1)*(2*n+1))/6;
        cout<<ans<<endl;
        cin>>n;
    }while(n!=0);

    return 0;
}
