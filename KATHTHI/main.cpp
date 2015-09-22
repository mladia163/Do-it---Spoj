#include <bits/stdc++.h>
using namespace std;
#define pii pair <int,int>
int visited[1001][1001];


int main()
{
    cin.sync_with_stdio(0);
    cin.tie();
    int t;
    cin>>t;
    while(t--)
    {
        int R,C,i,j,next_move_x=0,next_move_y=0;
        //cout<<"1"<<endl;
        cin>>R>>C;
        int graph[R][C];
        char str[C+10];
        for(i=0;i<R;i++)
        {
            cin>>str;
            for(j=0;j<C;j++)
            {
                graph[i][j]=str[j]-'a'+1;
                visited[i][j]=INT_MAX;
            }
        }
        /*  checking the graph
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        */
        pii temp;
        deque<pii>  Q;
        int movex[4]={0,1,0,-1};
        int movey[4]={1,0,-1,0};
        Q.push_back(make_pair(0,0));
        visited[0][0]=0;

        while(!Q.empty())
        {
            temp=Q.front();
            Q.pop_front();

            //base case
            if(temp.first==R-1 && temp.second==C-1)
                break;

            for(i=0;i<4;i++)
            {
                next_move_x=temp.first+movex[i];
                next_move_y=temp.second+movey[i];

                if(next_move_x>=0 && next_move_x<R && next_move_y>=0 && next_move_y<C)
                {
                    if(graph[next_move_x][next_move_y]==graph[temp.first][temp.second] &&
                        visited[next_move_x][next_move_y]>visited[temp.first][temp.second])
                    {
                        visited[next_move_x][next_move_y]=visited[temp.first][temp.second];
                        Q.push_front(make_pair(next_move_x,next_move_y));
                        //this is the point where we can start through this point as its its of low cost
                    }
                    else if(visited[next_move_x][next_move_y]>visited[temp.first][temp.second]+1)
                    {
                        visited[next_move_x][next_move_y]=visited[temp.first][temp.second]+1;
                        Q.push_back(make_pair(next_move_x,next_move_y));
                    }
                }
            }
        }
        cout<<visited[R-1][C-1]<<endl;
    }
    return 0;
}
