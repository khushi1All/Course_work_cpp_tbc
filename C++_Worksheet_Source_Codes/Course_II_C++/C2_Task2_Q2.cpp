#include <iostream>
using namespace std;

class Maximum
{
private:
    float max;

public:
    // Finds max between two integers
    void findMax(int a, int b)
    {
        if (a > b)
        {
            max = a;
        }
        else
        {
            max = b;
        }
    }

    // Finds max between two floating-point numbers
    void findMax(float x, float y)
    {
        if (x > y)
        {
            max = x;
        }
        else
        {
            max = y;
        }

    }

    // Finds max among three integers
    void findMax(int a, int b, int c)
    {
        if (a > b && a > c)
        {
            max = a;
        }

        else if (b > c)
        {
            max = b;
        }
        else
        {
            max = c;
        }

    }

    // Finds max between an integer and a float
    void findMax(int a, float x)
    {
        if (a > x)
        {
            max = a;
        }

        else
        {
            max = x;
        }

    }

    // Displays the result
    void display()
    {
        cout << "The largest number is: " << max << endl;
    }
};

int main()
{
    char checkAgain; // Variable to store if the user wants to continue

    cout << "              Let's find maximum between/ among different types of number."<<endl;
    cout << endl;

    do {
        Maximum M;
        int choice;

        cout << "Choose an option: " <<endl;
        cout << "1. Max between two integers" <<endl;
        cout << "2. Max between two floating-point numbers" <<endl;
        cout << "3. Max among three integers" <<endl;
        cout << "4. Max between an integer and a float" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int a, b;
            cout << "Enter two integers: " ;
            cin >> a >> b;
            M.findMax(a, b);
            break;
        }
        case 2:
        {
            float x, y;
            cout << "Enter two floating-point numbers: ";
            cin >> x >> y;
            M.findMax(x, y);
            break;
        }
        case 3:
        {
            int a, b, c;
            cout << "Enter three integers: ";
            cin >> a >> b >> c;
            M.findMax(a, b, c);
            break;
        }
        case 4:
        {
            int a;
            float x;
            cout << "Enter an integer and a floating-point number: ";
            cin >> a >> x;
            M.findMax(a, x);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 0;
        }

        M.display();

        // Ask if the user wants to check again
        cout << "Do you want to check again? (Y/N): ";
        cin >> checkAgain;

        // Input validation
        while (checkAgain != 'Y' && checkAgain != 'y' && checkAgain != 'N' && checkAgain != 'n') {
            cout << "Invalid input! Please enter 'Y' to continue or 'N' to exit: ";
            cin >> checkAgain;
        }

    } while (checkAgain == 'Y' || checkAgain == 'y'); // Continue if user enters 'Y' or 'y'

    cout << endl;
    cout << "Thank you for using the maximum finder!" << endl;

    return 0;
}
