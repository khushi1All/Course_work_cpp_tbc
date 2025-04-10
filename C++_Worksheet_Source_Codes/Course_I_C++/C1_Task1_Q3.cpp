#include <iostream>
using namespace std;

class Array {
private:
    int s;
    int temp;
    int arr[100];  // Fixed-size array to hold the elements (assuming max 100 elements)

public:

    // Function to get input from the user
   void getInput() {
    cout << "Enter the number of elements in your array: ";
    while (!(cin >> s) || s <= 0 || s > 100) {
        cout << "Invalid input! Please enter a number between 1 and 100: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter the elements of your array:" << endl;
    for (int i = 0; i < s; i++) {
        cout << "Element " << i + 1 << ": ";
        while (!(cin >> arr[i])) {
            cout << "Invalid input! Please enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}


    // Function to sort the array in ascending order
    void sortArray() {
        for (int i = 0; i < s - 1; i++) {
            for (int j = i + 1; j < s; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Function to display the sorted array
    void display() {
        cout << "The sorted array in ascending order: ";
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";  // Print each element of the array
        }
        cout << endl << endl;
    }
};

int main() {
char want;
cout<<"        LET'S SORT OUT YOUR ARRAY IN ASCENDING ORDER."<<endl;
cout<<endl;
cout<<endl;
do{
    Array sorter;
    sorter.getInput();
    sorter.sortArray();
    sorter.display();

    cout << "Do you want to sort another set of arrays? (Y/N): ";
    cin >> want;
    while (want != 'Y' && want != 'y' && want != 'N' && want != 'n') {
            cout << "Invalid input! Please enter 'Y' to play again or 'N' to exit: ";
            cin >> want;
        }

    } while (want == 'Y' || want == 'y');

    cout<<endl;
    cout << "Thank you for choosing us!" << endl;

    return 0;
}


