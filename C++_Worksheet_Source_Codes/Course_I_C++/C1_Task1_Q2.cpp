#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomGuessNumber {
private:
    int random, num;
    int attempts = 1;
    int lowerLimit, upperLimit;

public:
    void setLevel() {
        int level;
        cout << "Which difficulty level do you want to play in?" << endl;
        cout<<endl;
        cout << "1. Easy (1-8)" << endl;
        cout << "2. Medium (1-30)" << endl;
        cout << "3. Hard (1-50)" << endl;
        cout<<endl;
        cout << "(Press 1/2/3): ";
        cin >> level;
        cout<<endl;

        if (level == 1) {
            lowerLimit = 1;
            upperLimit = 8;
        }
        else if (level == 2) {
            lowerLimit = 1;
            upperLimit = 30;
        }
        else if (level == 3) {
            lowerLimit = 1;
            upperLimit = 50;
        }
        else {
            cout << "Invalid choice. Setting to Easy by default." << endl;
            lowerLimit = 1;
            upperLimit = 8;
        }

        cout << "You selected a range from " << lowerLimit << " to " << upperLimit << "!" << endl;
        cout<<endl;
    }

    void playGame() {
        // Generate random number based on the selected level
        random = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;

        cout << "Guess the number between " << lowerLimit << " and " << upperLimit << ": ";
        while (true) {
            cin >> num;

            if (num == random) {
                cout<<endl;
                cout << "Congratulations! You guessed the number " << random << " in " << attempts << " attempts." << endl;
                break;
            }
            else if (num < random) {
                cout << "Too low!"<<endl;
                cout<<"Try again. "<<endl;
            }
            else {
                cout << "Too high!"<<endl;
                cout<<"Try again. "<<endl;
                cout<<endl;
            }
           attempts++;
        }
    }
};

int main() {
    char playAgain;
    srand(time(0)); // Seed random number generator with current time

    cout << "           WELCOME TO THE GUESSING GAME" << endl;
    cout<<endl;
    cout<<endl;

    do {
        RandomGuessNumber game;
        game.setLevel();   // Set the difficulty level
        game.playGame();   // Start the game

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        // Input validation for 'Y' or 'N'
        while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
            cout << "Invalid input! Please enter 'Y' to play again or 'N' to exit: ";
            cin >> playAgain;
        }

    } while (playAgain == 'Y' || playAgain == 'y'); // Keep playing if user wants

    cout<<endl;
    cout << "Thank you for playing!" << endl;
    return 0;
}
