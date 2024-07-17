#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map<string, int> leaderboard;

void playGame() {
    string name;
    cout << "Enter your Name: ";
    cin >> name;

    int difficulty;
    cout << "Choose the difficulty level (1-3): ";
    cin >> difficulty;

    int maxNum, trials;
    switch (difficulty) {
        case 1:
            maxNum = 50;
            trials = 8;
            break;
        case 2:
            maxNum = 75;
            trials = 6;
            break;
        case 3:
            maxNum = 100;
            trials = 4;
            break;
        default:
            cout << "Invalid difficulty level. Setting to medium (2)." << endl;
            maxNum = 75;
            trials = 6;
            break;
    }

    int randomNumber = rand() % maxNum;
    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│ Let's Play Guess a Number... │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;
    cout << "Difficulty Level: " << difficulty << endl;

    bool win = false;
    int guess, attempts = 0;
    while (!win && attempts < trials) {
        cout << "Guess a Number: ";
        cin >> guess;
        attempts++;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " tries." << endl;
            win = true;
            leaderboard[name]++;
        } else if (guess < randomNumber) {
            int difference = randomNumber - guess;
            if (difference <= 10) {
                cout << "Too low but very close!" << endl;
            } else if (difference <= 20) {
                cout << "Low, but close. Guess again." << endl;
            } else {
                cout << "Too low and too far. Guess again." << endl;
            }
        } else {
            int difference = guess - randomNumber;
            if (difference <= 10) {
                cout << "Too high but very close!" << endl;
            } else if (difference <= 20) {
                cout << "High, but close. Guess again." << endl;
            } else {
                cout << "Too high and too far. Guess again." << endl;
            }
        }
    }

    if (!win) {
        cout << "You failed the game. The correct number was " << randomNumber << "." << endl;
    }
}

void displayLeaderboard() {
    cout << "\nLeaderboard:\n";
    cout << "Name\tScore\n";
    cout << "-------------------\n";
    for (auto& [name, score] : leaderboard) {
        cout << name << "\t" << score << endl;
    }
    cout << "-------------------\n";
}

void displayMenu() {
    int choice;
    do {
        cout << "\nOptions:\n"
             << "1. Play\n"
             << "2. View Leaderboard\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayLeaderboard();
                break;
            case 3:
                cout << "Thanks for playing. See you soon!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
    return 0;
}
