#include <bits/stdc++.h>
using namespace std;
#define sd(a)   scanf("%d",&a)

int sim_s(int arr[],int x,int n)
{
    int h=n,l=0;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(x==arr[mid])
            return mid;
        else if(x>arr[mid])
            l=mid+1;
        else if(x<arr[mid])
            h=mid-1;
    }
    return -1;
}

int inorder[8001],preorder[8001],postorder[8001],temp[8001],k=0;
/*int sim_s(int arr[],int x,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
            return i;
    return -1;
}
*/
void print_post(int in[],int pre[],int n)
{
    int b=sim_s(in,pre[0],n);

    if(b!=0)
        print_post(in,pre+1,b);
    if(b!=(n-1))
        print_post(in+b+1,pre+b+1,n-b-1);
    temp[k++]=pre[0];
}

int main()
{
    int n,i;
    sd(n);

    for(i=0;i<n;i++)
        sd(preorder[i]);
    for(i=0;i<n;i++)
        sd(postorder[i]);
    for(i=0;i<n;i++)
        sd(inorder[i]);

//    int x;
//    cin>>x;
//    int temp = bin_s(preorder,x,0,n-1);
//    cout<<temp<<endl;
    print_post(inorder,preorder,n);
    bool ans=true;

    for(i=0;i<n;i++)
        if(temp[i]!=postorder[i])
        {
            ans=false;
            break;
        }

    if(ans)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
