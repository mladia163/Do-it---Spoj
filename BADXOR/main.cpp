#include <bits/stdc++.h>
using namespace std;

#define fast    ios::sync_with_stdio(0); cin.tie(0)
#define maxn    1300
#define NN  1111
#define mod 100000007
#define casp(i,ans) printf("Case %d: %d\n",i,ans)

#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57)
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

int arr[maxn],B[maxn];
int  dp[maxn][2*NN];

int main()
{
//	fast;
    int cnt=1,t3;
    t3=read_int();
    //cin>>t3;
    for(cnt=1;cnt<=t3;cnt++)
    {
        int i,j,ans=0,temp=0,N,M;
      N=read_int();
      M=read_int();
      //  cin>>N>>M;
        memset(B,0,sizeof(B));
        for(i=0;i<N;i++)    arr[i]=read_int();//  cin>>arr[i];
        for(j=0;j<M;j++)
        {
        temp=read_int();
           // cin>>temp;
            B[temp]++;
        }

        memset(dp,0,sizeof dp);
        dp[0][0]=1;

        for(i=1;i<=N;i++)
        {
            for(j=0;j<1024;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j^arr[i-1]];
                if(dp[i][j]>=mod)   dp[i][j]-=mod;

               /* if(i==N && B[j]==0)
                {
                    ans+=dp[i][j];
                    if(ans>=mod)    ans-=mod;
                }
                */
            }
        }
        ans=0;
        for(j=0;j<1024;j++)
        if(B[j]==0) {ans+=dp[N][j];if(ans>=mod) ans-=mod;}
        casp(cnt,ans);
    }
    return 0;
}
