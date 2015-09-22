#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)
#define ll  long long int

bool visited[20000]={0};

void bfs(int n)
{
    string str;

   // if(n==1)
     //   ans="1";

    memset(visited,0,sizeof(visited));

    int val=0;
    pair<string,int> temp;
    queue < pair < string,int > > Q;
    Q.push(make_pair("1",1));

    while(!Q.empty())
    {
        temp=Q.front();
        str = temp.first;
        int rem = temp.second;
        Q.pop();
        visited[rem]=1;

        if(rem==0)
            break;

        val = (rem*10)%n;
        if(visited[val]!=1)
            Q.push(make_pair(str+'0',val));

        val = (rem*10 +1)%n;
        if(visited[val]!=1)
            Q.push(make_pair(str+'1',val));
    }

    cout<<str<<"\n";
}


int main()
{
    int t;
    sd(t);
    while(t--)
    {
        int n;
        sd(n);
        if(n==1)
            cout<<"i love u";
        else
        bfs(n);



    }
    return 0;
}
