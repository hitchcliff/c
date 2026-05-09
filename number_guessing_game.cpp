#include <iostream>

int main() {

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "Try to guess the number between 1 and 100." << std::endl;

    int guess;
    int num;
    int attempts = 0;

    srand(time(NULL));
    num = (rand() % 100) + 1;

    while (guess != num) {
        std::cout << "Enter your guess:";
        std::cin >> guess;
        attempts++;

        if(guess < num) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > num) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number in " << attempts << " attempts!" << std::endl;
        }
    }

    return 0;
}