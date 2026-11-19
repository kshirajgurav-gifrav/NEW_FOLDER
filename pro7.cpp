#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Parameterized Constructor
    BankAccount(string accNo, string name, double initialBalance);

    // Member Function Prototypes
    void deposit(double amount);
    void withdraw(double amount);
    void displayBalance();
    void displayAccountDetails();
};

// Constructor Definition
BankAccount::BankAccount(string accNo, string name, double initialBalance)
{
    accountNumber = accNo;
    accountHolderName = name;
    balance = initialBalance;
}

// Deposit Function
void BankAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Error: Deposit amount must be positive!" << endl;
    }
    else
    {
        balance += amount;

        cout << "Deposited $" << amount
             << " to account " << accountNumber
             << ". New Balance: $" << balance << endl;
    }
}

// Withdraw Function
void BankAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Error: Withdrawal amount must be positive!" << endl;
    }
    else if (amount > balance)
    {
        cout << "Error: Insufficient funds in account "
             << accountNumber << "!" << endl;
    }
    else
    {
        balance -= amount;

        cout << "Withdrew $" << amount
             << " from account " << accountNumber
             << ". New Balance: $" << balance << endl;
    }
}

// Display Balance Function
void BankAccount::displayBalance()
{
    cout << "Current Balance: $" << balance << endl;
}

// Display Account Details Function
void BankAccount::displayAccountDetails()
{
    cout << "Account Number: " << accountNumber
         << " | Holder: " << accountHolderName
         << " | Balance: $" << balance << endl;
}

int main()
{
    string accNo1, accNo2;
    string name1, name2;

    double initialBalance1, initialBalance2;
    double depositAmount, withdrawalAmount;

    cout << fixed << setprecision(2);

    // Input Account 1 Details
    cout << "Enter account number for Account 1: ";
    cin >> accNo1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter account holder name for Account 1: ";
    getline(cin, name1);

    cout << "Enter initial balance for Account 1: ";
    cin >> initialBalance1;

    // Input Account 2 Details
    cout << "\nEnter account number for Account 2: ";
    cin >> accNo2;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter account holder name for Account 2: ";
    getline(cin, name2);

    cout << "Enter initial balance for Account 2: ";
    cin >> initialBalance2;

    // Create Account Objects
    BankAccount account1(accNo1, name1, initialBalance1);
    BankAccount account2(accNo2, name2, initialBalance2);

    // Initial Account Status
    cout << "\n--- Initial Account Status ---" << endl;

    account1.displayAccountDetails();
    account2.displayAccountDetails();

    // Input Transactions
    cout << "Enter deposit amount for Account 1: ";
    cin >> depositAmount;

    cout << "Enter withdrawal amount for Account 2: ";
    cin >> withdrawalAmount;

    // Perform Transactions
    cout << "\n--- Performing Transactions ---" << endl;

    account1.deposit(depositAmount);
    account2.withdraw(withdrawalAmount);

    // Final Account Status
    cout << "--- Final Account Status ---" << endl;

    account1.displayAccountDetails();
    account2.displayAccountDetails();

    return 0;
}
