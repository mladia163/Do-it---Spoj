#include <bits/stdc++.h>
using namespace std;

int binary_pivoted(int a[],int n,int x)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x==a[mid])
            return mid;
        else if(a[low]<=a[mid])     // left half is sorted
        {
            if(x>=a[low] && x<a[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else                        // right half sorted
        {
            if(x>a[mid] && x<=a[high])      // checks if element if in the sorted list
                low=mid+1;
            else                            // if not present in the sorted which we considering
                high=mid-1;                 // just rejects that sub-array
        }
    }
    return -1;
}

int main()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int arr_size = sizeof(arr1)/sizeof(arr1[0]);
    int no = 3;
    printf("Index of the element is %d\n",binary_pivoted(arr1,arr_size,no));
    return 0;
}
