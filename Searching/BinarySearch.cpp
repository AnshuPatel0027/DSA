// ---------- Binary Search without using function ----------

#include <iostream>
using namespace std;

int main()
{
    int arr[50], n, i, search, first, last, middle;

       // taking size of array from user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

       // taking values in ascending order to store in array
    cout << "Enter " << n << " integers in ascending order: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

       // taking element input from user to search
    cout << "Enter the element to search: ";
    cin >> search;

    first = 0;
    last = n - 1;
    middle = (first+last)/2;


       // while loop 
    while (first <= last)
    {
        if (arr[middle] == search)
        {
              cout << search << " found at index " << middle+1 << endl;
              break;
        }
            
        else if (arr[middle] < search)
        {
              first = middle + 1;
        }
        else
        {
              last = middle - 1;
        }
            
        middle = (first + last)/2;
    }

    if (first > last)
        cout << "Element not found in the array." << endl;

    return 0;
}