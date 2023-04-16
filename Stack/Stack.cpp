#include <iostream>
#define MAX_SIZE 100
using namespace std;

int stack[MAX_SIZE];
int top = -1;

// push function 
void push(int element) 
{
  if (top >= MAX_SIZE - 1) 
  {
    cout << "Error: stack overflow\n";
    return;
  }
  top++;
  stack[top] = element;
  cout << "Pushed element " << element << " into the stack\n";
}

// pop function 
void pop() 
{
  if (top < 0) 
  {
    cout << "Error: stack underflow\n";
    return;
  }
  int element = stack[top];
  top--;
  cout << "Popped element " << element << " from the stack\n";
}

// peek function
void peek() 
{
  if (top < 0) 
  {
    cout << "Error: stack is empty\n";
    return;
  }
  int element = stack[top];
  cout << "Top element in stack is " << element << endl;
}

// change function 
void change() 
{
  if (top < 0) 
  {
    cout << "Error: stack is empty\n";
    return;
  }
  int element;
  cout << "Enter new value: ";
  cin >> element;
  stack[top] = element;
  cout << "Changed top element to " << element << endl;
}

// display function
void display() 
{
  if (top < 0) 
  {
    cout << "Stack is empty\n";
    return;
  }
  cout << "Stack contents: ";
  for (int i = top; i >= 0; i--) {
    cout << stack[i] << " ";
  }
  cout << endl;
}

// peep function
void peep() 
{
  if (top < 0) 
  {
    cout << "Error: stack is empty\n";
    return;
  }
  int index;
  cout << "Enter index to peep (0-" << top << "): ";
  cin >> index;
  if (index < 0 || index > top) 
  {
    cout << "Error: invalid index\n";
    return;
  }
  int element = stack[index];
  cout << "Element at index " << index << " is " << element << endl;
}

// main function
int main() 
{
  int choice, element;

  do 
  {
    cout << "Enter 1 to push, 2 to pop, 3 to peek, 4 to change, 5 to display, 6 to peep, 0 to exit: ";
    cin >> choice;

    switch (choice) 
    {
      case 1:
        cout << "Enter element to push: ";
        cin >> element;
        push(element);
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        change();
        break;
      case 5:
        display();
        break;
      case 6:
        peep();
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
