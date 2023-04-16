#include <iostream>
using namespace std;
#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// insert operation
void insert(int element) 
{
  if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) 
  {
    cout << "Error: Circular queue overflow\n";
    return;
  }
  if (front == -1 && rear == -1) 
  {
    front = rear = 0;
  } 

  else if (rear == MAX_SIZE - 1) 
  {
    rear = 0;
  } 

  else 
  {
    rear++;
  }
  circularQueue[rear] = element;
  cout << "Inserted element " << element << endl;
}

// delete operation
void remove() {
  if (front == -1 && rear == -1) 
  {
    cout << "Error: Circular queue underflow\n";
    return;
  }

  int element = circularQueue[front];
  if (front == rear) 
  {
    front = rear = -1;
  } 

  else if (front == MAX_SIZE - 1) 
  {
    front = 0;
  } 

  else 
  {
    front++;
  }
  cout << "Deleted element " << element << endl;
}

// display operation
void display() {
  if (front == -1) 
  {
    cout << "Circular queue is empty\n";
    return;
  }
  cout << "Circular queue elements: ";
  if (rear >= front) 
  {
    for (int i = front; i <= rear; i++) 
    {
      cout << circularQueue[i] << " ";
    }
  } 

  else 
  {
    for (int i = front; i < MAX_SIZE; i++) 
    {
      cout << circularQueue[i] << " ";
    }
    for (int i = 0; i <= rear; i++) 
    {
      cout << circularQueue[i] << " ";
    }
  }
  cout << endl;
}

// main function
int main() 
{
  int choice, element;

  do 
  {
    cout << "Enter 1 to insert, 2 to delete, 3 to display, 0 to exit: ";
    cin >> choice;

    switch (choice) 
    {
      case 1:
        cout << "Enter element to insert: ";
        cin >> element;
        insert(element);
        break;
      case 2:
        remove();
        break;
      case 3:
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