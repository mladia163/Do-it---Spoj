#include <iostream>
#include <string.h>
using namespace std;
char s[21];
int main()
{
    int i,a,b,c,len;
    cin>>s;
    len=strlen(s);
    a=1 , b=1;
    for(i=2;i<=len;i++)
    {
        c=b;
        if( ((s[i-2]-'0')*10 + (s[i-1]-'0'))<=20 && s[i-2]!='0' )
            c=c+a;
        a=b , b=c;
    }
    cout<<c<<endl;
    return 0;
}
