/*
//Task 01
1) Because the variable which belonged to that pointer i.e "pa" was integer, and the computer occupies 4 bytes for an integer but this varies from computer to computer as it depends on the compiler and architecture of the computer.
2) The address remained the same because memory occupied in both the cases i.e int and float is 4 bytes for that compiler of the computer which can
vary from one computer to another.
3) This is not possible as it is not logically correct and also it isn't required to give a value of product of two addresses in programming.



//Task 02
#include <iostream> 
using namespace std;  
void main()  
{
    cout << "Size of int in Bytes is " << sizeof(int)<<endl;  //sizeof is a function that returns the number of bytes stores in that data type.so we have used this function to know the number of bytes occupied by these data types in the memory.
	cout << "Size of long in Bytes is " << sizeof(long) << endl;		
	cout << "Size of double in Bytes is " << sizeof(double) << endl;
	cout << "Size of float in Bytes is " << sizeof(float) << endl;
	cout << "Size of char in Bytes is " << sizeof(char) << endl;
	getchar();
}



// Task 03
#include <iostream> 
#include <string>
using namespace std;  
class BankAccount 
{   
	string customerName;      
	int accountNumber;            
public:

	void setCustomerName()
	{     
		cout << "Customer's Name: ";
			cin >> customerName;
	
	}
	void setAccountNumber() 
	{        
		cout << "Customer's Account Number: ";
		cin >> accountNumber;

	}
};
class currentAccount :public BankAccount 
{ 
public:
	int currentAccounBbalance=0; 
	void deposit() 
	{   
		int depositMoney;  
		cout << "\nEnter the amount which you want to deposit to your current account: ";
		cin >> depositMoney;
		currentAccounBbalance += depositMoney; 
		cout << "\n"<<depositMoney<<" have been sucessfully deposited to your current account";
	}
	void withdraw() 
	{  
		int withdrawMoney;    
		cout << "\nEnter the amount which you want to withdraw from your savings account: ";
		cin >> withdrawMoney;
		currentAccounBbalance -= withdrawMoney;
		cout << "\n"<<withdrawMoney<<" have been sucessfully deposited to your current account";
	}
	void checkBalance() 
	{  
		cout << "\nYour current account balance is: " << currentAccounBbalance;
	}
	void transactions() 
	{
		int choice;
		do 
		{   
		cout << "\n\nPress \"1\" to deposit money to current account\nPress \"2\" to withdraw money from current account\nPress \"3\" to check current ccount balance\nPress \"4\" to Exit\n";
		cout<<"Option: ";
		cin >> choice;
		if (choice == 1)
		deposit();
		if (choice == 2)
		withdraw();
        if (choice == 3)
		checkBalance();
		} 
		while (choice != 4);
    }
};
class savingsAccount :public BankAccount 
{ 

public:
	int savingsAccountbalance=0; 
	void deposit() 
	{  
		int depositMoney;  
		cout << "\nEnter the amount which you want to deposit to your savings account: ";
		cin >> depositMoney;
		savingsAccountbalance += depositMoney; 
		cout << "\n"<<depositMoney<<" have been sucessfully deposited to your savings account";
	}
	void withdraw() 
	{  
		int withdrawMoney;    
		cout << "\nEnter the amount which you want to withdraw from your savings account: ";
		cin >> withdrawMoney;
		savingsAccountbalance -= withdrawMoney;
		cout << "\n "<<withdrawMoney<<" have been sucessfully deposited to your savings account";
	}
	void checkBalance() 
	{  
		cout << "\nYour savings account balance is: " << savingsAccountbalance;
	}
	void transactions() 
	{
		int choice;
		do 
		{   
		cout << "\n\nPress \"1\" to deposit money to savings account\nPress \"2\" to withdraw money from savings account\nPress \"3\" to check savings account balance\nPress \"4\" to Exit\n";
		cout<<"Option: ";
		cin >> choice;
		if (choice == 1)
		deposit();
		if (choice == 2)
		withdraw();
        if (choice == 3)
		checkBalance();
		} 
		while (choice != 4);
    }
};

int main() 
	{
	BankAccount ba;   
	ba.setCustomerName();   
	ba.setAccountNumber(); 
	int accountType;  
	cout << "\nWhich type of account you want to choose?\nFor Current account press \"1\".\nFor Savings account press \"2\".\n";
	cout<<"Option: ";
	cin >> accountType;
    if (accountType == 1) 
	{
	currentAccount ca;   
	ca.transactions();
	}
	if (accountType == 2) 
	{
	savingsAccount sa; 
	sa.transactions();   
	}
}
*/

