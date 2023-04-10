// ---------- Linear Search without using function ----------

#include <iostream>
using namespace std;

int main()
{
    int n, searchElement;

       // taking size of array from user 
    cout << "Enter the size of array: ";
    cin >> n;

       // declaring array with size of n
    int arr[n];  

       // taking values from user to store in array 
    cout << "Enter " << n << " elements: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

       // taking element from user to search it from the array
    cout << "Enter the search element: ";
    cin >> searchElement;

    int flag = 0;

       // for loop to check if searchelement is in array or not
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == searchElement)
        {
            flag = 1;
            cout << searchElement << " found at position " << i << endl;
            break;
        }
    }

    if(flag == 0)
    {
        cout << searchElement << " is not found in the array." << endl;
    }

    return 0;
}