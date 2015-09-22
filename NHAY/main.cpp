#include <bits/stdc++.h>
using namespace std;



#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <unistd.h>

using namespace std;

int *v;

void table(string p){

    //v[i] :where to go(what to compare next) if mismatch occur at i
    v[0]=0;  //obviously we'll stay at zero only even if its a mismatch
    v[1]=0;  //just think naturally where will u go if mismatch occur at 1

    int cur=0;
    int length = p.size();
    for(int j=2;j<length;j++){
        /*
        This is the case for mismatch : if mismatch occur at j we seek to find the first
        occurence of p[j-1] in the pattern such that the sequence preceding j-1(0...j-2)
        locations have already been matched
        */
        while(cur!=0 && p[cur]!=p[j-1])
            cur=v[cur];

        if(p[cur]==p[j-1]) //Case for match:length of prematched sequence increments by 1
            cur=cur+1;

        v[j]=cur;
    }

}

void kmp(string pattern, string text){

    table(pattern);
    int cur=0; //cur: All locations before cur have been matched.
    int length_text = text.size();
    int length_pattern = pattern.size();
    int flag = 0, j=0;
    while(j<length_text){
        /*
        Key points:
        1. Mismatch occurs at cur.
        2. Suppose anand is compared with ananandnd.
        3. Mismatch occur at a i.e. cur=4.  anand.
        4. But we shift as above v[cur]=2(and it matches 'a').So now we only compare and.
        5. We have saved our work of starting from beginning.
        6. This was luckily the longest possible one.In general,we try to save even the
        the smaller amount of work unitl we reach index 0 in the pattern.
        */
        while(cur>0 && pattern[cur]!=text[j])
            cur = v[cur];

        if(pattern[cur]==text[j]){
            cur++;
            if(cur==length_pattern){
                //if all all locations before index p.size() have been matched
                cout << j- length_pattern +1<< endl;
                cur--;
                cur = v[cur];
                flag = 1;
                j--;
            }
        }
        j++;
    }
}

int main(){

    int length;
    scanf("%d", &length);
    while(1){
        v = new int[length+2];
        string text, pattern;
        cin >> pattern >> text;
        kmp(pattern, text);//all the indexes are printed now
        if(scanf("%d", &length)==1){
            //there are more cases
            cout << endl;//for the separating line, between the test cases
        }
        else{
            break;
        }
    }

    return 0;
}


/*
//int length;
//string pattern,text;
void LPS(int lps[],string p)
{
    int len=0,i=1;  // len for longest prefix suffix
    lps[0]=0;       // always 0 initially

    while(i<p.length())
    {
        if(p[i]==p[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)              // if not equal and also we have to put back the len to 0
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP(string pat,string text)
{
    int lps[pat.length()],j=0,i=0,brk_point=-1;
    LPS(lps,pat);

    while(i<text.length())
    {
        if(pat[j]==text[i])
            i++,j++;
        if(j==pat.length())
        {
            cout<<i-j<<endl;
            brk_point=1;
            j=lps[j-1];
        }
        else if(i<text.length() && pat[j]!=text[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    //return brk_point;
}

int main()
{
    int length;
    scanf("%d", &length);
    while(1)
    {
        string text, pattern;
        cin >> pattern >> text;
        KMP(pattern, text);//all the indexes are printed now
        if(scanf("%d", &length)==1)
            cout << endl;
        else
            break;
    }
    return 0;
}




int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int length;
    string pattern,text;
    cin>>length;

    while(1)
    {
        int pp=0;
        cin>>pattern>>text;
        pp=KMP(pattern,text);
        //if(scanf("%d",&length)==1)
          //  cout<<endl;
        if(pp==-1)
            cout<<endl;
        cin>>length;
    }

    return 0;
}
*/
