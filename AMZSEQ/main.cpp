#include <iostream>

using namespace std;
#define ll long long int

int main()
{
    int n;
    cin>>n;
    int one[n+1],two[n+1],zero[n+1];
    one[1]=1;
    two[1]=1;
    zero[1]=1;
    for(int i=2;i<=n;i++)
    {
        zero[i] = zero[i-1]+one[i-1];
        one[i] = one[i-1]+two[i-1]+zero[i-1];
        two[i] = one[i-1]+two[i-1];
    }
    cout<<one[n]+zero[n]+two[n]<<endl;
    return 0;
}
