#include <bits/stdc++.h>
using namespace std;

#define Lim 86029000
vector<bool> b((Lim>>1)+100);
int p[5000100];

void setPrimes()
{
        for(int i=3;i<=9257;i+=2)
            if(!b[(i-3)>>1])
                for(int j=i*i;j<Lim;j+=i)
                    if(j&1)
                        b[(j-3)>>1]=1;
        p[0]=2;
        int cnt=1;
        for(int i=0;2*i<Lim;i++)
            if(!b[i])
                p[cnt++]=2*i+3;
}

int main()
{
    int t;
    cin>>t;
    setPrimes();
    while(t--)
    {
        long long int n;
        cin>>n;

        cout<<p[n-1]<<endl;


    }
    return 0;
}
