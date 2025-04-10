#include <iostream>
using namespace std;

const int maxSize = 10;
int stackArr[maxSize];
int top = -1;

void pushElement() {
    if (top == maxSize - 1) {
        cout << "Stack is full." << endl;
    }
    else {
        int value;
        cout << "Enter element to push: ";
        cin >> value;
        stackArr[++top] = value;
        cout << value << " has been pushed to the stack." << endl;
        cout << endl;
    }
}

void popElement() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << stackArr[top] << " has been popped from the stack." << endl;
        cout << endl;
        top--;
    }
}

void findMiddleElement() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    }
    else {
        int middleIndex = top / 2;
        cout << "Middle element is: " << stackArr[middleIndex] << endl;
    }
}

void reverseBottomHalf() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    int mid = (top + 1) / 2;
    for (int i = 0; i < mid / 2; ++i) {
        int temp = stackArr[i];
        stackArr[i] = stackArr[mid - i - 1];
        stackArr[mid - i - 1] = temp;
    }
    cout << "Bottom half of the stack has been reversed." << endl;
}

void displayStack() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        cout << endl;
    }
     else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; --i) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Lets implement a stack using arrays" << endl << endl;
    cout << "1. Push Element" << endl;
    cout << "2. Pop Element" << endl;
    cout << "3. Find Middle Element" << endl;
    cout << "4. Reverse Bottom Half" << endl;
    cout << "5. Display Stack" << endl;
    cout << "6. Exit" << endl << endl;

    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pushElement();
                break;
            case 2:
                popElement();
                break;
            case 3:
                findMiddleElement();
                break;
            case 4:
                reverseBottomHalf();
                break;
            case 5:
                displayStack();
                break;
            case 6:
                cout << endl;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
