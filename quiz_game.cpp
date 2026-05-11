#include <iostream>

int main() {

    std::cout << "Welcome to the Quiz Game!" << std::endl;

    std::string questions[] = {
        "What is the capital of France?",
        "What is 2 + 2?",
        "Who wrote 'To Kill a Mockingbird'?"
    };

    std::string options[][3] = {
        {"A) Paris", "B) London", "C) Rome"},
        {"A) 3", "B) 4", "C) 5"},
        {"A) Harper Lee", "B) J.K. Rowling", "C) Ernest Hemingway"}
    };

    char answers[] = {'A', 'B', 'A'};

    char guess;
    int score = 0;

    int size = sizeof(questions) / sizeof(questions[0]);
    
    for(int i =0; i < size; i++) {
        std::cout << "****************************" << std::endl;
        std::cout << questions[i] << std::endl;

        for(int j =0;j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            std::cout << options[i][j] << std::endl;
        }

        std::cin >> guess;
        guess = toupper(guess);

        if(guess == answers[i]) {
            std::cout << "Correct!" << std::endl;
            score++;
            std::cout << score << std::endl;
        } else {
            std::cout << "Wrong! The correct answer is " << answers[i] << "." << std::endl;
        }

    }

    std::cout << "****************************" << std::endl;
    std::cout << "Your score is: " << score << std::endl;
    std::cout << "Total questions: " << size << std::endl;
    std::cout << "Percentage: " << (score/(double)size) * 100 << "%" << std::endl;
    std::cout << "****************************" << std::endl;
    

    return 0;
}

