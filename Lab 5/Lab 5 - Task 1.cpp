/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Data Structures And Algorithms
Lab 5
Task 2
Linked List Implementation of Queue
*/

#include<iostream>
using namespace std;

class queueList{
public:
	struct Node
	{
		int num;
		struct Node *next;
	}*front = NULL, *rear = NULL;
	queueList()	{}
	bool isEmpty()
	{
		if(front==NULL)
		return 1;
		else 
		return 0;
	}
	void Enque(int x)
	{
		Node *temp;
		temp = new Node;
		temp->num = x;
		temp->next = NULL;
		if (front == NULL)
			front = rear = temp;
		else
		{
			rear->next = temp;
			rear = temp;
		}
		cout << "\nElement Inserted"<<endl;
	}
	int Deque()
	{
		if (front == NULL)
			cout << "Error!, Queue is empty\n";
		else{
			Node *temp = front;
			front = front->next;
			int n = temp ->num;
			delete temp;
			return n;
		}
	}
	void showQueue()
	{
		if (front == NULL)
			cout << "Error!, Queue is empty\n";
		else{
			struct Node *temp = front;
			while (temp->next != NULL){
				cout << temp->num << "  ";
				temp = temp->next;
			}
			cout << temp->num << endl;
		}
	}
};

int main()
{
	queueList q1;
	int choice;
    do
    {
    	cout<<"\n\n1) Insert a value in the queue (Queue can have maximum 10 values)";
    	cout<<"\n2) Delete a value from the queue";
    	cout<<"\n3) Check to see if the queue is empty";
    	cout<<"\n4) Show the queue";
    	cout<<"\n5) Exit";
    	cout<<"\nChoice: ";
    	cin>> choice;
    	if(choice == 1)
    	{
			int value;
    		cout<<"Enter the value which you want to insert in the queue: ";
    		cin>> value;
    		q1.Enque(value);
		}
		else if(choice == 2)
		{
			if(q1.isEmpty())
		    {
		    cout<<"The queue is already empty";
		    }
		    else
		    cout<<q1.Deque()<<" is successfully deleted from the queue";	
		}
		else if (choice == 3)
		{
			if(q1.isEmpty())
			{
				cout<<"The queue is empty";
			}
			else 
			cout<<"The queue is not empty";
		}
		else if (choice == 4)
		{
			q1.showQueue();
		}
		else if (choice == 5)
		{
			exit(0);
		}
	}
	while(choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5);
}


