#include <iostream>
using namespace std;

const int limit = 10;
int queue[limit];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == limit - 1;
}

void enqueue() {
    if (isFull()) {
        cout << "Queue is full." << endl;
        return;
    }
    int num;
    cout << "Enter number to enqueue: ";
    cin >> num;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = num;
    cout << num << " added to the queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << queue[front] << " removed from the queue." << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void reverseFirstK() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    int k;
    cout << "Enter value of K: ";
    cin >> k;

    // Edge case: Handle invalid K values (zero or negative)
    if (k <= 0) {
        cout << "Invalid K value. It must be greater than 0." << endl;
        return;
    }

    if (k > (rear - front + 1)) {
        cout << "Not enough elements in queue." << endl;
        return;
    }

    int temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = queue[front + i];
    }
    for (int i = 0; i < k; i++) {
        queue[front + i] = temp[k - i - 1];
    }
    cout << "First " << k << " elements reversed." << endl;
}

void interleaveQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    int total = rear - front + 1;
    if (total % 2 != 0) {
        cout << "Queue does not have even number of elements to interleave." << endl;
        return;
    }

    int mid = total / 2;
    int temp[limit];
    int index = 0;
    int first = front;
    int second = front + mid;

    while (first < front + mid && second <= rear) {
        temp[index++] = queue[first++];
        temp[index++] = queue[second++];
    }

    for (int i = 0; i < index; i++) {
        queue[front + i] = temp[i];
    }

    cout << "Queue interleaved successfully." << endl;
}

int main() {
    int choice;

    cout << "Let's implement a queue using arrays" << endl;
    cout << endl;

    do {
        cout << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Reverse first K elements" << endl;
        cout << "5. Interleave queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                reverseFirstK();
                break;
            case 5:
                interleaveQueue();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
