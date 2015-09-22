#include <bits/stdc++.h>
using namespace std;

typedef struct chess
{
    int a,b,cost;
}chess;

int bfs_modified(chess s,chess d)
{
    /*int i,j,visited[8][8];
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            visited[i][j]=false;
    */vector<int> v;
    chess p;
    p.cost=0;
    queue<chess> q;
    q.push(s);
    //visited[s.a][s.b]=true;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
      //  visited[p.a][p.b]=true;
        if(p.a<0 || p.a>7 || p.b<0 || p.b>8)
            continue;
        else if(p.a==d.a && p.b==d.b)
            v.push_back(p.cost);
        //cout<<"///// here starts round "<<endl;
        q.push((chess){p.a+1,p.b+2,p.cost+(p.a*(p.a+1)+p.b*(p.b+2))});
        //cout<<p.a+1<<" "<<p.b+2<<" "<<p.cost+(p.a*(p.a+1)+p.b*(p.b+2))<<endl;
        q.push((chess){p.a+2,p.b+1,p.cost+(p.a*(p.a+2)+p.b*(p.b+1))});
        //cout<<p.a+2<<" "<<p.b+1<<" "<<p.cost+(p.a*(p.a+2)+p.b*(p.b+1))<<endl;
        q.push((chess){p.a+2,p.b-1,p.cost+(p.a*(p.a+2)+p.b*(p.b-1))});
        //cout<<p.a+2<<" "<<p.b-1<<" "<<p.cost+(p.a*(p.a+2)+p.b*(p.b-1))<<endl;
        q.push((chess){p.a+1,p.b-2,p.cost+(p.a*(p.a+1)+p.b*(p.b-2))});
        //cout<<p.a+1<<" "<<p.b-2<<" "<<p.cost+(p.a*(p.a+1)+p.b*(p.b-2))<<endl;
        q.push((chess){p.a-1,p.b-2,p.cost+(p.a*(p.a-1)+p.b*(p.b-2))});
        //cout<<p.a-1<<" "<<p.b-2<<" "<<p.cost+(p.a*(p.a-1)+p.b*(p.b-2))<<endl;
        q.push((chess){p.a-2,p.b-1,p.cost+(p.a*(p.a-2)+p.b*(p.b-1))});
        //cout<<p.a-2<<" "<<p.b-1<<" "<<p.cost+(p.a*(p.a-2)+p.b*(p.b-1))<<endl;
        q.push((chess){p.a-2,p.b+1,p.cost+(p.a*(p.a-2)+p.b*(p.b+1))});
        //cout<<p.a-2<<" "<<p.b+1<<" "<<p.cost+(p.a*(p.a-2)+p.b*(p.b+1))<<endl;
        q.push((chess){p.a-1,p.b+2,p.cost+(p.a*(p.a-1)+p.b*(p.b+2))});
        //cout<<p.a-1<<" "<<p.b+2<<" "<<p.cost+(p.a*(p.a-1)+p.b*(p.b+2))<<endl;

        //cout<<"///// here roun ends "<<endl<<endl;
    }
    sort(v.begin(),v.end());
    return v[0];
}



int main()
{
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
    {
        int ans;
        ans=bfs_modified((chess){a,b},(chess){c,d});
        cout<<ans<<endl;
    }
    return 0;
}
