#include <iostream>
using namespace std;

class TemperatureConverter {
private:
    double temperature=0;
    char choice;

public:
    void getConversionChoice() {
        cout << "What would you like to convert the temperature into?" << endl;
        cout << endl;
        cout << "1. Celsius (C)" << endl;
        cout << "2. Fahrenheit (F)" << endl;
        cout<<endl;
    }

    void getChoice(){
        cout << "(Enter C or F): ";
        cin >> choice;
        if (choice != 'C' && choice != 'c' && choice != 'f' && choice != 'F') {
            cout << "Invalid choice. Please enter 'C' or 'F'" << endl;
            getChoice();
        }
    }

    void getTemperature() {
    cout << "Enter the temperature value: ";
    while (!(cin >> temperature)) {
        cout << "That's not a number. Try again: "; //handling error like non-numeric inputs
        cin.clear();
        cin.ignore(1000, '\n');
    }
}


    void convertAndDisplay() {
        if (choice == 'C' || choice == 'c') {
            double celsius = (temperature - 32) * 5 / 9;
            cout << "Converted temperature: " << celsius << " degree Celsius" << endl;
        }
        if (choice == 'F' || choice == 'f') {
            double fahrenheit = (temperature * 9 / 5) + 32;
            cout << "Converted temperature: " << fahrenheit << " degree Fahrenheit" << endl;
        }

    }
};

int main() {
    char a;
    cout << "            WELCOME TO THE TEMPERATURE CONVERTER [F-C/C-F]      " << endl;
    cout<<endl;
    cout<<endl;


    do {
        TemperatureConverter converter;
        converter.getConversionChoice();
        converter.getChoice();
        converter.getTemperature();
        converter.convertAndDisplay();

        cout << "Do you want to continue? (Y/N): ";
        cin >> a;

        while (a != 'Y' && a != 'y' && a != 'N' && a != 'n') {
            cout << "Please enter 'Y' to continue or 'N' to exit: ";
            cin >> a;
            cout << endl;
        }

    } while (a == 'Y' || a == 'y');

    cout<<endl;
    cout << "Thank you for using us." << endl;
    return 0;
}
