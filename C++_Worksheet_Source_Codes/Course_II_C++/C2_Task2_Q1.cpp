#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    float radius;

public:
    // Constructor to initialize radius in meters
    Circle(float r) {
        radius = r;
    }

    // Friend function to compare two Circle objects
    friend void compareTwoCircles(Circle cir1, Circle cir2);

    // Function to calculate the area of the circle in square meters
    float getArea() {
        return 3.14 * radius * radius;
    }
};

// Friend function definition
void compareTwoCircles(Circle cir1, Circle cir2) {
    float area1 = cir1.getArea();
    float area2 = cir2.getArea();

    cout << "Area of Circle 1: " << area1 << " square meters" << endl;
    cout << "Area of Circle 2: " << area2 << " square meters" << endl;

    if (area1 > area2) {
        cout << "Circle 1 has the larger area." << endl;
        cout<<endl;
    }
    else if (area2 > area1) {
        cout << "Circle 2 has the larger area." << endl;
        cout<<endl;
    }
    else {
        cout << "Both circles have the same area." << endl;
        cout<<endl;
    }
}

int main() {
    char choice;

    cout << "Let's calculate areas of the circles and compare them." << endl;
    cout << endl;

    do {
        float radius1, radius2;
        string unit1, unit2;

        // Get input for radius and unit for Circle 1
        cout << "Enter the radius for Circle 1: "<<endl;
        cin >> radius1;
        cout << "Enter the unit for Circle 1 (m or cm): "<<endl;
        cin >> unit1;

        // Convert radius1 to meters if the unit is cm
        if (unit1 == "cm" || unit1 == "CM") {
            radius1 /= 100;  // Convert cm to meters
        }

        // Get input for radius and unit for Circle 2
        cout << "Enter the radius for Circle 2: "<<endl;
        cin >> radius2;
        cout << "Enter the unit for Circle 2 (m or cm): "<<endl;
        cin >> unit2;

        // Convert radius2 to meters if the unit is cm
        if (unit2 == "cm" || unit2 == "CM") {
            radius2 /= 100;  // Convert cm to meters
        }

        // Create Circle objects
        Circle cir1(radius1);
        Circle cir2(radius2);

        // Comparing the two circles
        compareTwoCircles(cir1, cir2);

        // Ask if the user wants to do it again
        cout << "Do you want to enter new data? (Y/N): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout<<endl;
    cout<<"Thank you for calculating."<<endl;

    return 0;
}
