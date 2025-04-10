#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}  // Improved initialization
};

class LinkedList {
private:
    Node* head;

    void clearList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clearList();
    }

    // Prevent accidental copying
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Insert operations
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at start." << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            cout << value << " inserted at end." << endl;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        cout << value << " inserted at end." << endl;
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 1) {
            insertAtStart(value);
            return;
        }

        Node* current = head;
        for (int i = 1; current && i < pos-1; ++i) {
            current = current->next;
        }

        if (!current) {
            cout << "Position out of range." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;

        cout << value << " inserted at position " << pos << "." << endl;
    }

    // Loop handling
    void detectAndRemoveLoop() {
        if (!head) return;

        Node *slow = head, *fast = head;
        bool loopExists = false;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                loopExists = true;
                break;
            }
        }

        if (!loopExists) {
            cout << "No loop detected." << endl;
            return;
        }

        // Find loop start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Find last node in loop
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = nullptr;

        cout << "Loop removed." << endl;
    }

    // Nth from end
    int findNthFromEnd(int n) {
        if (n <= 0 || !head) return -1;

        Node *first = head, *second = head;
        for (int i = 0; i < n; ++i) {
            if (!second) return -1;  // List has fewer than n nodes
            second = second->next;
        }

        while (second) {
            first = first->next;
            second = second->next;
        }

        return first->data;  // Return nth node from end
    }

    // Reverse in groups
    void reverseInGroups(int k) {
        head = reverseGroup(head, k);
        cout << "List reversed in groups of " << k << " nodes." << endl;
    }

private:
    Node* reverseGroup(Node* node, int k) {
        Node *current = node, *prev = nullptr, *next = nullptr;
        int count = 0;

        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            node->next = reverseGroup(next, k);
        }

        return prev;  // Return new head of reversed group
    }

public:
    // Display
    void display() const {
        Node* current = head;

        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List: ";

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;  // End of list display
    }
};

// Simplified menu
int main() {
    LinkedList list;

    int choice, value, position, k;

    while (true) {
        cout << "\n----- Linked List Menu -----" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Detect and Remove Loop" << endl;
        cout << "5. Find Nth Node from End" << endl;
        cout << "6. Reverse in Groups of K" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> value;
                list.insertAtStart(value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                list.detectAndRemoveLoop();
                break;

            case 5:
                cout << "Enter the position from end: ";
                cin >> position;
                if (list.findNthFromEnd(position) != -1) {
                    cout << "The " << position << "th node from the end is: " << list.findNthFromEnd(position) << endl;
                } else {
                    cout << "The list has fewer than " << position << " nodes." << endl;
                }
                break;

            case 6:
                cout << "Enter the group size (K): ";
                cin >> k;
                list.reverseInGroups(k);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
