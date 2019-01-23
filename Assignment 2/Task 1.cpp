/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Data Structures And Algorithms
Assignment 2
TASK 1
Compiled and executed perfectly on Dev C++ as well as Visual Studio 2015
*/
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


class HashTable
{
	private:
	static const int table_size = 26;				//Indexes in the array
	int total_names;								//Total number of items or names in the dictionary
	
	struct Dict
	{
		string name;
		Dict *next;
	};	
	Dict* Dictionary[table_size];
	
	
	int Hash(string Person_name)		   //TASK 1: PART(5)		//Takes a string stored in the variable key and returns the index of that key. Index will be used to store the information of the key in the array.
	{
	int hash_value = 0;								 //If the key has a hash value of 453 then that value will be divided with the table size, let's say table size is 100 and the remainder will be the index which will be 53. At index 53 in the array the information of the key will be stored.
	int index;									//Hash Value is actually the sum of the ASCII values of the alphabets of the key.
	
	int k = 0;
	for(int i=0; i<Person_name.length(); i++)
	{
	//	cout<<"\nPerson_name["<<k<<"]"<<" = "<<Person_name[i];
		k++;
	}
	
//	cout<<endl;
	
	int j = 0;
	for(int i=0; i<Person_name.length(); i++)
	{
	//	cout<<"ASCII value of Person_name["<<j<<"]"<<" = "<<(int)Person_name[i]<<endl;
		j++;
	}
	
//	cout<<endl;
	
	int h = 0;
	for(int i=0; i<Person_name.length(); i++)				//Person_name.length returns an integer value which is the length of the string that was passed
	{
		hash_value = hash_value + (int)Person_name[i];
	//	cout<< "Hash Value at Person_name["<<h<<"] = "<<hash_value<<endl;
		h++;
	}
		
//	cout<<endl;
					
	index = hash_value % table_size;					//Index is the remainder of the hash_value (Sum of ASCII values of the string alphabets) with the Table_size (which is 100).
	// cout<<"The index value of " <<Person_name<< " is: "<<index<<endl;
	return index;
	}
	
	
	public:
	HashTable(int tSize)									//Constructor is called when an object of class HashTable is instantiated.
	{
		total_names = 0;									//Initializing total_names equal to zero.
		Dictionary[tSize];									
		for(int i=0; i<table_size; i++)						//Loop runs equal to the number of times of table size
		{
			Dictionary[i] = new Dict;						//A new item is made
			Dictionary[i]->name = "NULL";					//Name of the item is set as empty
			Dictionary[i]->next = NULL;						//The next pointer to that is set equal to NULL
		}
	}
		

	void Add(string Person_name)				//TASK 1: PART(1)
	{
		int index = Hash(Person_name);					//Calling Hash function so that we can specify the index of the person's name where we will store the information of that specific person in the array
		
		if(Dictionary[index]->name == "NULL")		//This condition is used when we have not yet stored any information of any person in that index.
		{
			Dictionary[index]->name = Person_name;
			cout<<"\n"<<Person_name<<" is successfully added in the dictionary";
		}
		else									//This condition will be used for chaining
		{
			Dict* Ptr = Dictionary[index];		//Declaring a pointer variable of item struct and initializing it with the above calculated index of the Dictionary array
			Dict* n = new Dict;
			n->name = Person_name;
			n->next = NULL;
			while(Ptr->next != NULL)			//Loop runs till the last pointer of the list
			{
				Ptr = Ptr->next;
			}
			Ptr->next = n;
			cout<<"\n"<<Person_name<<" is successfully added in the dictionary";								
		}		
	}  
	
	
	void Remove(string Person_name)				//TASK 2: PART(2)
	{
		int index = Hash(Person_name);				//Getting the index of the person which is to be removed using the Hash function
		
		Dict *delPtr;
		Dict *Ptr1;
		Dict *Ptr2;
		
		//Case 0 - Bucket that we're looking into is empty
		if(Dictionary[index]->name == "NULL")
		{
			cout<<Person_name<<" dosenot exist in the Dictionary"<<endl;
		}
		
		//Case 1 - Only one item is in the bucket and that item has matching name
		else if (Dictionary[index]->name == Person_name && NumberOfItemsInIndex(index) == 1)
		{
			Dictionary[index]->name = "NULL";
			cout<<"\""<<Person_name<<"\""" is removed from the Dictionary"<<endl;
		}
				
		//Case 2 - Match is located in the first item in the bucket but there are more items in the bucket
		else if(Dictionary[index]->name == Person_name)
		{
			delPtr = Dictionary[index];						//Bucket that we're looking. delPtr is now pointing to the very first pointer inside the bucket that we're looking into and that would be the item with the matching name.
			Dictionary[index] = Dictionary[index]->next;		//Making sure that the very first item referenced by the bucket that we're looking into actually points to the very next item because we're about to delete this first item.
			delete delPtr;
			cout<<"\""<<Person_name<<"\""" is removed from the Dictionary"<<endl;
		}
		
		//Case 3 - Bucket contain items but the first item is not a match
		else
		{
			Ptr1 = Dictionary[index]->next;					//Ptr1 is now pointing to the second item in the bucket or index
			Ptr2 = Dictionary[index];						//Ptr2 is now pointing to the first item in the bucket or index that we're looking into
			
			while(Ptr1 != NULL && Ptr1->name != Person_name)			//This loop will runs as long as we're pointing to some item and that item isn't the item that we're looking for. 
			{
				Ptr2 = Ptr1;				//Simply advancing Ptr2 one item forward.	
				Ptr1 = Ptr1->next;			//Also simply advancing Ptr1 one item forward.
			}
			
			//Case 3a - Looked at all the items in the bukcet but there is no match
			if(Ptr1 == NULL)		//Didn't find a match and we've looked through the whole list in the while loop
			cout<<"\""<<Person_name<<"\""" doesnot exist in the Dictionary"<<endl;
			
			//Case 3b - Match is found
			else				//Means name is found
			{
			delPtr = Ptr1;				//delPtr is now pointing to the item that we want to delete.
			Ptr1 = Ptr1->next;			//Ptr1 points to the very next item in the list.
			Ptr2->next = Ptr1;			//As we want to remove the item that Ptr1 was pointing to which is also referenced by Ptr2->next, so Ptr2->next now references the next pointer that Ptr1 is now pointing to.
			delete delPtr;
			cout<<"\""<<Person_name<<"\""" is removed from the Dictionary"<<endl;
			}
		} 		
	}
	
	bool Contains(string Person_name)				//TASK 1: PART(3)
	{
			int index = Hash(Person_name);				//Returns the sum of the ASCII values of the alphabets of the strings passed to this function whose value is being sotred in the index integer
			bool flag = false;						//Initilizing check bool with false
			Dict *Ptr = Dictionary[index];			//Declaring a pointer variable of item struct and initializing it with the above calculated index of the Dictionary array
			while (Ptr != NULL)						//Loop runs till this pointer becomes is pointing to some pointer
			{
				if(Ptr->name == Person_name)				//If the pointer variable name is equal to the string name which was passed then put check equal to true
				{
					flag = true;
				}
				Ptr = Ptr->next;					//Moving to the next pointer
			}
			if(flag == true)						//If the value of check is true after coming out of the loop then return true
			return true;
			
			else									//else return false
			return false;			
	}
	
	int NumberOfItemsInIndex(int index)						//Returns the number of items that are in the list of a single bucket
	{										// This function is being used in Size() function to return the total number of strings which are available in the dictionary
		int count = 0;
		if(Dictionary[index]->name == "NULL")				//if the index which was passed to this function and at that index the name is equal to empty then return count as is which is equal to zero. Means that there are no items in this index at the moment.
		return count;
		
		else			//Else
		{
			count++;		//There should be one item therefore count is incremented by one
			Dict *Ptr = Dictionary[index];			//A new ptr of Dict is defined in initialized and put equal to that dictionary index which was passed in the function
			while(Ptr->next != NULL)				//Loop runs till the next pointer after Ptr becomes equal to NULL
			{
				count++;						//Count is incremented everytime this loop runs
				Ptr = Ptr->next;				//Ptr is set equal to the next pointer.
			}		
			return count;							//Count is returned. This count will return the number of items in the index which was passed.
		}	
	}
	int Size()							//TASK 1: PART(4)				//This function returns the number of strings in the table
	{	
		total_names = 0;
		for(int i=0; i <table_size; i++)					//Loop runs till the size of the table
		{
		total_names = total_names + NumberOfItemsInIndex(i);			//Every time loop runs the total_names is added to the number of items in the index which is passed in the NumberOfItemsInIndex from the loop. This function will run for all indexes and return all the items in all the indexes which are being updated in the total_names variable.
		}		
		return total_names;	
	}
	
	
	void PrintItemsInIndex(int index)
	{
		Dict *Ptr = Dictionary[index];
		if(Ptr->name == "NULL")
		{
			cout<<"Index "<<index<<" is empty"<<endl;
		}
		else
		{
			cout<<"Index "<<index<<" contains the following names\n";
			while(Ptr!=NULL)
			{
			cout << "------------------\n";
			cout << Ptr->name <<endl;
			cout << "------------------\n";
			Ptr = Ptr->next;	
			}
		}
	}
	
	
	void PrintTable()
	{
		int number;					//Holds number of elements in each bucket(index)
		for(int i=0; i<table_size; i++)
		{
			number = NumberOfItemsInIndex(i);
			if(number>1)
			{
				Dict *Ptr = Dictionary[i];
				while(Ptr != NULL)
				{
					cout<<"\n--------------------\n";
					cout<<"Index = "<< i << endl;
					cout<<Ptr->name<<endl;
					cout<< "# of names = " << number <<endl;
					cout<<"--------------------\n";
					Ptr = Ptr->next;
				}
			}
			else
			{
			cout<<"\n--------------------\n";
			cout<<"Index = "<< i << endl;
			cout<< Dictionary[i]->name<<endl;
			cout<< "# of names = " << number <<endl;
			cout<<"--------------------\n";		
			}
		}		
	}
		  		
};


int main()
{
	cout<<"********HASH TABLE********"<<endl;
	
	HashTable H1(26);
	
	string name;
	char choice;
	MENU:
	cout<<endl<<endl;
	cout<<"-------------MENU---------------"<<endl;
	cout<<"1) Add a name to the Dictionary"<<endl;
	cout<<"2) Remove a name from the Dictionary"<<endl;
	cout<<"3) Check to see whether a name exists in the Dictionary or not"<<endl;
	cout<<"4) See the number of strings in the table"<<endl;
	cout<<"5) Print the whole Dictionary"<<endl;
	cout<<"Press \"E or e\" to exit"<<endl;
	cout<<"Choice: ";
	cin>>choice;
	switch (choice)
	{
		char Menu_choice;
		case ('1'):
			{
				cout<<"Enter the name of the person which you want in the Dictionary: ";
				cin>>name;
				H1.Add(name);
				goto MENU;
			}
		case ('2'):
			{
				cout<<"Enter the name of the person which you want to remove from the Dictionary: ";
				cin>>name;	
				H1.Remove(name);
				goto MENU;
			}
		case ('3'):
			{
				cout<<"Enter the name of the person which you want to check whether exists in the Dictionary or not: ";
				cin>>name;
				H1.Contains(name);
				if(H1.Contains(name) == 1)
				cout<<"\""<<name<<"\""" is found in the Dictionary";
				else
				cout<<"\""<<name<<"\""" is not found in the Dictionary";
				goto MENU;
			}
		case ('4'):
			{
				cout<<"Number of names in the dictionary are: "<<H1.Size()<<endl;
				goto MENU;
			}
		case ('5'):
			{
				H1.PrintTable();
				goto MENU;
			}
		case ('E'):
			{
				char sure;
				cout<<"Are you sure to want to quit the program?(Y/N): ";
				cin>>sure;
				if(sure == 'Y' || sure=='y')
				exit(0);
				else
				goto MENU;
			}		
	}
	
}
	
