#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int regNum;
    string color;

public:
    void inputDetails() {
        cout << "Enter the registration number: ";
        cin >> regNum;
        cout << "Enter the color: ";
        cin >> color;
    }

    void displayDetails() {
        cout << "Registration Number: " << regNum << endl;
        cout << "Color: " << color << endl;
    }

    void writeToFile() {
        // Vehicle specific details
        ofstream file("vehicle.txt", ios::app);
        file << "----Vehicle Details----" << endl;
        file << "Registration Number: " << regNum << endl;
        file << "Color: " << color << endl;
        file << "----------------------" << endl;
        file.close();
    }
};

// Derived class Car
class Car : public Vehicle {
    int seats;

public:
    void inputCarDetails() {
        inputDetails();
        cout << "Enter the number of seats in the car: ";
        cin >> seats;
    }

    void displayCarDetails() {
        displayDetails();
        cout << "Number of Seats: " << seats << endl;
    }

    void writeToFile() {
        // Car specific details
        ofstream file("vehicle.txt", ios::app);
        file << "----Car Details----" << endl;
        file << "Registration Number: " << regNum << endl;
        file << "Color: " << color << endl;
        file << "Number of Seats: " << seats << endl;
        file << "-------------------" << endl;
        file.close();
    }
};

// Derived class Bike
class Bike : public Vehicle {
    int engineCapacity;

public:
    void inputBikeDetails() {
        inputDetails();
        cout << "Enter the engine capacity of the bike: ";
        cin >> engineCapacity;
    }

    void displayBikeDetails() {
        displayDetails();
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }

    void writeToFile() {
        // Bike specific details
        ofstream file("vehicle.txt", ios::app);
        file << "----Bike Details----" << endl;
        file << "Registration Number: " << regNum << endl;
        file << "Color: " << color << endl;
        file << "Engine Capacity: " << engineCapacity << " cc" << endl;
        file << "--------------------" << endl;
        file.close();
    }
};

int main() {
    Car car;
    cout << "Enter details of the car:" << endl;
    cout << endl;
    car.inputCarDetails();

    cout << endl << "Car details:" << endl;
    car.displayCarDetails();
    car.writeToFile(); // Call Car's own writeToFile

    cout << endl << "=============================" << endl << endl;

    Bike bike;
    cout << "Enter details of the bike:" << endl;
    cout << endl;
    bike.inputBikeDetails();
    cout << endl << "Bike details:" << endl;
    bike.displayBikeDetails();
    bike.writeToFile(); // Call Bike's own writeToFile

    cout << endl << "Details saved successfully in 'vehicle.txt'" << endl;

    return 0;
}
