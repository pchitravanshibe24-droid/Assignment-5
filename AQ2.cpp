#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    // (a) Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        cout << value << " inserted at beginning.\n";
    }

    // (b) Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at end.\n";
    }

    // (c) Insert before or after a node with given key
    void insertBefore(int key, int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) { // insert before head
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Key " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << value << " inserted before " << key << ".\n";
    }

    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Key " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << value << " inserted after " << key << ".\n";
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) { // only one node
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete specific node
    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Key " << key << " not found.\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        cout << key << " deleted.\n";
        delete delNode;
    }

    // (g) Search a node
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    // (h) Display list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, key;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert before " << key << ": ";
            cin >> value;
            list.insertBefore(key, value);
            break;
        case 4:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert after " << key << ": ";
            cin >> value;
            list.insertAfter(key, value);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
