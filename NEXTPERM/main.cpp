#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
using namespace std;
char a[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        scanf("%s",a);
        if(next_permutation(a,a+n))
            for(i=0;i<n;i++)
                cout<<a[i];
        else
            cout<<"ERROR";
        cout<<endl;
    }
    return 0;
}
