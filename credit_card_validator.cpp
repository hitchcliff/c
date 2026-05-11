#include <iostream>

int getDigits(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

int main() {
    std::cout << "Welcome to the Credit Card Validator!" << std::endl;

    std::string cardNumber;
    int result = 0;

    std::cout << "Please enter your credit card number: ";
    std::cin >> cardNumber;

    // result = sumOddDigits(cardNumber);

    result = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);
    std::cout << "The sum of the odd digits is: " << sumOddDigits(cardNumber)<< std::endl;
    std::cout << "The sum of the even digits is: " << sumEvenDigits(cardNumber) << std::endl;

    if(result %10 == 0) {
        std::cout << "The credit card number is valid." << std::endl;
    } else {
        std::cout << "The credit card number is invalid." << std::endl;
    }



    return 0;
}

int getDigits(int number){
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardNumber){
    int sum = 0;

    for(int  i = cardNumber.size() - 1; i >=0; i--) {
        sum += getDigits(cardNumber[i] - '0');
    }
    

    return sum;
}

int sumEvenDigits(const std::string cardNumber){

    int sum = 0;

    for (int i= cardNumber.size() - 2; i >= 0; i--) {
        sum += getDigits((cardNumber[i] - '0') * 2);
    }

    return sum;
}
