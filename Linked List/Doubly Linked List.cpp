#include<iostream>
using namespace std;

class nodes
{
	friend class DoublyLinkedList;
	
private:
	int data;
	nodes *next;
	nodes *prev;
	
public:
	nodes() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
	~nodes() 
	{ 
	}
};

class DoublyLinkedList
{
	private:
	nodes *first;
	nodes *last;
	nodes *current;

public:
	DoublyLinkedList() {
		first = NULL;
		last = NULL;
	}
	
	int totalNodes()
	{
		int counter= 0;
		current = first;
		{
			while(current!=NULL)
			{
				current = current->next;
				++counter;
			}
		}
		int total_nodes = counter;
		return total_nodes;
	}	
	
	void insert_at_begin(int d)
	{
		nodes *newptr = new nodes;
		newptr->data = d;
		newptr->prev = NULL;
		if(first == NULL)
		{
		first = newptr;	
		last = newptr;
		newptr->prev = NULL;
		}
		else
		{
			newptr->next = first;
			first->prev = newptr;
			first = newptr;
		}
	}
	
	void insert_at_middle(int d)
	{
		nodes *newptr = new nodes;
		newptr->data = d;
		current = first;
		int midpoint = totalNodes()/2;
		for(int i=1; i<midpoint; i++)
		{
			current = current->next;
		}	
		nodes *after = current->next;
		current->next = newptr;
		newptr->prev = current;
		newptr->next = after;
		after->prev = newptr;
	}
		
	void insert_at_end(int d)
	{
		nodes *newptr = new nodes;
		newptr->data = d;
		newptr->next = NULL;
		if(first == NULL)
		{
		first = newptr;	
		last = newptr;
		newptr->prev = NULL;
		}
		else
		{
			/*last->next = newptr;
			newptr->prev = last;       //Zain algorithm for insertion at end
			last = newptr; */
			current = first;
			while(current->next!=NULL)
			{
				current = current->next;
			}
			current->next = newptr;
			newptr->prev = current;
			last = newptr;
		}
	}
	
	void delete_all()
	{
		current = first;
		if(first == NULL)
		{
			cout<<"\nThe list is empty";
		}
		else
		{
			while(current!=NULL)
			{
				nodes *t1 = current;
				current = current->next;
				delete t1;
				t1 = NULL;
			}
			first = NULL;
			last = NULL;
		}
	}
	
	void delete_from_begin()
	{
		current = first;
		first = current->next;
		first->prev = NULL;
		if(current == NULL)
		{
			cout<<"The list is empty";
		}
		else
		{
		delete current;
		current = NULL;	
		}
	}
	
	int print_first()
	{
		return first->data;
	}
	int print_last()
	{
		return last->data;
	}
	
	void print_forward()
	{
		current = first;
		if(first == NULL)
		{
			cout<<"The list is empty";
		}
		else
		{
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current = current->next;
		}
		}
	}
	
	void print_backward()
	{
		current = last;
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current = current->prev;
		}
	}
};

int main()
{
	DoublyLinkedList L1;
	L1.insert_at_end(1);       cout<<"Inserting 1 at end";
	L1.insert_at_end(2);       cout<<"\nInserting 2 at end";
	L1.insert_at_end(3);       cout<<"\nInserting 3 at end";
	L1.insert_at_end(4);       cout<<"\nInserting 4 at end";
	L1.insert_at_end(5);       cout<<"\nInserting 5 at end";
	
	cout<<"\nPRINTING THE LIST IN FORWARD DIRECTION: \n";
	L1.print_forward();
	
	cout<<endl<<endl;
	
	cout<<"PRINTING THE LIST IN BACKWARD DIRECTION: \n";
	L1.print_backward();
	
	cout<<endl<<endl;
	cout<<"Deleting all nodes";
	L1.delete_all();
	
	L1.print_forward();
	
	L1.insert_at_begin(1);       cout<<"\n\nInserting 1 at begin";
	L1.insert_at_begin(2);       cout<<"\nInserting 2 at begin";
	L1.insert_at_begin(3);       cout<<"\nInserting 3 at begin";
	L1.insert_at_begin(4);       cout<<"\nInserting 4 at begin";
	L1.insert_at_begin(5);       cout<<"\nInserting 5 at begin";
	
	cout<<endl<<endl;
	cout<<"\nPRINTING THE LIST IN FORWARD DIRECTION: \n";
	L1.print_forward();
	
	cout<<endl<<endl;
	cout<<"PRINTING THE LIST IN BACKWARD DIRECTION: \n";
	L1.print_backward();
	
	cout<<endl<<endl;
	cout<<"The first number in the list is: ";
	cout<<L1.print_first();
	
	cout<<endl<<endl;
	cout<<"The last number in the list is: ";
	cout<<L1.print_last();
	
	L1.insert_at_middle(7);       cout<<"\n\nInserting 7 at middle";
	L1.insert_at_middle(8);         cout<<"\n\nInserting 8 at middle";
	L1.insert_at_middle(9);         cout<<"\n\nInserting 9 at middle";
	L1.insert_at_middle(10);        cout<<"\n\nInserting 10 at middle";
	L1.insert_at_middle(11);        cout<<"\n\nInserting 11 at middle";
	
	cout<<endl<<endl;
	cout<<"\nPRINTING THE LIST IN FORWARD DIRECTION: \n";
	L1.print_forward();
	
	cout<<endl<<endl;
	cout<<"PRINTING THE LIST IN BACKWARD DIRECTION: \n";
	L1.print_backward();
	
	L1.delete_from_begin();        cout<<"\n\nDeleting from begin";  
    L1.delete_from_begin();        cout<<"\nDeleting from begin";  
    L1.delete_from_begin();        cout<<"\nDeleting from begin";  
    L1.delete_from_begin();        cout<<"\nDeleting from begin";  
    L1.delete_from_begin();        cout<<"\nDeleting from begin";  
    
    cout<<endl<<endl;
	cout<<"\nPRINTING THE LIST IN FORWARD DIRECTION: \n";
	L1.print_forward();
	
	cout<<endl<<endl;
	cout<<"PRINTING THE LIST IN BACKWARD DIRECTION: \n";
	L1.print_backward();

}
