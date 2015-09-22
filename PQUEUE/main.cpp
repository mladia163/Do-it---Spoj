#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    queue<int> pos;
    queue<int> val;
    priority_queue<int> max_val;
    while(t--)
    {
        int ans=0,m,n,i,temp;
        cin>>n>>m;

        for(i=0;i<n;i++)
        {
            pos.push(i);
            cin>>temp;
            val.push(temp);
            max_val.push(temp);
        }
        bool tt=true;
        while(tt)
        {
            while(max_val.top()!=val.front())
            {
                temp = val.front();
                val.pop();
                val.push(temp);
                temp = pos.front();
                pos.pop();
                pos.push(temp);
            }
            ++ans;
            if(pos.front()==m)
            {
                cout<<ans<<endl;
                break;
            }
            else
            {
                pos.pop();
                val.pop();
                max_val.pop();
            }
        }
        while(!pos.empty())
            pos.pop();
        while(!val.empty())
            val.pop();
        while(!max_val.empty())
            max_val.pop();
    }
    return 0;
}
