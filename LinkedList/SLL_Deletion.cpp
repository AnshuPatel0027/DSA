#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void deleteFirst(Node** head_ref) {
    if (*head_ref == NULL) {
        cout << "Error: List is empty." << endl;
        return;
    }
   
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    delete temp;
}

void deleteBefore(Node** head_ref, int pos) {
    if (*head_ref == NULL || pos <= 1) {
        cout << "Error: Cannot delete before first node." << endl;
        return;
    }
   
    Node* prev = NULL;
    Node* current = *head_ref;
   
    for (int i = 1; current != NULL && i < pos - 1; i++) {
        prev = current;
        current = current->next;
    }
   
    if (current == NULL) {
        cout << "Error: Specified position is out of range." << endl;
        return;
    }
   
    if (prev == NULL) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }
   
    delete current;
}

void deleteAfter(Node** head_ref, int pos) {
    if (*head_ref == NULL) {
        cout << "Error: List is empty." << endl;
        return;
    }
   
    Node* current = *head_ref;
    Node* prev = NULL;
   
    for (int i = 1; current != NULL && i < pos; i++) {
        prev = current;
        current = current->next;
    }
   
    if (current == NULL || current->next == NULL) {
        cout << "Error: Specified position is out of range." << endl;
        return;
    }
   
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
   
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 7);
   
    cout << "Original list: ";
    printList(head);
   
    deleteFirst(&head);
    cout << "After deleting first node: ";
    printList(head);
   
    deleteBefore(&head, 3);
    cout << "After deleting node before position 3: ";
    printList(head);
   
    deleteAfter(&head, 1);
    cout << "After deleting node after position 1: ";
    printList(head);
   
    return 0;
}