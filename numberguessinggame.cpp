//number guessing game program
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Initialize random number generator with current time as seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I have generated a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    // Loop until the user guesses the correct number
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number!" << std::endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
