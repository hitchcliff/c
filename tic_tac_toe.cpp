#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    std::cout << "Welcome to the Tic Tac Toe Game!" << std::endl;

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    do {
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            break;
        }
        

        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            break;
        }

        // if(checkTie(spaces)) {
        //     std::cout << "It's a tie!" << std::endl;
        //     break;
        // }          

    } while(running);

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << std::endl;
    std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << std::endl;
    std::cout << std::endl;
}

void playerMove(char *spaces, char player) {

    int number;

    while(number > 0 || number < 10) {
        std::cout << "Player " << player << ", enter a number between 1 and 9: ";
        std::cin >> number;

        number--;

        if(spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    }
}

void computerMove(char *spaces, char computer) {

    srand(time(NULL));

    int number = rand() % 9;

    while (true) {
        number = rand() % 9;

        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }

}


bool checkWinner(char *spaces, char player, char computer) {

    // check rows
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        if(spaces[0] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
        return true;
    }

    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        if(spaces[3] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        if(spaces[6] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    // check columns
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        if(spaces[0] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        if(spaces[1] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        if(spaces[2] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    // check diagonals
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        if(spaces[0] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    }

    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        if(spaces[2] == player) {
            std::cout << "Player " << player << " wins!" << std::endl;
        } else {
            std::cout << "Computer " << computer << " wins!" << std::endl;
        }
    } else {
        return false;
    }


    return true;
}

bool checkTie(char *spaces) {
    for(int i =0; i <9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }

    return true;
}