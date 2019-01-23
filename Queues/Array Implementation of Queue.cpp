/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Data Structures And Algorithms
Lab 5
Task 1
Array Implementation of Queue
*/

#include<iostream>
using namespace std;
#define MAX 5 //maximum size of the array that will store Queue. 

class Queue
{
	private:
	int queue[MAX];
	int front;
	int rear;
	
	public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	
	int first_Element()
	{
		return queue[front];
	}
	 
	bool isEmpty()
	{
		if(rear == -1 && front == -1)
		return 1;
		else 
		return 0;
	}
	
	bool isFull()
	{
		if((rear+1)%MAX == front)
		return 1;
		else 
		return 0;
	}
	void Enque(int x)
	{			
	    if(isEmpty())
		{
			front = rear = 0;
			cout<< x <<" is successfully entered in the queue";	
		}
		else if(isFull())
		{
			cout<<"Queue is already full."<<endl;
			return;
		}
		else
		{
			rear = (rear+1)%MAX;
			cout<< x <<" is successfully entered in the queue";	
		}
		queue[rear]=x;
	}
	
	int Deque()
	{
		int temp;
		if(front == rear)    //Queue has only one element
		{
			temp = queue[front];
			front = rear = -1;				//Queue will now be empty after dequeing
		}
		else
		{
		    temp = queue[front];		
			front = (front+1)%MAX;		
	    }	
		return temp;	
	}
	void showQueue()
	{
		if(isEmpty())
		{
			cout<<"The queue is empty";
		}
		else
		{
		   int count = (rear+MAX-front)%MAX + 1;
		   cout<<"Queue:  ";
		   for(int i = 0; i <count; i++)
		   {
			int index = (front+i) % MAX; // Index of element while travesing circularly from front
			cout<<queue[index]<<" ";
		   }
		   cout<<"\n\n";	
		}		
	}
	
};

int main()
{
	Queue q1;
	int choice;
    do
    {
    	cout<<"\n\n1) Insert a value in the queue (Queue can have maximum 10 values)";
    	cout<<"\n2) Delete a value from the queue";
    	cout<<"\n3) Check to see if the queue is empty";
    	cout<<"\n4) Check to see if the queue is full";
    	cout<<"\n5) Show the queue";
    	cout<<"\n6) See the first element of the queue";
    	cout<<"\n7) Exit";
    	cout<<"\nChoice: ";
    	cin>> choice;
    	if(choice == 1)
    	{
            if(q1.isFull())
	        {
		    cout<<"The queue is already full";
		    }
		    else
		    {
			int value;
    		cout<<"Enter the value which you want to insert in the queue: ";
    		cin>> value;
    		q1.Enque(value);
		    }
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
			if(q1.isFull())
			{
				cout<<"The queue is full";
			}
			else 
			cout<<"The queue is not full";
		}
		else if (choice == 5)
		{
			q1.showQueue();
		}
		else if(choice == 6)
		{
			cout<<"The first element of the queue is: "<<q1.first_Element();
		}
		else if (choice == 7)
		{
			exit(0);
		}
	}
	while(choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5 || choice != 6);
}
