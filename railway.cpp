#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "Not Set");
        strcpy(source, "Not Set");
        strcpy(destination, "Not Set");
        strcpy(trainTime, "Not Set");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char* name, const char* src,
          const char* dest, const char* time) {

        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Copy Constructor
    Train(const Train &t) {
        trainNumber = t.trainNumber;
        strcpy(trainName, t.trainName);
        strcpy(source, t.source);
        strcpy(destination, t.destination);
        strcpy(trainTime, t.trainTime);
        trainCount++;
    }

    // Destructor
    ~Train() {
       
    }


    int getTrainNumber() const {
        return trainNumber;
    }

    // Input Method
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Method
    void display(int index) const {
        cout << "\n--- Train " << index << " Details ---\n";
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

// Railway System 

class RailwaySystem {
private:
    vector<Train> trains;

public:
    void addTrainByInput() {
        Train t;
        t.inputTrainDetails();
        trains.push_back(t);
        cout << "Train record added successfully!\n";
    }

    void displayAllTrains() const {
        if (trains.empty()) {
            cout << "No Train Records Available.\n";
            return;
        }

        cout << "\n===== All Train Records =====\n";
        for (int i = 0; i < trains.size(); i++) {
            trains[i].display(i + 1);
        }
        cout << "\nTotal Trains: " << Train::getTrainCount() << endl;
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < trains.size(); i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain Found!\n";
                trains[i].display(i + 1);
                return;
            }
        }
        cout << "Train with number " << number << " not found.\n";
    }
};



int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Add New Train\n";
        cout << "2. Display All Trains\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrainByInput();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3: {
            int num;
            cout << "Enter Train Number: ";
            cin >> num;
            system.searchTrainByNumber(num);
            break;
        }

        case 4:
            cout << "Program Exited Successfully.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}