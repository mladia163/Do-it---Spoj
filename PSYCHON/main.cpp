#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
#define ll  long long int
bool arr[3165];             // 0 means not prime & 1 means prime

void seive()
{
    int i,j,temp,k;
    memset(arr, 1, sizeof(arr));
    arr[0]=arr[1]=false;
    for(i=2;i<=3165;i++)
    {
        if(arr[i]==true)
        {
            j=2;
            k=i;
            while((temp=j*k)<=3165)
            {
                arr[temp]=false;
                ++j;
            }
        }
    }
    //f//or(i=0;i<3165;i++)
       // if(arr[i]==true)
       //     cout<<i<<" ";

}
/*
bool check_num_prime(int n)
{
    for(int i=3;i<3165;i++)
        if(arr[i]==true && i==n)
            return true;
    return false;
}
*/
bool chq_psycho(ll n)
{
    int even=0,odd=0,temp_power=0,i;

    /*while(n%2==0)
    {
        n/=2;
        temp_power+=1;
    }

    if(temp_power%2==0)
        even+=1;
    else
        odd+=1;
*/
    for(i=2;i<=sqrt(n);i++)
    {
       if(arr[i])
       {
        temp_power=0;

        while(n%i==0)
        {
            n/=i;
            temp_power+=1;
        }

        if(temp_power!=0) //&& arr[i])//check_num_prime(i))
        {
            if(temp_power%2==0)
                even+=1;
            else
                odd+=1;
        }
       }
    }

    if(n>2)
        odd+=1;

    if(even>odd)
        return true;
    else
        return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    seive();
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        //if(check_num_prime(n))
          //  cout<<"yes";
        //else
          //  cout<<"no";
        if(n==0 || n==1)
            printf("Ordinary Number\n");
        else if(chq_psycho(n))
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;
}
