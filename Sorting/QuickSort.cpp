#include <iostream>
using namespace std;

// quickSort function
void quickSort(int arr[], int left, int right) 
{
    int i = left, j = right, temp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) 
    {
        while (arr[i] < pivot)
        {
              i++;
        }
        while (arr[j] > pivot)
        {
              j--;
        }

        if (i <= j) 
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
    {
       quickSort(arr, left, j);
    }
    if (i < right)
    {
       quickSort(arr, i, right);
    }
}

// main function 
int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "The sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}