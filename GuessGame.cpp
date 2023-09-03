//Create a program that generates a random number and asks the user to guess it.
//Provide feedback on whether the guess is too high or too low until the user guesses the correct number.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Guessing_Game() {

    string name;
    int user_guess;
    int tries = 0;
    int random_number = rand() % 150 + 1; // Generates a random number between 1 and 150
    bool guessedCorrectly = false;                          // Added boolean flag


    cout << "----------------------------------------------------------------\n";
    cout << "|             Welcome to the NUMBER GUESSING GAME!             |\n";
    cout << "----------------------------------------------------------------\n";
    cout << "Can you tell me your name first?  ";
    cin >> name;
    cout << "\nHEY " << name << "\n";
    cout << "I'm thinking of a number between 1 and 150. Let's see if " << name << " can guess it.. \n";

    do {
        cout << "\nPlease enter your guess: \n";

        if (!(cin >> user_guess)) {
            cout << "\nInvalid Input.\nNOTE: Enter the number from range(1-150) \n";

            // Clear the error flags and any remaining characters from the input buffer.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        tries++;
        cout << "\n";

        // Provide feedback on user's guess
        if (user_guess < random_number) {
            cout << "OPPS...It's too low from guess.Keep guessing!\n";
        }
        else if (user_guess > random_number) {
            cout << "UMMMM...It's too high.Keep guessing!\n";
        }
        else {
            cout << "Congratulations, " << name << "! You guessed the number '" << random_number << "' in " << tries << " tries :)\n\n";
            break;
        }
    } while (!guessedCorrectly); // Loop until guessed correctly

}


void Rules() {
    cout << "|----------------------------RULES:----------------------------|\n";
    cout << "|1. You need to guess the number within my specified range.    |\n";
    cout << "|2. I will give you hints whether your guess is low or high.   |\n";
    cout << "|3. Keep guessing until you find the correct number.           |\n";
    cout << "|4. Have fun and enjoy the game!                               |\n\n";

}

int main() {
    srand(time(nullptr)); // set the random number generator with the current time

    string choice;

    do {
        cout << "\n---------------------------|\n";
        cout << "1. View Game Rules         |\n";
        cout << "2. Start Tic Tac Toe Game  |\n";
        cout << "3. Quit Game               |\n";
        cout << "---------------------------|\n\n";

        cout << "Enter your choice (1-3): ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";

        if (choice.length() == 1) {
            switch (choice[0]) {
            case '1':
                Rules();
                break;

            case '2':
                Guessing_Game();
                break;

            case '3':
                cout << "\nThanks for playing.Hope you had fun.\n\n";
                break;

            default:
                cout << "\nInvalid input :( Please enter a valid number.\n" << endl;

            }
        }
        else {
            cout << "\nInvalid input :( Please enter a valid number.\n" << endl;
        }
    } while (choice != "3");

    return 0;
}

