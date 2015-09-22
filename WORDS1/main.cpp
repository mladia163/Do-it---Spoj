#include <bits/stdc++.h>
using namespace std;
#define NO  cout<<"The door cannot be opened.\n"
#define YES cout<<"Ordering is possible.\n"

int visit[100];
vector<int> graph[100];
int first[100];
int last[100];

void dfs(int v)
{
    visit[v]=1;
   // char p=v+'a';
 //   cout<<p<<" ";
    for(int i=0;i<graph[v].size();i++)
        if(!visit[graph[v][i]])
            dfs(graph[v][i]);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,v=-1,i;
        string str;
        cin>>n;
        memset(visit,0,sizeof visit);
        for(i=0;i<100;i++)
        {
            last[i]=0;
            first[i]=0;
            graph[i].clear();
        }

        for(i=0;i<n;i++)
        {
            cin>>str;
            graph[str[0]-'a'].push_back(str[str.length()-1]-'a');
            first[str[0]-'a']++;
            last[str[str.length()-1]-'a']++;
        }
        bool ans=false;
        int ta=0,tb=0;
        v=-1;
        for(i=0;i<26;i++)
        {
            if(first[i]==last[i])   ans=true;
            else if(first[i]==last[i]+1)    ans=true,v=i,ta++;
            else if(last[i]==first[i]+1)    ans=true,tb++;
            else
            {
                ans=false;
                break;
            }
        }

        if(v==-1)
        for(i=0;i<26;i++)
        {
            if(first[i]>0)
            {
                v=i;
                break;
            }
        }

        if(ans==false || ta!=tb || ta>1 || tb>1)    // odd degree walle 2 ho ya 0 ho
            NO;
        else
        {
          // char p=v+'a';
           // cout<<"qwerty\n"<<p<<"\n";
            dfs(v);
            for(i=0;i<26;i++)
                if((first[i]>0 || last[i]>0) && visit[i]==0)
                {
                //    p=i+'a';
                  //  cout<<p<<"\n";
                    ans=false;
                    break;
                }

            if(ans)     YES;
            else    NO;
        }
    }
    return 0;
}
