#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> personNames;
map<string, int> nameToAgeMap;

// Function to add a new person with their name and age
void addPersonDetails() {
    string personName;
    int personAge;
    cout << "Enter the name: " << endl;
    cin >> personName;
    cout << "Enter their age: " << endl;
    cin >> personAge;

    personNames.push_back(personName);
    nameToAgeMap[personName] = personAge;

    cout << "Person added successfully!" << endl;
}

// Function to list people who are older than a certain age
void findOlderPeople(int ageThreshold) {
    cout << "People older than " << ageThreshold << " years:" << endl;
    for (const auto& entry : nameToAgeMap) {
        if (entry.second > ageThreshold) {
            cout << entry.first << " (" << entry.second << " years old)" << endl;
        }
    }
}

// Function to sort and display the names alphabetically
void showSortedNames() {
    vector<string> sortedList = personNames;
    sort(sortedList.begin(), sortedList.end());

    cout << "Here are the names in alphabetical order:" << endl;
    for (const string& name : sortedList) {
        cout << name << endl;
    }
}

int main() {
    int option;
    while (true) {
        cout << endl;
        cout << "--- Main Menu ---" << endl;
        cout << "1. Add a new person with name and age" << endl;
        cout << "2. Find people older than a certain age" << endl;
        cout << "3. Show names sorted alphabetically" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Please choose an option: " << endl;
        cin >> option;

        if (option == 1) {
            addPersonDetails();
        }
        else if (option == 2) {
            int ageLimit;
            cout << "Enter the age threshold: " << endl;
            cin >> ageLimit;
            findOlderPeople(ageLimit);
        }
        else if (option == 3) {
            showSortedNames();
        }
        else if (option == 4) {
            cout << "Goodbye! Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
