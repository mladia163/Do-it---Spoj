#include <bits/stdc++.h>
using namespace std;

typedef struct chess
{
    char x,y;
    int c;
}chess;

int bfs(chess s,chess d)
{
    chess t;
    queue<chess> q;
    q.push(s);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.x<0 || t.x>7 || t.y>8 || t.y<1)
            continue;
        else if(t.x==d.x && t.y==d.y)
            return t.c;

        q.push((chess){t.x+1,t.y+2,t.c+1});     // considering all the 8 steps knight can move in a chess
        q.push((chess){t.x+2,t.y+1,t.c+1});
        q.push((chess){t.x+2,t.y-1,t.c+1});
        q.push((chess){t.x+1,t.y-2,t.c+1});
        q.push((chess){t.x-1,t.y-2,t.c+1});
        q.push((chess){t.x-2,t.y-1,t.c+1});
        q.push((chess){t.x-2,t.y+1,t.c+1});
        q.push((chess){t.x-1,t.y+2,t.c+1});
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[3],d[3];
        scanf("%s %s",s,d);
        int ans=0;


        ans = bfs((chess){s[0]-'a',s[1]-'0'},(chess){d[0]-'a',d[1]-'0'});
        printf("%d\n",ans);
    }
    return 0;
}
