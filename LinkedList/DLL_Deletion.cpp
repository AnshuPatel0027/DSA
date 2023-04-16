#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void deleteLast() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            size--;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        size--;
    }

    void deleteBeforePosition(int pos) {
        if (pos < 2 || pos > size) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 2) {
            Node* temp = head->next;
            delete head;
            head = temp;
            head->prev = NULL;
            size--;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* del = temp->prev;
        temp->prev = del->prev;
        del->prev->next = temp;
        delete del;
        size--;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.addNode(1);
    dll.addNode(2);
    dll.addNode(3);
    dll.addNode(4);
    dll.addNode(5);
    cout << "Original list: ";
    dll.displayList();
    dll.deleteLast();
    cout << "List after deleting last node: ";
    dll.displayList();
    dll.deleteBeforePosition(2);
    cout << "List after deleting node before position 2: ";
    dll.displayList();
    return 0;
}