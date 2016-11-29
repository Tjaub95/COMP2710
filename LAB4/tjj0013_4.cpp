/*
 * =====================================================================================
 *
 *       Filename:  tjj0013_4.cpp
 *
 *    Description:  Bank transaction application that allows the bank and customers to 
 *                  create bank accounts, and perform transactions and print transactions
 *                  of various types, as well as the total balance. 
 *
 *        Version:  1.0
 *        Created:  11/28/2016 06:04:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *   Organization:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class BankAccount
{
public:

	BankAccount(const string &name, const string &account)
		: owner(name), account_type(account), balance(0.0) {}

	virtual ~BankAccount() {}

	string getName() 
	{
		return owner;
	}

	string getAccountType() 
	{
		return account_type;
	}

	double getBalance() 
	{
		return balance;
	}

	void deposit(double amount)
	{
		balance += amount;
	}

	virtual int withdrawal(double amount)
	{
		if (amount > balance)
		{
			cout << "Insufficient funds";
			return -1;
		}	

		else
		{
			balance -= amount;
			return 1;
		}	
	} 

	virtual void printTransactions()
	{
		cout << "\n\nTransaction # " << id << ":";
    	cout << "\n" << type.c_str();
    	cout << "\nName: " << acct_->getName().c_str();
    	cout << "\nAccount type: " << acct_->getAccountType().c_str();
	}

	virtual void computeBankBalance()
	{
    	double finalBalance;
    	
    	for (int i = 0; i < list.size(); i++)
    	{
    		BankAccount* acct = list[i];
    
			finalBalance += acct->getBalance();
		}	

		cout << "Final Balance: $" << finalBalance;
    }	

protected:
	string owner;
	string account_type;
	double balance;
	int id;
	string type;
	BankAccount* acct_;
	vector<BankAccount*> list;
};

class SavingAccount : public BankAccount
{
public:
	SavingAccount(const string &name)
		: BankAccount(name, "Saving account") {}

	~SavingAccount() {}
};

class CheckingAccount : public BankAccount
{
public:
	CheckingAccount(const string &name)
		: BankAccount(name, "Checking account") {}

	~CheckingAccount() {}	

	int withdrawal(double amount)
	{
		if (amount > balance)
		{
			cout << "Insufficient funds";
			return -1;
		}

		else
		{
			balance -= amount;
			if (balance < 500)
			{
				cout << "Withdrawal Fee: $2.50";
				balance -= 2.5;
			}

			return 1;
		}		
	}
};

class MoneyMarketAccount : public BankAccount
{
public:
	MoneyMarketAccount(const string &name)
		: BankAccount(name, "Money market account"), numWithdrawals(0) {}

	~MoneyMarketAccount() {}
		
	int withdrawal(double amount)
	{
		if (amount > balance)
		{
			cout << "Insufficient funds";
			return -1;
		}

		else
		{	
			balance -= amount;

			numWithdrawals++;

			if(numWithdrawals > 2)
			{
				cout << "Withdrawal fee: $1.50";
				balance -= 1.5;
			}
		}

		return 1;	
	}

private:
	int numWithdrawals;
};

class CDAccount : public BankAccount
{
public:
	CDAccount(const string &name, double interest)
		: BankAccount(name, "CD account"), interest_rate(interest) {}

	~CDAccount() {}
		
	int withdrawal(double amount)
	{
		if (amount > balance)
		{
			cout << "Insufficient funds";
			return -1;
		}

		else
		{	
			double penalty = balance * interest_rate * .25;
			cout << "Withdrawal penalty: $" << penalty;

			balance -= amount + penalty;

			return 1;
		}	
	}

private:
	double interest_rate;	
};


class System
{
public:

	System() { }
 
  	~System() 
  	{  	}	

  	vector<BankAccount*> list;

	void create()
	{
		cout << "\nEnter name: ";
		string name;
		cin >> name;

		cin.ignore();

		cout << "\nEnter account type: ";
		string account;
		getline(cin, account);

		if (account == "Saving account")
		{
			SavingAccount *acct = new SavingAccount(name);
      		acct_[name] = acct;
      		list.push_back(acct);
		}	

		else if (account == "Checking account")
		{
			CheckingAccount *acct = new CheckingAccount(name);
      		acct_[name] = acct;
      		list.push_back(acct);
		}	

		else if (account == "Money market account")
		{
			MoneyMarketAccount *acct = new MoneyMarketAccount(name);
      		acct_[name] = acct;
      		list.push_back(acct);
		}

		else if (account == "CD account")	
		{
			cout << endl << "Enter interest rate (in percentage): ";
			string r;
			cin >> r;
			double rate = atof(r.c_str());

			if (rate < 0 || rate > 100)
			{
				cout << endl << "Error! Invalid Rate." << endl;
				return;
			}

			CDAccount *acct = new CDAccount(name, rate / 100.);
      		acct_[name] = acct;
      		list.push_back(acct);
		}

		else
		{
			cout << endl << "Invalid account type." << endl;
			return;
		}
	}

	void depositing()
	{
		cout << "\nEnter name: ";
		string name;
		cin >> name;

		if (acct_.find(name) == acct_.end()) 
		{
      		fprintf(stderr, "Account name not exist!\n");
      		return;
    	}

		cout << "\nEnter account type: ";
		string account;
		cin.ignore();
		getline(cin, account);
		cout << "\nEnter deposit amount: $";
		string deposit;
		cin >> deposit;
		double amount = atof(deposit.c_str());

		BankAccount *acct = acct_[name];

		acct -> deposit(amount);

		cout << endl << "Balance: $" << acct->getBalance() << endl;
	}

	void withdraw()
	{
		cout << endl << endl << "Enter name: ";
		string name;
		cin >> name;

		if (acct_.find(name) == acct_.end()) 
		{
      		fprintf(stderr, "Account name not exist!\n");
      		return;
    	}

		cout << endl << "Enter account type: ";
		string account;
		cin.ignore();
		getline(cin, account);
		cout << endl << "Enter withdrawal amount: $";
		string deposit;
		cin >> deposit;
		double amount = atof(deposit.c_str());

		BankAccount *acct = acct_[name];

		acct -> withdrawal(amount);

		cout << endl << "Balance: $" << acct->getBalance() << endl;
	}

	void transferring()
	{
		cout << endl << endl << "Enter name (to withdraw from): ";
		string name;
		cin >> name;

		if (acct_.find(name) == acct_.end()) 
		{
      		fprintf(stderr, "Account name not exist!\n");
      		return;
    	}

		cout << endl << "Enter account type: ";
		string account;
		cin.ignore();
		getline(cin, account);
		cout << endl << "Enter transfer amount: $";
		string deposit;
		cin >> deposit;
		double amount = atof(deposit.c_str());

		BankAccount *acct = acct_[name];

		acct -> withdrawal(amount);

		cout << endl << "Balance: $" << acct->getBalance() << endl;

    	cout << "\nEnter name (to transfer to): ";
		string name2;
		cin >> name2;

		if (acct_.find(name2) == acct_.end()) 
		{
      		fprintf(stderr, "Account name not exist!\n");
      		return;
    	}

		cout << "\nEnter account type: ";
		string account2;
		cin.ignore();
		getline(cin, account2);

		BankAccount *acct2 = acct_[name2];

		acct2 -> deposit(amount);


		cout << endl << "Balance: $" << acct2->getBalance() << endl;
	}

	void inquiring()
	{
		cout << "\nEnter name: ";
		string name;
		cin >> name;

		cin.ignore();

		cout << "\nEnter account type: ";
		string account;
		getline(cin, account);

		BankAccount *acct = acct_[name];

		cout << endl << "Balance: $" << acct->getBalance() << endl;
	}

	void printAll()
	{
		for(int i = 0; i < list.size(); i++)
		{
			list[i] -> printTransactions();
		}	
	}
	
	void computeBalance()
	{
		for (int i = 0; i < list.size(); i++)
		{
			list[i] -> computeBankBalance();
		}
	}

private:
  	System(const System &);
  	void operator = (const System &);

  	map<string, BankAccount *> acct_;	
};

int main()
{
	System ss;

	int option;

	do
	{
		cout << endl;
		cout << "===========================================================" << endl;
		cout << "|                Welcome to Aubie Bank!                   |" << endl;
		cout << "===========================================================" << endl;

		cout << endl << "Select an option: (1) Create account, (2) Deposit fund, (3) Withdraw fund," << endl;
		cout << "(4) Transfer fund, (5) Inquiry, (6) Print all transactions, (7) Print Bank Balance," << endl;
		cout << "(8) Quit:  ";

		string input;
		cin >> input;

		option = atoi(input.c_str());

		switch(option)
			{
				case (1): 
				{
					ss.create();	
					break;
				}

				case (2):
				{
					ss.depositing();
					break;
				}

				case (3):
				{
					ss.withdraw();
					break;
				}

				case (4):
				{
					ss.transferring();
					break;
				}

				case (5):
				{
					ss.inquiring();
					break;
				}

				case (6):
				{
					ss.printAll();
					break;
				}

				case (7):
				{
					ss.computeBalance();
					break;
				}

				case (8):
				{
					cout << "===========================================================" << endl;
					cout << "|        Thank you for banking with Aubie Bank!           |" << endl;
					cout << "===========================================================" << endl;
					break;
				}
			}	

	} while (option != 8);	
};


