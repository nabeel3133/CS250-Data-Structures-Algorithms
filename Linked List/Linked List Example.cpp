#include<iostream>
using namespace std;

class LinkedList
{
	private:
	struct node
	{
		int data;
		node *next;
	}*head = NULL,	*tail = NULL;
	
	public:		
	int totalNodes()
	{
		int counter= 0;
		node *temp = head;
		{
			while(temp!=NULL)
			{
				temp = temp->next;
				++counter;
			}
		}
		return counter;
	}	
	
	void insertAtbegin(int x)
	{
		node *temp = new node;    //Making a new node
		temp->data = x;    //Entering data in the node
		if(head == NULL)   //List is empty. So entering the first node
		{
		head = temp;     //Making head equal to the new node
		tail = temp;     //Making head equal to the new node
		temp->next = NULL;       //Making the new node point to NULL as it is the only node in the list
		}
		else
		{
		temp->next = head;	   //the next in the new node will point to the head node
		head = temp;           //and the head was already pointing to some node that is why we made it equal to the new node so that it should point to the new node
		}	
	}
	
	void insertAtmiddle(int x)
	{
		node *temp = head;
		node *newNode = new node;
		newNode->data = x;
		int midpoint = totalNodes()/2;
		cout<<"Midpoint is: "<<midpoint<<endl;
		
		for(int i = 1; i<midpoint ;i++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	
	void insertAtend(int x)
	{
		node *temp = new node;
		temp->data = x;
		temp->next = NULL;
		if(head == NULL)   //List is empty. So entering the first node
		{
		head = temp;     //Making head equal to the new node
		tail = temp;     //Making head equal to the new node
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}		
	}
	
	void insert_at_specific(int x)
	{
		int node_pos;
		node *newNode = new node;
		newNode->data = x;
		cout<<"Enter the position of the node where you want to insert the value: ";
		cin>>node_pos;
		if(head == NULL)
		{
			cout<<"The list is empty. So the value is added at the first node";
			head = newNode;
			tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			node *temp = head;
			node *prev = head;
            int count = 0;
			while(++count != node_pos)
			{
				prev = temp;
				temp =temp->next;	
			}
			if (node_pos == 1 || temp == head)
			{		 
			newNode->next = head;              //If you want to insert a node at start
			head = newNode;
		    }
		    else if((node_pos > 0 && node_pos < totalNodes()) || temp->next!=NULL)          //If you want to insert in between
		    {
		    prev->next= newNode;
		    newNode->next = temp;
			}
			else if(totalNodes() == node_pos || temp->next == NULL)        //If you want to insert at last node
			{
			prev->next = newNode;
			newNode->next = temp;
			temp->next = NULL;
			}
	
		}
		cout<<"\n\nValue is successfully added at the "<<node_pos<<" node\n\n";
	}

		
	void deleteAll()
	{
		if(head == NULL)
		{
			cout<<"The list is empty";
		}
		else
		{
		    node *t1,*t2;
	        t1=head;
	        while(t1!=NULL)
			{
		    t2=t1;
		    t1=t1->next;
		    delete t2;
	        }
	    head=NULL;
	    tail=NULL;
		}
	}
	
	void delete_value_at_start()
	{
		node *temp = head;
	    head = temp->next;
	    delete temp;
	}
	
	void delete_value_at_middle()
	{
		node *temp = head;
		int midpoint = totalNodes()/2;
		cout<<"Midpoint is: "<<midpoint<<endl;
		
		for(int i = 1; i<midpoint ;i++)
		{
			temp = temp->next;
		}
		node *after = temp->next;
	    temp->next = after->next;
			
	}
	
	void delete_value_at_end()
	{
		node *temp=head;
		while(temp->next->next!= NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
	
	void delete_specifc()
	{
		int node_pos;
		cout<<"Enter the node which you want to delete: ";
		cin>>node_pos;
		if(head == NULL)
		{
			cout<<"The list is empty. First insert any value and then delete";
		}
		else
		{
			node *temp = head;
			node *prev = head;
            int count = 0;
			while(++count != node_pos)
			{
				prev = temp;
				temp =temp->next;	
			}
			if (node_pos == 1 || temp == head)
			{		 
			head = temp->next;             //If you want to delete the first node
			delete temp;
			temp = NULL;
		    }
		    else if((node_pos > 0 && node_pos < totalNodes()) || temp->next!=NULL)          //If you want to delete a node in between
		    {
		    prev->next = temp->next;
		    delete temp;
		    temp = NULL;
			}
			else if(totalNodes() == node_pos || temp->next == NULL)        //If you want to delete the last node
			{
			prev->next = NULL;			//Previous is pointing to the second last node 
			delete temp;				//temp is pointing to the last node
			temp = NULL;
			}
	    }
	}
	
	void showList()
	{
		node *temp=head;
		if(head==NULL)           //First Node is empty
  	    {
  	    cout<<"The list is empty"<<endl;	
	    }
	    else
	    {
		cout<<"The list is: \n";
	    }
	    while(temp!=NULL)          //Loop runs till the end of the list (means till the last node points to NULL)
	    {
		cout<<temp->data<<endl;        //output showing the data in the node 
		temp=temp->next;              //node points to the next node
	    }
	}
};


int main()
{
	LinkedList L1;
	L1.insertAtbegin(5);             cout<<"5 inserted at starting position\n";
	L1.insertAtbegin(6);             cout<<"6 inserted at starting position\n";
	L1.insertAtbegin(7);             cout<<"7 inserted at starting position\n";
	L1.showList();
	
	cout<<"\nCalling delete all nodes in the list function.\n";
	L1.deleteAll();
	cout<<"All the nodes are successfully deleted in the list"<<endl;
	L1.showList();
    cout<<"\n\n";
    L1.insert_at_specific(7);
    cout<<endl;
    L1.showList();
    
	L1.insertAtend(8);             cout<<"8 inserted at end position\n";
	L1.insertAtend(9);             cout<<"9 inserted at end position\n";
	L1.insertAtend(11);             cout<<"11 inserted at end position\n";
	L1.insertAtend(12);             cout<<"12 inserted at end position\n";
	
	L1.showList();	
	
	cout<<"\nTotal number of nodes in the list are: "<<L1.totalNodes()<<endl;	
	
	L1.insertAtmiddle(10);          cout<<"\n10 inserted at middle position\n";	
	L1.showList();
	
	cout<<"\n\n";
	
	L1.insert_at_specific(7);       	
	L1.showList();
	
	cout<<"\n\n";
	
	cout<<"Deleting value which was at the start\n";
	L1.delete_value_at_start();
	L1.showList();
	
	cout<<"\n\n";
	
	cout<<"Deleting value which was at the middle\n";
	L1.delete_value_at_middle();
	L1.showList();
	
	cout<<"\n\n";
	
	cout<<"Deleting value which was at the end\n";
	L1.delete_value_at_end();
	L1.showList();
	
	cout<<"\n\n";
	
	L1.delete_specifc();       	
	L1.showList();
	
}
