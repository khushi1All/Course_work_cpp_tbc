#include <iostream>
using namespace std;

class DayOfWeek {

private:
    int day;
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

public:

// Function to get the input from the user
    void getInput() {
        while (true) {
            cout << "Enter a number between 1 and 7 to find the day of the week: " << endl;
            cin >> day;
            cout<<endl;

            // Check if the input is valid
            if (day >= 1 && day <= 7) {
                break;  // Exit the loop if valid input
            } else {
                cout << "Invalid input! Please enter a number between 1 and 7." << endl;
            }
        }
    }

// Function to print the day of the week using the array
    void printDay() {
        cout << "It is " << days[day - 1] << "!" << endl;
        cout<<"Have a great day!"<<endl;
    }
};

int main() {

    cout << "   Let's find day of the week using numbers:"<< endl;
    cout << endl;
    DayOfWeek WhichDay;

    WhichDay.getInput();
    WhichDay.printDay();

    return 0;
}
