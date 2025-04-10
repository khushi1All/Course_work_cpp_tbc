#include <iostream>
using namespace std;

class BouncyNumber {

private:
    string num;

public:

    void getInput() {
        cout << "Enter a number of your liking: ";
        cin >> num;
    }


    void checkBouncy() {
        bool a = false, b = false;
        int length = num.length();

        // Loop through the digits of the number
        for (int i = 0; i < length - 1; i++) {
            if (num[i] > num[i + 1]) {
                a = true; // The number is decreasing
            }
            else if (num[i] < num[i + 1]) {
                b = true; // The number is increasing
            }
        }

        // If the number is both increasing and decreasing, it's a bouncy number
        if (a && b) {
            cout << "The number is a bouncy number." << endl;
        }
        else {
            cout << "The number is NOT a bouncy number." << endl;
        }
    }
};

int main() {
    char checkAgain; // Variable to store if user wants to check another number
     cout << "                       BOUNCY NUMBER OR NOT? LET'S CHECK." << endl;
     cout << endl;


    do {

        BouncyNumber bn;
        bn.getInput();
        bn.checkBouncy();

        // Ask the user if they want to check another number
        cout << "Do you want to check another number? (Y/N): "<<endl;
        cin >> checkAgain;

        // Input validation for 'Y' or 'N'
        while (checkAgain != 'Y' && checkAgain != 'y' && checkAgain != 'N' && checkAgain != 'n') {
            cout << "Invalid input! Please enter 'Y' to check another number or 'N' to exit: ";
            cin >> checkAgain;
            cout<<endl;
        }

    } while (checkAgain == 'Y' || checkAgain == 'y'); // Keep checking if user wants to check again

    cout << "Thank you for checking the bouncy number!" << endl;

    return 0;
}
