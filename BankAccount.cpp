#include "BankAccount.h"

// interface function to perform *threadsafe* transactions
// "you will need to implement the transaction_threadsafe() function...
// "using mutexes to ensure proper concurrency"
void BankAccount::transaction_threadsafe(int _amount) {
    // TODO: LOCK other threads from using transaction() at the same time
    transaction(_amount);
    // TODO: UNLOCK for the next thread to access transaction()
}

/***************** ALL FUNCTIONS BELOW THIS LINE ARE COMPLETE ****************/

// default constructor
// "assume the bank account starts with $0"
BankAccount::BankAccount() : balance(0) {}

// interface function to perform transactions
void BankAccount::transaction(int _amount) {
    int temp = balance;
    temp += _amount;
    usleep(rand() % 50);
    balance = temp;
}

// print function for consistency
void BankAccount::print_balance() {
    std::string currency = this->balance < 0 ? "-$" : "$";
    std::cout << currency << abs(this->balance);
}
