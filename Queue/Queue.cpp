#include <iostream>
#define MAX_SIZE 100
using namespace std;

int queue[MAX_SIZE];
int front = -1, rear = -1;

// insert function 
void insert(int element) 
{
  if (rear >= MAX_SIZE - 1) 
  {
    cout << "Error: queue overflow\n";
    return;
  }
  if (front == -1)
    front = 0;
  rear++;
  queue[rear] = element;
  cout << "Inserted element " << element << " into the queue\n";
}

// delete function 
void delete_element() 
{
  if (front == -1 || front > rear) 
  {
    cout << "Error: queue underflow\n";
    return;
  }
  int element = queue[front];
  front++;
  cout << "Deleted element " << element << " from the queue\n";
}

// display function
void display() 
{
  if (front == -1 || front > rear) 
  {
    cout << "Queue is empty\n";
    return;
  }
  cout << "Queue contents: ";
  for (int i = front; i <= rear; i++) {
    cout << queue[i] << " ";
  }
  cout << endl;
}

int main() 
{
  int choice, element;

  do 
  {
    cout << "Enter 2 to insert, 3 to delete, 5 to display, 0 to exit: ";
    cin >> choice;

    switch (choice) 
    {
      case 2:
        cout << "Enter element to insert: ";
        cin >> element;
        insert(element);
        break;
      case 3:
        delete_element();
        break;
      case 5:
        display();
        break;
      case 0:
        cout << "Exiting program\n";
        break;
      default:
        cout << "Invalid choice\n";
    }
  } while (choice != 0);

  return 0;
}
