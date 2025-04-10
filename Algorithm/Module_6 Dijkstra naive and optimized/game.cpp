#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));
    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int numberOfTries = 0;
    int guess;
    bool hasWon = false;

    cout << "Welcome to Guess the Number!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Main game loop
    while (!hasWon) {
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfTries++;

        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            hasWon = true;
            cout << "Congratulations! You guessed the number in " << numberOfTries << " tries." << endl;
        }
    }

    return 0;
}
