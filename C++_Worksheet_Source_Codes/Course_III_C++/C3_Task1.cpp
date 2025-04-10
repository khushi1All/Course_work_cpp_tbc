#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute;

public:
    Time() {
        hour = minute = 0;
    }

    Time(int h, int m) {
        hour = h;
        minute = m;
    }

    // Overloading + operator to add two Time objects
    Time operator+(Time T) {
        Time temp;
        temp.minute = minute + T.minute;
        temp.hour = hour + T.hour + (temp.minute / 60);
        temp.minute %= 60;

        if (temp.hour > 24) {
            cout << "Time exceeded 24 hours! Resetting to 23:59." << endl;
            temp.hour = 23;
            temp.minute = 59;
        }
        return temp;
    }

    // Overloading > operator to compare two Time objects
    bool operator>(Time T) {
        return (hour > T.hour) || (hour == T.hour && minute > T.minute);
    }

    // Overloading < operator to compare two Time objects
    bool operator<(Time T) {
        return (hour < T.hour) || (hour == T.hour && minute < T.minute);
    }

    void display() {
        cout << hour << " hours " << minute << " minutes" << endl;
    }
};


int main() {
    int h1, m1, h2, m2;
    cout<<"           ADD TWO TIMES FROM USER AND COMPARE THEM."<<endl;
    cout<<endl;

    try {
        cout << "Enter first time (hours minutes): "<<endl;
        cin >> h1 >> m1;
        if (h1 > 24 || m1 >= 60) {
            throw("Invalid time! Hours should be <= 24 and minutes should be < 60.");
        }

        cout << "Enter second time (hours minutes): "<<endl;
        cin >> h2 >> m2;
        if (h2 > 24 || m2 >= 60) {
            throw("Invalid time! Hours should be <= 24 and minutes should be < 60.");
        }

        Time T1(h1, m1), T2(h2, m2);

        cout << "First time: ";
        T1.display();
        cout << "Second time: ";
        T2.display();

        Time T3 = T1 + T2;
        cout << "Sum of times: ";
        T3.display();

        if (T1 > T2){
            cout << "First time is greater." << endl;
        }
        else if (T1 < T2){
            cout << "Second time is greater." << endl;
        }
        else {
            cout<<"Both time are exactly same."<<endl;
        }
    }
    catch (const char* msg) {
    cout << msg << endl;
}

    return 0;
}
