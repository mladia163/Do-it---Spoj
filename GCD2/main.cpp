#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int a,temp,i,ans=0,len;
        scanf("%d",&a);
        string b;
        cin>>b;
        if(a==0)
        {
            cout<<b<<endl;
        }
        else
        {
        len=b.length();
        for(i=0,temp=0;i<len;i++)
            temp=(temp*10+(b[i]-'0'))%a;
        ans = gcd(a,temp);
        cout<<ans<<endl;
        }
    }
    return 0;
}
