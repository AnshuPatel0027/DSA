#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Function to insert a node at the front of the linked list
void insertAtFront(Node*& head, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert a node such that linked list is in ascending order
void insertInAscendingOrder(Node*& head, int data)
{
    Node* newNode = new Node;
    newNode->data = data;

    if (head == NULL || head->data >= data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }

    cout << "Linked list: ";
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// main function
int main()
{
    Node* head = NULL;

    // Inserting nodes at the front
    insertAtFront(head, 4);
    insertAtFront(head, 2);
    insertAtFront(head, 1);
    displayList(head);

    // Inserting nodes at the end
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    displayList(head);

    // Inserting nodes in ascending order
    insertInAscendingOrder(head, 3);
    displayList(head);

    return 0;
}
