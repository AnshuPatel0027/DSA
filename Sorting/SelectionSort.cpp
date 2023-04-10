// ---------- Selection Sort without using function ----------

#include <iostream>
using namespace std;

int main()
{
    int n, min_idx;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for (int i = 0; i < n-1; i++) 
    {
       min_idx = i;
       for (int j = i+1; j < n; j++) 
       {
              if (arr[j] < arr[min_idx]) 
              {
                     min_idx = j;
              }
       }
       int temp = arr[i];
       arr[i] = arr[min_idx];
       arr[min_idx] = temp;
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}