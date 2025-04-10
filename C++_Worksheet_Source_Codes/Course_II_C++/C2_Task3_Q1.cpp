#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

const int max_books = 10;  // Number of books
const int max_length = 150;  // Max characters in a title

// Function to save book titles into a binary file
void saveBooks(const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    char books[max_books][max_length];  // Store book titles
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter " << max_books << " book titles:" << endl;
    for (int i = 0; i < max_books; i++) {
        cout << "Book " << i + 1 << ": ";
        cin.getline(books[i], max_length);
    }

    file.write(reinterpret_cast<char*>(books), sizeof(books));  // Write all books
    file.close();
    cout << "Books saved successfully in '" << filename << "'" << endl;
}

// Function to find a book title in a binary file
void findBook(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    char books[max_books][max_length];  // Read titles from file
    file.read(reinterpret_cast<char*>(books), sizeof(books));
    file.close();

    char search_title[max_length];
    cout << "Enter book title to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cin.getline(search_title, max_length);

    // Check if book exists
    bool found = false;
    for (int i = 0; i < max_books; i++) {
        if (strcmp(books[i], search_title) == 0) {
            found = true;
            break;
        }
    }

    if (found){
        cout << "The book \"" << search_title << "\" is in the file." << endl;
        cout << endl;
        }
    else{
        cout << "The book \"" << search_title << "\" is NOT in the file." << endl;
        cout << endl;
        }
}

int main() {
    char filename[50];
    cout << "Enter the name of the binary file (.bin file): ";
    cin >> filename;

    int choice;
    do {
        cout << "MENU:" << endl;
        cout << "1) Save 10 book titles" << endl;
        cout << "2) Search for a book title" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
            continue; // Restart loop
        }

        switch (choice) {
            case 1:
                saveBooks(filename);
                break;
            case 2:
                findBook(filename);
                break;
            case 3:
                cout << endl;
                cout << "Exiting program... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
