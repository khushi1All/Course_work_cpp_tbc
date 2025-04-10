#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>  // To throw exceptions for invalid marks
using namespace std;

// Function to read student records from a text file
void readStudentRecords(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Oops! The student records file couldn't be opened. Please try again!" << endl;
        return;
    }

    int roll;
    char name[50];
    float marks;

    cout << endl;
    cout << "Displaying the student records:" << endl;
    cout << endl;
    while (file >> roll >> name >> marks) {
        cout << "Roll No: " << roll << endl << "Name: " << name << endl << "Marks: " << marks << endl;
        cout << endl;
    }

    file.close();
}

// Function to add a new student record with validation
void addStudentRecord(const char* filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Oops! We could not open the file to save the record. Please try again!" << endl;
        return;
    }

    int roll;
    char name[50];
    float marks;

    cout << "Let's add a new student record!" << endl;
    cout << endl;

    // Taking the roll number
    cout << "Enter the roll number of the student: ";
    cin >> roll;
    cout << "Enter the name of the student: ";
    cin.ignore();  // To clear any leftover input from the buffer
    cin.getline(name, 50);

    while (true) {
        cout << "Enter marks (between 0 and 100): ";
        cin >> marks;

        try {
            // Check if marks are valid (between 0 and 100)
            if (marks < 0 || marks > 100) {
                throw out_of_range("Marks must be between 0 and 100!");
            }
            break; // Marks are valid, exit the loop
        } catch (const out_of_range& e) {
            cout << e.what() << endl; // Show the exception message
        }
    }

    file << roll << " " << name << " " << marks << endl;
    file.close();

    cout << "Student record has been successfully added!" << endl;
    cout << endl;
}

// Main function
int main() {
    const char* studentFilename = "students.txt";  // Student records file

    int choice;
    do {
        cout << "           STUDENT RECORD MANAGEMENT" << endl;
        cout << endl;
        cout << "1. Display student records" << endl;
        cout << endl;
        cout << "2. Add a new student record" << endl;
        cout << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readStudentRecords(studentFilename);
                break;
            case 2:
                addStudentRecord(studentFilename);
                break;
            case 3:
                cout << "Exiting the program. Have a great day!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);

    return 0;
}


