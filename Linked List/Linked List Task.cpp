#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class LinkedList            
{
private:
	class node          
	{
	public:
		int number;          
		node *next;           
		node()
		{
			next = NULL;
		}
	};
	node *head = NULL;        
	node *head2;         
	int totalNodes;       
public:
	bool flagAdd;
	LinkedList()
	{
		flagAdd = 0;
		head = NULL;
	}
	void PrintList()            
	{
		node *ptr = head;
		if (ptr == NULL)         
		{
			cout << "The list is empty" << endl;
		}
		else
		{
			cout << "The list is: \n";
		}
		while (ptr != NULL)          
		{
			cout << ptr->number << endl;       
			ptr = ptr->next;           
		}
	}
	int numOfnodes()         
	{
		node *ptr = head;    
		int counter = 0;       
		while (ptr != NULL)         
		{
			ptr = ptr->next;        
			counter++;              
		}
		totalNodes = counter;          
		return totalNodes;
	}
	void InsertNodeAtFront(int number)           
	{
		node *p = head;             
		node *add = new node();   
		add->number = number;     
		add->next = NULL;
		if (head == NULL)               
		{
			head = add;        
			flagAdd = 1;
			system("cls");
		}
		else
		{
			add->next = head;                 
			head = add;                       
			node *ptr = head;          
			while (ptr != NULL)         
			{
				ptr = ptr->next;              
			}
		}
	}
	void InsertNodeAtBack(int number)    
	{
		node *p = head;         
		node *add = new node();   
		add->number = number;      
		if (head == NULL)     
		{
			head = add;            
			flagAdd = 1;
			system("cls");
		}
		else
		{
			node *ptr = head;             
			while (ptr->next != NULL)        
			{
				ptr = ptr->next;     
			}
			ptr->next = add;     
		}
		flagAdd = 1;
		system("cls");
	}
	int DeleteNodeFromFront()        
	{
		node *del;        
		numOfnodes();        
		if (head == NULL)     
		{
			cout << "The list is empty at the moment. First add any node and then select this option";
		}
		else if (head != NULL)      
		{
			del = head;             
			head = head->next;       
			cout << "The number which was at front was successfully deleted from the list" << endl;
		}
	}
};
int main()
{
	LinkedList L1, L2, L3;          
	char option, choice;
	int num;
	do
	{
		cout<<"\n\nLIST L1!!\n\n";
		cout << "Do you want to add a value in the List L1? (Y/N): ";
		cin >> option;
		if (option == 'y' || option == 'Y')
		{
			cout << "Enter the value which you want to add in the list(The values will be added at the front of the list): ";
			cin >> num;
			L1.InsertNodeAtFront(num);     
			cout<<"Do you want to print the List L1?(Y/N): ";
			cin>>choice;
			if(choice == 'Y' || choice =='y')		
			L1.PrintList();      
		}
		else
			break;
	} while (option != 'y' || option != 'Y');

	do
	{
		cout<<"\n\nLIST L2!!\n\n";
		cout << "Do you want to add a value in the List L2? (Y/N): ";
		cin >> option;
		if (option == 'y' || option == 'Y')
		{
			cout << "Enter the value which you want to add in the list(The values will be added at the back of the list): ";
			cin >> num;
			L2.InsertNodeAtBack(num);     
			cout<<"Do you want to print the List L2?(Y/N): ";
			cin>>choice;
			if(choice == 'Y' || choice =='y');
			L2.PrintList();      
		}
		else
			break;
	} while (option != 'y' || option != 'Y');

	do
	{
		cout<<"\n\nLIST L3!!\n\n(By deleting values from List L1)";
		cout << "Do you want to delete a value from the List L1? (Y/N): ";
		cin >> option;
		if (option == 'y' || option == 'Y')
		{
			cout << "Enter the value which you want to delete from the list(The values will be deleted from the front of the list): ";
			cin >> num;
			L2.DeleteNodeFromFront();    
		}
		else
			break;
	} while (option != 'y' || option != 'Y');
	
	do
	{
		cout<<"\n\nLIST L3!!\n\n(By deleting values from List L2)";
		cout << "Do you want to delete a value from the List L2? (Y/N): ";
		cin >> option;
		if (option == 'y' || option == 'Y')
		{
			cout << "Enter the value which you want to delte from the list(The values will be deleted from the front of the list): ";
			cin >> num;
			L2.DeleteNodeFromFront();          
		}
		else
			break;
	} while (option != 'y' || option != 'Y');
	
	L3.PrintList();
}
