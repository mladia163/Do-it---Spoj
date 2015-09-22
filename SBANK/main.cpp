    #include <iostream>
    #include <set>
    #include <map>
    #include <string>
    #include <cstdio>
    using namespace std;

    int main()
    {
        int t1;
        scanf("%d",&t1);
        map<string, int> t;
        map<string, int> :: iterator it;
        while(t1--)
        {
            t.clear();
            string str;
            int n,i;
            scanf("%d\n",&n);
            for(i=0;i<n;i++)
            {
                gets(str);
                t[str]++;
            }
            for(it=t.begin();it!=t.end();it++)
                printf("%s %d\n",it->first.c_str(),it->second);
            printf("\n");
        }
        return 0;
    }
