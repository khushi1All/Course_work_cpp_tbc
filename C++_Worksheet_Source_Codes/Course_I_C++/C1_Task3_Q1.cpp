#include <iostream>
using namespace std;

class CinemaBooking {
private:
    char seating[5][5]; // 5x5 array

public:
    CinemaBooking() {
        //Seating arrangement with 'O' indicate available seats
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                seating[i][j] = 'O';
            }
        }
    }


    void displaySeating() {
        cout << "Current seating arrangement: "<<endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << seating[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bookSeat() {
        int row, col;
        cout << "Enter row (1-5): "<<endl;
        cin >> row;
        cout << "Enter column (1-5): "<<endl;
        cin >> col;

        // Check if the entered row and column are valid
        if (row < 1 || row > 5 || col < 1 || col > 5) {
            cout << "Invalid row/column! Please enter a row and column between 1 and 5." <<endl;
            return;
        }

        // Adjust indices since the user starts from 1, but array indices start from 0
        row -= 1;
        col -= 1;

        // Check if the selected seat is already booked
        if (seating[row][col] == 'X') {
            cout << "Error! Seat already booked."<<endl;
        } else {
            seating[row][col] = 'X';  // Mark the seat as booked
            cout << "Seat booked successfully!"<<endl;
        }

        displaySeating(); // Show the updated seating arrangement
    }
};

int main() {
    CinemaBooking cinema;
    char checkAgain;

    cout << "    SEAT BOOKING:"<< endl;

    do {
        cinema.displaySeating();
        cinema.bookSeat();
        cout << "Do you want to book another seat? (Y/N): ";
        cin >> checkAgain;

        // Input validation for 'Y' or 'N'
        while (checkAgain != 'Y' && checkAgain != 'y' && checkAgain != 'N' && checkAgain != 'n') {
            cout << "Invalid input! Please enter 'Y' to book another seat or 'N' to exit: "<<endl;
            cin >> checkAgain;
        }

    } while (checkAgain == 'Y' || checkAgain == 'y'); // Keep booking if user wans

    cout<<endl;
    cout << "Thank you for using the Cinema Booking System!" << endl;

    return 0;
}
