#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int partitions(int arr[],int start,int last)
{
    int pivot = arr[last];
    int p_index = start;

    for(int i=start;i < last;i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[p_index],arr[i]);
            p_index++;
        }
    }
    swap(arr[p_index],arr[last]);

    return p_index;

}

void quick_sort(int arr[],int low,int high)
{

    if(low < high)
    {
        int piv= partitions(arr,low,high);

        quick_sort(arr, low, piv-1);
        quick_sort(arr, piv+1,high);
    }

}


int main()
{
    int n;
    cout<<"Number of elements ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    quick_sort(arr,0,n-1);
    display(arr,n);
}
