#include <iostream>
using namespace std;

class Student {
private:
    string name;
    string subjects[3];
    int marks[3];

public:
    // Function to get student details
    void getDetails() {
        cout << "Enter your name: " << endl;
        getline(cin, name);  // Use getline to capture full name (I took help from AI to get full name)

        for (int i = 0; i < 3; i++) {
            cout << "Enter name of subject " << i + 1 << ": " << endl;
            cin >> subjects[i];

            // Handle invalid input for marks
            cout << "Enter marks for " << subjects[i] << " (0-100): " << endl;
            while (true) {
                cin >> marks[i];
                if (marks[i] >= 0 && marks[i] <= 100) {
                    break;
                }
                else {
                    cout << "Oops! Invalid mark. Enter a valid mark (0-100): " << endl;
                }
            }
        }
    }

    // Function to calculate total marks
    int getTotal() {
        return marks[0] + marks[1] + marks[2];
    }

    // Function to calculate average
    float getAverage() {
        return getTotal() / 3.0;      //float division
    }

    // Function to get grade
    char getGrade() {
        float avg = getAverage();

        if (avg >= 90){
            return 'A';
            }
        else if (avg >= 80){
            return 'B';
            }
        else if (avg >= 70){
            return 'C';
            }
        else if (avg >= 60){
            return 'D';
            }
        else {
            return 'F';
            }
    }

    // Function to display report
    void showReport() {
        cout << "           Student Report" << endl;
        cout << endl;
        cout << "Name: " << name << endl;

        // Print subject names and corresponding marks
        for (int i = 0; i < 3; i++) {
            cout << subjects[i] << ": " << marks[i] << endl;
        }

        // Display total, average, and grade
        cout << "Total Marks: " << getTotal() << "/300" << endl;
        cout << "Average: " << getAverage() << "%" << endl;
        cout << "Grade: " << getGrade() << endl;

        // Provide feedback based on the grade
        if (getGrade() == 'A') {
            cout << "Amazing! You're a star! Keep it up!" << endl;
        } else if (getGrade() == 'B' || getGrade() == 'C') {
            cout << "Good job! Keep pushing forward!" << endl;
        } else {
            cout << "Don't give up! You can do it!" << endl;
        }
    }
};

int main() {
    Student s;
    s.getDetails();
    s.showReport();

    return 0;
}
