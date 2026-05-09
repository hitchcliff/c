#include <iostream>

double deposit();
double withdraw(double balance);
void showBalance(double balance);

int main() {

    std::cout << "Welcome to the banking balance program!" << std::endl;

    double balance = 0.0; // user total balance
    int choice = 0;

    do  {

        std::cout << "Please select an option: " << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Show Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1: balance += deposit();
            break;
            case 2: balance -= withdraw(balance);
            break;
            case 3: showBalance(balance);
            break;  
            case 4: std::cout << "Thank you for using the banking balance program. Goodbye!" << std::endl;
            break;
            default: std::cout << "Invalid option. Please try again." << std::endl;
        }

    } while(choice != 4);



    return 0;
}

double deposit() {
    double amount;

    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;

    if (amount < 0) {
        std::cout << "Invalid amount. Please enter a positive value." << std::endl;
        return 0.0;
    }

    std::cout << "You have deposited: $" << amount << std::endl;

    return amount;
}

double withdraw(double balance) {
    double amount;

    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amount;

    if(amount < 0) {
        std::cout << "Invalid amount. Please enter a positive value." << std::endl;
        return 0.0;
    } else if (amount > balance) {
        std::cout << "Insufficient funds. Your current balance is: $" << balance << std::endl;
        return 0.0;
    }

    std::cout << "You have withdrawn: $" << amount << std::endl;

    return amount;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << balance << std::endl;
}