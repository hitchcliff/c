#include <iostream>
#include <ctime>

char getPlayerChoice();
char getComputerChoice();
void showChoice(char choice);
void determineWinner(char playerChoice, char computerChoice);

int main() {

    char playerChoice;
    char computerChoice;


    playerChoice = getPlayerChoice();
    std::cout << "You chose: " << std::endl;
    showChoice(playerChoice);

    computerChoice = getComputerChoice();
    std::cout << "Computer chose: " << std::endl;
    showChoice(computerChoice);

    determineWinner(playerChoice, computerChoice);

    return 0;
}


char getPlayerChoice() {
    char choice;

    do {
        std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
        std::cout << "Please enter your choice (R for Rock, P for Paper, S for Scissors): ";
        std::cin >> choice;
    } while (choice != 'R' && choice != 'P' && choice != 'S');
    
    
    return choice;
}

char getComputerChoice() {
    srand(time(NULL));
    int randomNum = rand() % 3; // generates a random number between 0

    switch(randomNum) {
        case 0: return 'R';
        case 1: return 'P';
        case 2: return 'S';
    }
}

void showChoice(char choice) {
    switch (choice) {
        case 'R': std::cout << "Rock" << std::endl;
        break;
        case 'P': std::cout << "Paper" << std::endl;
        break;
        case 'S': std::cout << "Scissors" << std::endl;
        break;
    }
}

void determineWinner(char playerChoice, char computerChoice) {

    if(playerChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl;
    } else if (playerChoice == 'R' && computerChoice == 'S' || playerChoice == 'P' && computerChoice == 'R' || playerChoice == 'S' && computerChoice == 'P') {
        std::cout << "Congratulations! You win!" << std::endl;
    } else {
        std::cout << "Sorry, you lose. Better luck next time!" << std::endl;
    }

}