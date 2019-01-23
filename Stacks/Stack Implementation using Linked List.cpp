#include<iostream>
using namespace std;

class stackList
{
	private:
	struct node
	{
		int data;
		node *next;	
	}*top=NULL;
    
    public:
    void push(int value)
    {
    	node *temp = new node;
    	temp->data = value;
    	if(top == NULL)
    	{
    	top = temp;
    	temp->next = NULL;	
		}
		else
		{
		temp->next=top;
		top = temp;
		}

	}
	
	int pop()
	{
		int pop_value = top->data;
		node *temp = top;
		top = top->next;
		delete temp;
		temp = NULL;
		return pop_value;
	}
	
	int Top()
	{
	   int top_value = top->data;
	   return top_value;
	}
	
	bool isEmpty()
	{
		if(top == NULL)
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
	
	void display()
	{
		node *temp = top;
		if(temp==NULL)
		cout<<"The stack is empty"<<endl;
		else
		{
			cout<<"The stack is: "<<endl;
			while(temp!=NULL)
			{
			cout<<temp->data<<endl;
			temp = temp->next;
			}
		}

	}
	
	
	
};

int main()
{
	stackList s1;
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
