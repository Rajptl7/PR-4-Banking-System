#include <iostream>
using namespace std;

class BankAccount{
private:
    double accountNumber;
    string accountHolderName;

protected:
    double accountBalance;

public:
    void deposit(double amount); // only delcaration
    void withdraw(double amount);
    double getBalance();
    void displayAccountInfo();

    BankAccount(double accountNumber, string accountHolderName, double accountBalance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->accountBalance = accountBalance;
    }

    virtual void calculateInterest()
    {
        cout << "Bank Account Interest" << endl;
    }
};

void BankAccount::deposit(double amount)
{
    accountBalance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (amount <= accountBalance)
    {
        accountBalance -= amount;
    }
    else
    {
        cout << "Insuffient Balance";
    }
}

double BankAccount::getBalance()
{
    return accountBalance;
}

void BankAccount::displayAccountInfo()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Account Balance: " << accountBalance << endl;
}

class SavingsAccount : public BankAccount{
private:
    double interestRate, interest;

public:
    void calculateInterest();
    SavingsAccount(double accountNumber, string accountHolderName, double accountBalance, double interestRate) : BankAccount(accountNumber, accountHolderName, accountBalance)
    {
        this->interestRate = interestRate;
    }
};

void SavingsAccount::calculateInterest()
{
    interest = (getBalance() * interestRate) / 100;
    cout << "Interest: " << interest << endl;
}

class CheckingAccount : public BankAccount{
private:
    double overdraftLimit;

public:
    void withdraw(double amount);
    bool checkOverDraft(double amount);

    CheckingAccount(double accountNumber, string accountHolderName, double accountBalance, double overdraftLimit) : BankAccount(accountNumber, accountHolderName, accountBalance)
    {
        this->overdraftLimit = overdraftLimit;
    }
};

bool CheckingAccount::checkOverDraft(double amount)
{
    if (amount <= getBalance() + overdraftLimit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CheckingAccount::withdraw(double amount)
{
    if (checkOverDraft(amount))
    {
        accountBalance -= amount;
        cout << "withdrawl Sauccessfull" << endl;
    }
    else
    {
        cout << "Overdraft Limit Exceeded";
    }
}

class FixedDepositAccount : public BankAccount{
private:
    int term;
    double interestRate;
    double interest;

public:
    void calculateInterest();

    FixedDepositAccount
    (
        double accountNumber,
        string accountHolderName,
        double accountBalance,
        double interestRate,
        double term) : BankAccount(accountNumber, accountHolderName, accountBalance)
    {
        this->interestRate = interestRate;
        this->term = term;
    }
};

void FixedDepositAccount::calculateInterest()
{
    interest = (getBalance() * interestRate * term) / (100 * 12);
    cout << "Fixed Deposit Interest: " << interest << endl;
}

int main()
{

    // BankAccount *acc;
    // SavingsAccount  s;
    // acc  = &s;
    // acc->calculateInterest();

    // BankAccount b(101, "Raj", 19800);
    // cout << b.getBalance() << endl;
    // b.displayAccountInfo();


    // Savings Account
    cout << endl;
    SavingsAccount s(101, "Raj", 10000, 5);

    cout << "Savings Account:" << endl;

    s.displayAccountInfo();
    s.deposit(2000);
    s.withdraw(1000);
    s.displayAccountInfo();
    s.calculateInterest();
    cout<<endl<<endl;

    // Checking Account
    CheckingAccount c(102, "Nevil", 5000, 2000);

    cout << "Checking Account:" << endl;

    c.displayAccountInfo();
    c.deposit(1000);
    c.withdraw(6000);
    c.displayAccountInfo();
    cout<<endl<<endl;

    // Fixed Deposit Account
    FixedDepositAccount f(103, "Pruthiv", 20000, 6, 12);

    cout << "Fixed Deposit Account:" << endl;
    
    f.displayAccountInfo(); 
    f.calculateInterest();
    cout<<endl;

    BankAccount *acc;

    acc = &s;
    acc->calculateInterest();

    acc = &f;
    acc->calculateInterest();\
    cout << endl;

    return 0;
}