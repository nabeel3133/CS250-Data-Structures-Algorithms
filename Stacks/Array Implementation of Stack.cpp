#include<iostream>
using namespace std;
#define size 10

class stack
{
	private:
	int A[size];
	int top = -1;
	
	public:
	void push(int value)
	{
		top++;
		A[top]=value;
	}
	
	int pop()
	{
		int pop_value = A[top];
		top--;
		return pop_value;
	}
	
	int Top()
	{
		int top_value = A[top];
		return top_value;
	}
	
	bool isEmpty()
	{
		if(top == -1)
		{
		cout<<"The stack is empty";
		return 1;
		}
		else 
		{
		cout<<"The stack is not empty";
		return 0;
		}	
	}
	
	bool isFull()
	{
		if(top == size-1)
		{
			cout<<"The stack is full";
		}
		else
		{
		    cout<<"The stack is not full";
		}
	}
	
	void display()
	{
	    if(top == -1)
	    {
	    	cout<<"\nThe stack is empty";
		}
		else
		{
		  cout<<"The stack is: "<<endl;
		  for(int i=top; i>=0; i--)
		  {
		  cout<<A[i]<<endl;
		  }	
		}
		
	}
};

int main()
{
	stack s1;
	cout<<"Checking whether the stack is empty or not!\n";
	s1.isEmpty();
	
	cout<<"\n\n";
	
	s1.push(1);          cout<<"1 is pushed\n";
	s1.push(2);          cout<<"2 is pushed\n";
	s1.push(3);          cout<<"3 is pushed\n";
	s1.push(4);          cout<<"4 is pushed\n";
	s1.push(5);          cout<<"5 is pushed\n";
    s1.push(6);          cout<<"6 is pushed\n";
	s1.push(7);          cout<<"7 is pushed\n";
    s1.push(8);          cout<<"8 is pushed\n";
	s1.push(9);          cout<<"9 is pushed\n";
	s1.push(10);          cout<<"10 is pushed\n";
								
	
	cout<<"\n\n";
	
	cout<<"Value at the top of the stack is: "<<s1.Top();
	
	cout<<"\n\n";
	
	cout<<"Checking whether the stack is full or not!\n";
	s1.isFull();
		
	cout<<"\n\nChecking whether the stack is empty or not!\n";
	s1.isEmpty();
	
	cout<<"\n\n";
	
	s1.display();
	
	cout<<"\n\n";
	
	cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
    cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
    cout<<s1.pop()<<" is popped\n";	
	cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
	cout<<s1.pop()<<" is popped\n";
	
	cout<<"\n\n";
	cout<<"Checking whether the stack is empty or not!\n";
	s1.isEmpty();
	
	cout<<"\n\n";
	cout<<"Displaying: \n";
	s1.display();
}
