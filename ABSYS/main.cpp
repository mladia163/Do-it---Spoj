#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s1[20],s2[20],s3[20];
        //char a_[20],b_[20],c_[20];
        int k_a=0,k_b=0,k_c=0,i,a=0,b=0,c=0,temp;
        scanf("%s + %s = %s",s1,s2,s3);
        //cout<<s1<<s2<<s3;
        for(i=0;i<strlen(s1);i++)
        {
            a=(a*10)+(s1[i]-'0');
            if(isalpha(s1[i]))
            {
                k_a=1;
                break;
            }
        }
        for(i=0;i<strlen(s2);i++)
        {
            b=(b*10)+(s2[i]-'0');
            if(isalpha(s2[i]))
            {
                k_b=1;
                break;
            }
        }
        for(i=0;i<strlen(s3);i++)
        {
            c=(c*10)+(s3[i]-'0');
            if(isalpha(s3[i]))
            {
                k_c=1;
                break;
            }
        }
        if(k_c==1)
            c=a+b;
        else if(k_a==1)
            a=c-b;
        else if(k_b==1)
            b=c-a;

        cout<<a<<" + "<<b<<" = "<<c<<endl<<endl;

    }
    return 0;
}
