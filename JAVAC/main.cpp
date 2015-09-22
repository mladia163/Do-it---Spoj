#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
#define FOR(i,n)    for(i=0;i<n;i++)
int main()
{
    char str[100];
    int len;
    while(scanf("%s",str)!=EOF)
    {
        int i;
        len=strlen(str);
            bool j,c;
            j=c=true;
            if(!islower(str[0]))
                j=c=false;
            FOR(i,len)
            {
                if(!isalpha(str[i]))
                    j=false;
                if(str[i]=='_')
                {
                    if(!islower(str[i+1]))
                        c=false;
                }
                else if(isupper(str[i]))
                    c=false;
            }
            if(!j && !c)
            {
                cout<<"Error!"<<endl;
                continue;
            }
            else if(j&&c)
            {
                cout<<str<<endl;
                continue;
            }
            if(c)
            {
                FOR(i,len)
                    if(str[i]=='_')
                    {
                        if(islower(str[++i]))
                            printf("%c",toupper(str[i]));
                    }
                    else
                        printf("%c",str[i]);
                c=0;
                cout<<endl;
            }
            else
            {
                FOR(i,len)
                    if(!isupper(str[i]))
                        printf("%c",str[i]);
                    else
                    {
                        printf("_");
                        printf("%c",tolower(str[i]));
                    }
                cout<<endl;
            }
    }
    return 0;
}
