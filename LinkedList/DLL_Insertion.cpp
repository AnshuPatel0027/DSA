#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtFront(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void insertAtEnd(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 6);
    insertAtFront(&head, 3);
    insertAtEnd(&head, 9);
    insertAtFront(&head, 1);
    insertAtEnd(&head, 11);
    insertAtFront(&head, 4);
    insertAtEnd(&head, 14);
    printList(head);
    return 0;
}