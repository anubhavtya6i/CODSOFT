#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize the random seed based on the current time
    srand(static_cast<unsigned int>(time(0)));

    // Define the range for the random number
    const int MIN = 1;
    const int MAX = 100;

    // Generate a random number between MIN and MAX
    int numberToGuess = rand() % (MAX - MIN + 1) + MIN;
    int userGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between " << MIN << " and " << MAX << ". Can you guess it?\n";

    // Game loop: keep asking until the player guesses correctly
    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        // Check the player's guess
        if (userGuess < numberToGuess) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    }

    return 0;
}

