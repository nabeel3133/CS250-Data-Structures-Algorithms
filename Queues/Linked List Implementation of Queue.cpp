#include<iostream>
using namespace std;

class QueueList
{
	private:
	struct Node
	{
		int value;
		Node *next;
	}*front = NULL, *rear = NULL, *temp;
	
	public:	
	bool isEmpty()
	{
		if(front == NULL && rear == NULL)
		return 1;
		else 
		return 0;	
	}

	void Enqueue(int x)
	{
		temp = new Node;
		temp->value = x;
		temp->next = NULL;
		if (isEmpty())
			front = rear = temp;
		else
		{
			rear->next = temp;
			rear = temp;
		}
		cout << x << " is successfully entered in the queue.";
	}
	
	int Dequeue()
	{
		temp = front;
		if(front == rear) //Queue has only one element
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		int deletedValue = temp->value;
		delete temp;
		return deletedValue;
	}
	
	void showQueue()
	{
			temp = front;
			cout<<"Queue:  ";
			while (temp!= NULL)
			{
				cout << temp->value << "  ";
				temp = temp->next;
			}
	}
	
};

int main()
{
	QueueList q1;
	int choice;
    do
    {
    	cout<<"\n\n1) Insert a value in the queue";
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
    		q1.Enqueue(value);
		}
		else if(choice == 2)
		{
			if(q1.isEmpty())
		    {
		    cout<<"The queue is already empty";
		    }
		    else
		    cout<<q1.Dequeue()<<" is successfully deleted from the queue";	
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
			if(q1.isEmpty())
			{
				cout<<"There is nothing to show as the queue is empty. Insert some values first and then show the queue";
			}
			else
			{
			q1.showQueue();
			}
		}
		else if (choice == 5)
		{
			exit(0);
		}
	}
	while(choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5);
}

