/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class LinkedList             //Class Definition and Declaration
{
	private:
	class node           //Class to get nodes
	{
		public:
		int number;           //Number in node to add or delete
		node *next;             //Next node
		node()      
		{
			next=NULL;
		}
	};
	node *head=NULL;       //First node set equal to NULL 
	node *head2;           //Need for splitting of the list
    int totalNodes;        //Total nodes
	public:
	bool flagAdd;
	List()            
	{
		flagAdd=0;
		head=NULL;
	}
void showing()            //Showing Function which shows the list of numbers
{
  	node *ptr=head;
  	if(ptr==NULL)           //First Node is empty
  	{
  	cout<<"The list is empty"<<endl;	
	}
	else
	{
		cout<<"The list is: \n";
	}
	while(ptr!=NULL)          //Loop runs till the first node becomes equal to NULL
	{
		cout<<ptr->number<<endl;        //output shows the number in the first node
		ptr=ptr->next;              //head node becomes equal to the next node
	}
}	

int numOfnodes()           //Function to find the total number of nodes
{
        node *ptr = head;    //Pointer node delcared and set equal to the first node
        int counter = 0;         //Counter integer declared which will count the total number of nodes
        while(ptr!= NULL)           //While the first Node becomes equal to NULL
		{
            ptr=ptr->next;          //First nodes becomes equal to the next node and so on
            counter++;                //Counter value incremented by 1
        }
       totalNodes=counter;           //Total nodes set equal to counter 
        return totalNodes;
}

void insertAtbegin(int number)           //Function to insert a node or number at the beginning of the list
{
	node *p=head;                //Pointer node delcared and set equal to the first node
	while(p!=NULL)               //Loop runs till the first node becomes equal to NULL
		{
			if(p->number==number)              //The number being entered is the same as that of the number in the node 
			{
				cout<<"This number is already in the list\n";
				cout<<"Enter another number: ";
				cin>>number;                     //Taking input from the user again
				p=head;                   //The pointer which was declared is again set to first node
			}
			else
			p=p->next;            //Else the first pointer becomes equal to the next pointer
		}
	node *add=new node();      //Making a new node (Here constructor is called by which the next node becomes equal to NULL)
	add->number = number;      //The number which is entered by the user becomes equal to the number in the new node made
	add->next = NULL;
	if(head==NULL)                 //If there is no number in the first node
	{
	head = add;         //New node becomes equal to that of the first node
	flagAdd=1;
	system("cls");
    }
	else
	{
		add->next=head;                  //First node becomes equal to next node
		head=add;                        //New node becomes equal to first node
		node *ptr=head;                //First node becomes equal to ptr(A new declared pointer node)
		while(ptr!=NULL)            //Loop runs till the first node becomes NULL
		{
		ptr=ptr->next;               //First node becomes next node and so on
		}
    }
}
void insertAtmiddle(int number)            //Function to insert a node or number at the middle of the list
{                 
        node *p=head;                //Pointer node delcared and set equal to the first node
        while(p!=NULL)                //Loop runs till the first node becomes equal to NULL
		{
			if(p->number==number)         //The number being entered is the same as that of the number in the node
			{
				cout<<"This number is already in the list\n";
				cout<<"Enter another number: ";
				cin>>number;                          //Taking input from the user again
				p=head;                            //The pointer which was declared is again set to first node
			}
			else
			p=p->next;              //Else the first node pointer becomes equal to the next node pointer
		}
            node *add = new node();  //Making a new node (Here constructor is called by which the next node becomes equal to NULL)
            add->number=number;   //The number which is entered by the user becomes equal to the number in the new node made
            numOfnodes();         //Function called to get the total number of nodes
            int midpoint = (totalNodes/2) - 1;              //Finding midpoint for the list
            node *ptr = head;         //Pointer node delcared and set equal to the first node
            
            if(ptr==NULL)         //If first node is equal to NULL
			{
                head=add;      //First node becomes equal to the new node which is to be added
            }
            else
			{
                for(int i=0; i<midpoint; i++)              //Loop runs till midpoint of the list comes
				{
                    ptr = ptr->next;      //First nodes becomes equal to the next node till the mipoint
                }
                node *after = ptr->next;     //Next node after the midpoint becomes equal to the "after" node declared
                add->next=after;          //new node points to the next node and is set equal to the after node
                ptr->next=add;            //Next node after the midpoint node is set equal to the new node
            }
            
}
void insertAtend(int number)     //Function to insert a number at the middle of the list
{       node *p=head;            //Pointer node delcared and set equal to the first node
		while(p!=NULL)           //Loop runs till the first node becomes equal to NULL
		{
			if(p->number==number)        //The number being entered is the same as that of the number in the node
			{
				cout<<"This number is already in the list\n";
				cout<<"Enter another number: ";
				cin>>number;       //Taking input from the user again
				p=head;            //The pointer which was declared is again set to first node
			}
			else
			p=p->next;         //Else the first node pointer becomes equal to the next node pointer
		}
	node *add=new node();   //Making a new node (Here constructor is called by which the next node becomes equal to NULL)
	add->number=number;      //The number which is entered by the user becomes equal to the number in the new node made
	if(head==NULL)      //If first node is equal to NULL
	{
	head=add;             //First node becomes equal to the new node which is to be added
	flagAdd=1;
	system("cls");
	}	
	else
	{
		node *ptr=head;               //Pointer node delcared and set equal to the first node
			while(ptr->next!=NULL)        //Loop runs till the node after first node becomes equal to NULL
			{
				ptr=ptr->next;      //First node becomes equal to the next node
			}
			ptr->next=add;       //The new node which is to be added becomes equal to the node at the end
	}
	flagAdd=1;
	system("cls");
}	
void deletefromBegin()         //Function to delete a node or number from beginning
{
	node *del;         //A new del node declared 
	numOfnodes();        //Function called to get the total number of nodes
	if(head==NULL)     //If the first node is equal to NULL
	{
		cout<<"The list is empty at the moment. First add any node and then select this option";
	}
	else if(head!=NULL)        //If the first node is not equal to NULL
	{
		del=head;              //First node is set equal to the del node
		head=head->next;       //First node is set equal to the next node
		cout<<"The number which was at start position was successfully deleted from the list"<<endl;
	}
}
void deletefromMiddle()      //Function to delete a node or number from middle of the list
{         
    if(head==NULL)            //If the first node is equal to NULL
	{
		cout<<"The list is empty at the moment. First add any node or number and then select this option\n";
	}
	else
	{
		numOfnodes();             //Function called to get the total number of nodes
		if(totalNodes==1)     //If the total number of nodes are 1
		{
			cout<<"There is only one number present in the list. Add more than one node or number and then\nchoose this option\n\n";
			menu();
		} 
            node *del=head;             //A new node pointer declared and set equal to the first node               
            int midpoint = totalNodes/2 - 1;          //Getting the midpoint of the list
            for(int i = 0; i < midpoint; i++)        //Loop runs till we get to the midpoint of the list
			{
            del = del->next;           //Till the midpoint is reached the first node points to the next node
            }
            del->next=del->next->next;     
            cout<<"The number which was at middle position was successfully deleted from the list\n"<<endl;
    }
}
void deletefromEnd()         //Function to delete a node or number from end of the list
{
	if(head==NULL)             //If the first node is equal to NULL
	{
		cout<<"The list is empty at the moment. First add any node or number and then select this option\n";
	}
	else
	{
		numOfnodes();
		if(totalNodes==1)           //If the total number of nodes is 1
		{
			cout<<"There is only one number present in the list. Add more than one node or number and then\nchoose this option\n\n";
			menu();
		}
		node *del=head;                //New node pointer declared is equal to the first node
		while(totalNodes!=2)            
		{
			del=del->next;
			totalNodes--;
	    }
	    del->next=NULL;
	cout<<"The number which was at last position was successfully deleted from the list\n"<<endl;
	}
}

void deleting(int number)
{
	node *del;
	bool found=0;
	node *temp=head;
	if(head==NULL)               //If there are no numbers present in the list
	{
		cout<<"List is empty at the moment. First add any node then choose this option"<<endl;
		menu();
	}
	else if(head->number==number)           //If number which is entered by the user is also at starting node
	{
		del=head;              //First node is equal to del node declared
		head=head->next;       //First node is set equal to the next node
		cout<<"The number is successfuly deleted from the list\n";
	}
	else
	{ 
	while (temp->next!=NULL)
			{
				if (temp->next->number==number)
				{
					found=1;
					break;
				}
				else
				{
					temp=temp->next;
				}
			}
			if (found==1)      //Number is present in the list
			{
				del=temp->next;
				temp->next=temp->next->next;
				cout<<"Number is successfully deleted from the list"<<endl;
			}
			else          //Number is not present in the list
			{
				cout<<"The number which you want to delete is not present in the list"<<endl;
				menu();
			}
		}
}
void SORT()     //Sort function defined which sorts the list in ascending order
{
   bool changeMade;
do{
    changeMade = 0;
   node *current = head;           //New node pointer declared and set equal to the first node
   node *temp;
    while(current)           //Loop runs till current node or the first node becomes equal to NULL
	{
        temp = current;           //Temp node pointer is set equal to the first node
        current = current->next;       //first node is set equal to the next node

        if( current && current->number < temp->number )      //If the number in the first node is less than the number in the next node
		{
            changeMade = 1;         
            swap( temp->number, current->number );         //Swapping the numbers
        }
    }
  } while(changeMade);
}
void SPLIT()          //Split function to split the a list into two parts
{
	node *split;
    int count=0,temp=0;
    if(totalNodes==0)        //If the total number of nodes are zero
	{
		cout<<"First add some numbers in the list, then choose this option!";
		menu();           //Calling menu function
	}
	else if(totalNodes==1)        //If the total number of nodes are one
	{
		cout<<"There is only one number in the list. Add more than one numbers in the list and then choose this option!";
		menu();         //Calling menu function
	}
    else
  {
    split=head;           //First node is set equal to the split node defined
	while(split!=NULL)      //Loop runs till the first node becomes equal to NULL
    {
    count++;                  //Count value is incremented by 1 everytime the loop runs
    split=split->next;        //First node becomes equal to next node and this happens till the loop is terminated
    }
    temp=count/2;          //Temp integer gets the value of count divided by 2
    int count1=1;  
	split=head;
    while(split!=NULL && count1!=temp)            //Loop runs till the splited node becomes equal to NULL and count1 becomes equal to temp
    {
    split=split->next;            //Split node is set equal to the next node till the loop terminates
    count1++;         //Count1 value is incremented by 1 everytime the loop runs
    }
    head2=split->next;         //Head2 node is set equal to the next node which the splitted node is pointing to
    split->next=NULL;          //The next node which the splitted node was pointing to is set equal to NULL
  }
}
void front_part()      //Display function to display the front part of the list after splitting a list into two parts
{
    node *ptr;         //A node pointer delcared
    ptr=head;              //The node pointer which was declared is set equal to the first node
    while(ptr!=NULL)        //Loop runs till the first node becomes equal to NULL
    {
    cout<<ptr->number<<endl;         //Giving the output of the number in the first node     
    ptr=ptr->next;       //The first node is set equal to the next node
    }
}
void back_part()     //Display function to display the back part of the list after splitting a list into two parts
{
    node *ptr1;         //A node pointer delcared
    ptr1=head2;            //The node pointer which was declared is set equal to the first node of the back part of the splitted list
    while(ptr1!=NULL)     //Loop runs till the first node of the back part of the splitted list becomes equal to NULL
    {
    cout<<ptr1->number<<endl;     //Giving the output of the number in the first node  of the back part of the splitted list
    ptr1=ptr1->next;           //The first node of the back part of the splitted list is set equal to the next node of the back part of the splitted list
    }
}
void SortedINSERT(int number)     //Sorted Insert function defined which takes a node and adds it in the list and also sorts the lit in ascending order
{      
     node *p=head;          //A node pointer delcared and is set equal to the first node     
     while(p!=NULL)         //Loop runs till the first node becomes equal to NULL
		{
			if(p->number==number)         //If the number in the first node is equal to the number input by the user
			{
				cout<<"This number is already in the list\n";
				cout<<"Enter another number: ";
				cin>>number;     //Taking input again from user
				p=head;     //node pointer is again set equal to the first node
			}
			else
			p=p->next;         //Otherwise it will be equal to the next node till the loop terminates
		}
   
        node *add = new node();      //New node is made and is set equal to the node pointer add
        add->number=number;   //The number which was input by the user is set equal to the number in the new node
        if(head == NULL)   //If the first node is empty
		{     
            head = add;      //New added node becomes equal to the first node
        }
        else if(head->number > number)    //If the number in the first node is greater than the number input by the user
		{	
            add->next=head;    //Next node becomes equal to the first node
            head = add;         //The new node which was to be added is set equal to the first node
        }
        else
		{
            node* current = head;              //New node pointer is declared and set equal to first node
            while (current->next->number < number)   //Loop runs till the number in the next node is less than the number entered by the user
			{
                current = current->next;       //Current node is set equal to the next node
                if (current->next == NULL)      //If the next node is NULL
				{
                    break;
                }
            }
            add->next=current->next;      //The new node which was to be added points to the next node after it and is set equal to the next node after current
            current->next=add;         //The new node is set equal to the next node after current  
        }
    
}
void appending(LinkedList L)
{
	if(L.head==NULL)     //If the list being appended is empty
	{
		cout<<"The list which was to be appended is empty!";
	}
	else
	{
            node *append = new node();        //A new node pointer is declared which makes a new node
			append= head;         //The node pointer which was declared is now set equal to the first node
			while (append->next != NULL)   //Loop runs till the next node after the new declared node becomes equal to NULL
			{
			append = append->next;    //First node becomes equal to the next node till the loop terminates
			}
			append->next = L.head;   //When the loop ends, the node has reached to the end, and is set equal to the head of the appending node
		}
}
 
void menu()       //Menu function which shows different options and menu to the user
{
	cout<<"\n\nMenu for the 3rd List:  "<<endl;
	cout<<"1) Add a number in the list (End Position)"<<endl;
	cout<<"2) Add a number at start position of the list"<<endl;
	cout<<"3) Add a number at middle position of the list"<<endl;
	cout<<"4) Delete a number"<<endl;
	cout<<"5) Delete a number from start position of the list"<<endl;
	cout<<"6) Delete a number from middle position of the list"<<endl;
	cout<<"7) Delete a number from end position of the list"<<endl;
	cout<<"8) Sort the list in ascending order"<<endl;
	cout<<"9) Add a number and see the list in ascending order"<<endl;
	cout<<"10) Show the list of numbers "<<endl;
	cout<<"11) Split the list into two parts"<<endl;
	cout<<"12) Exit"<<endl;
	cout<<"Enter your choice: ";
	options();
}
void options()                 //Giving Options to user
{
	int number;           //Number integer defined so that the user can add or delete node
	int optionSelection;            //Option selection integer defined so that the user can choose an option from the menu
	cin>>optionSelection;
	switch (optionSelection)
   {
	    case(1):
	    {
		cout<<"Enter the number which you want to add in the list: ";
        cin>>number;
        insertAtend(number);             //Calling insert function to insert a node or number at the end of the list
        if(flagAdd==1)
	    {
		cout<<"The list has been successfully stored";
	    }
	    menu();            //Menu function called
	    break; 
        }
	    case(2):
		{
		cout<<"Enter the number which you want to add in the start position: ";
		cin>>number;
		insertAtbegin(number);             //Calling insert function to insert a node or number at the beginning of the list
		   if(flagAdd==1)
	       {
		cout<<"The list has been successfully stored";
	       }
	    menu();           //Menu Function called
	    break;
	    }
	    case(3):
		{
		cout<<"Enter the number which you want to add in the middle position: ";
		cin>>number;
	    insertAtmiddle(number);     //Calling insert function to insert a node or number at the middle of the list
	    if(flagAdd==1)
	       {
		cout<<"The list has been successfully stored";
	       }
	    menu();       //Menu function called
        }
        case(4):
        {
        cout<<"Enter the number which you want to delete from the list: ";
		cin>>number;
		deleting(number);        //Calling deleting function to delete a number or node by the users choice
		if(flagAdd==1)
	       {
		   cout<<"The list has been successfully stored";
	       }
		menu();          //Menu Function called
		break;	
		}
		case(5):
		{
		deletefromBegin();   //Calling deleting function which will delete a node or number from the beginning of the list
		   if(flagAdd==1)
	       {
		   cout<<"The list has been successfully stored";
	       }
	       menu();		//Menu Function called
		}
	    case(6):
		{
		deletefromMiddle();   //Calling delete function to delete a node or number from the middle of the list
		if(flagAdd==1)
	        {
		    cout<<"The list has been successfully stored";
	        }
	        menu();        //Menu Function called
		    break;
	    }
	    case(7):
	    {
	    	deletefromEnd();     //Calling delete function to delete a node or number from the end of the list
			if(flagAdd==1)
	        {
		    cout<<"The list has been successfully stored";
	        }
	        menu();      //Calling menu function
			break;
		}
		case(8):
		{
			SORT();         //Calling SORT function which will sort the list in ascending order
			cout<<"In Ascending order\n";
			showing();     //Calling showing function which will show the list of numbers
			menu();      //Calling menu function
			break;	
		}
		case(9):
		{	
		cout<<"Enter the number which you want to add in the list and see the list\nin ascending order: ";
		cin>>number;
		SORT();           //Calling SORT function which will sort the list in ascending order
		SortedINSERT(number);   //Called SortedINSERT function which will add a node or number and sort the list in ascending order aswell
		cout<<"In Ascending order\n";
		showing();           //Calling showing function to show the list of numbers
		menu();             //Calling menu function
		}
		case(10):
		{
		showing();         //Calling showing function to show the list of numbers
	    menu();          //Calling menu function
        }
		case(11):
		{
		SPLIT();              //Calling split function which will split the list into two parts
		cout<<"After splitting the list!\n";
		cout<<"Front part: \n";
		front_part();           //Dsiplaying the first list after splitting
		cout<<"\nBack part: \n";
		back_part();          //Displaying the second list after splitting
		menu();          //Calling function
		}
		case(12):
		{
		exit(0);        //Exiting program
		}
		default:
		{
		cout<<"Invalid Input."<<endl;
		menu();
		}   
	}
}
	
};
int main()
{
	LinkedList L1,L2,L3;           //3 objects made for the class of LinkedList
		char option;
		int num;
	cout<<"Asking the numbers to add for the two lists after which the second list will be appended to the first!\n\n";
	do
	{
		cout<<"Do you want to add a number in the first list? (Y/N): ";
		cin>>option;
		if(option=='y'||option=='Y')
		{
			cout<<"Enter the number which you want to add in the list: ";
			cin>>num;
			L1.insertAtend(num);     //Calling function for the first object of class LinkedList to insert a number or node
			L1.showing();        //Showing the list of numbers for the first object of class LinkedList
		}
		else
		break;
	}
	while(option!='y'||option!='Y');
	
	do
	{
		cout<<"Do you want to add a number in the second list? (Y/N): ";
		cin>>option;
		if(option=='y'||option=='Y')
		{
			cout<<"Enter the number which you want to add in the list: ";
			cin>>num;
			L2.insertAtend(num);      //Calling function for the second object of class LinkedList to insert a number or node
			L2.showing();         //Showing the list of numbers for the second object of class LinkedList
		}
		else
		break;
	}
	while(option!='y'||option!='Y');

    L1.appending(L2);   //Calling appending function
	cout<<"\nAfter Appending second list to the first\n";
	L1.showing();       //After appending showing the list of the numbers of the first object of class LinkedList which is now appended
	L3.menu();        //Showing the menu for the third object of the class LinkedList
}

