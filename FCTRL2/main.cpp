#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num,i,j,k=0,carry=0,arr[200]={1};
        cin>>num;
        for(i=1;i<=num;i++)
        {
            for(j=0;j<=k;j++)
            {
                arr[j] = arr[j]*i+carry;
                carry = arr[j]/10;
                arr[j] = arr[j]%10;
            }
            while(carry)
            {
                k++;
                arr[k] = carry%10;
                carry=carry/10;
            }
        }
        for(i=k;i>=0;i--)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}
