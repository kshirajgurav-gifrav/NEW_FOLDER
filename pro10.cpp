#include <iostream>
#include <string>
using namespace std;
          class BankAccount {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    void readDetails();
    void displayDetails();
    void deposit(double amount);
};
         class SavingsAccount : public BankAccount {
public:
    void calculateInterest(double rate);
};

class CurrentAccount : public BankAccount {
public:
    void withdraw(double amount, double overdraftLimit);
};

void BankAccount::readDetails() {
    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> holderName;

    cout << "Enter balance: ";
    cin >> balance;
}

void BankAccount::displayDetails() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << holderName << endl;
    cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance = balance + amount;
        cout << "Amount deposited successfully." << endl;
        cout << "Updated Balance: " << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

void SavingsAccount::calculateInterest(double rate) {
    if (rate >= 0) {
        double interest = balance * rate / 100;
        cout << "Interest Amount: " << interest << endl;

        balance = balance + interest;
        cout << "Balance after interest: " << balance << endl;
    } else {
        cout << "Invalid interest rate." << endl;
    }
}

void CurrentAccount::withdraw(double amount, double overdraftLimit) {
    if (amount > 0 && overdraftLimit >= 0 &&
        amount <= balance + overdraftLimit) {
        balance = balance - amount;
        cout << "Withdrawal successful." << endl;
        cout << "Updated Balance: " << balance << endl;
    } else {
        cout << "Withdrawal denied. Overdraft limit exceeded." << endl;
    }
}
         int main() {
    SavingsAccount savings;
    CurrentAccount current;
              double amount, rate, overdraftLimit;
              cout << "===== Savings Account =====" << endl;
    savings.readDetails();
    savings.displayDetails();
              cout << "Enter deposit amount: ";
    cin >> amount;
    savings.deposit(amount);
              cout << "Enter interest rate (%): ";
    cin >> rate;
    savings.calculateInterest(rate);
   cout << "\n===== Current Account =====" << endl;
   current.readDetails();
   current.displayDetails();

    cout << "Enter deposit amount: ";
    cin >> amount;
    current.deposit(amount);
              cout << "Enter overdraft limit: ";
    cin >> overdraftLimit;
             cout << "Enter withdrawal amount: ";
    cin >> amount;
    current.withdraw(amount, overdraftLimit);
              return 0;
}
