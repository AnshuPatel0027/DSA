#include<iostream>
using namespace std;

int main()
{
    int n, arr[50], i, j, temp;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    cout<<"\nSorted Array: ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
