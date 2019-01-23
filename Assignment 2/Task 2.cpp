/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Data Structures And Algorithms
Assignment 2
TASK 2
Compiled and executed perfectly on Dev C++
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
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
	for(int i=0; i<Person_name.length(); i++)				//key.length returns an integer value which is the length of the string that was passed
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
		total_names = 0;									//Initializing total_items equal to zero.
		Dictionary[tSize];									
		for(int i=0; i<table_size; i++)						//Loop runs equal to the number of times of table size
		{
			Dictionary[i] = new Dict;						//A new item is made
			Dictionary[i]->name = "Empty";					//Name of the item is set as empty
			Dictionary[i]->next = NULL;						//The next pointer to that is set equal to NULL
		}
	}
		

	void Add(string Person_name)				//TASK 1: PART(1)
	{
		int index = Hash(Person_name);					//Calling Hash function so that we can specify the index of the person's name where we will store the information of that specific person in the array
		
		if(Dictionary[index]->name == "Empty")		//This condition is used when we have not yet stored any information of any person in that index.
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
		  		
};



int main()
{
	HashTable H1(26);
	ifstream file;
	file.open("names.txt");				//Opens txt file from the computer named "names"
	if(!file.is_open())					//Condition for if file is not opened.
	{				
		cout<<"Error: Unable to open the file"<<endl;
		exit(0);
	}
	else 
	{
		string name;
		while(file.good())			//loop runs till the file is totally read
		{
		getline(file,name);		//Get first line from the file and puts it in variabe "name"
		H1.Add(name);			//Adds the variable name which was taken from the file and puts it in the dictionary using the function Add
		}
	}
	
	string word_name;
	while(word_name!="exit" || word_name!="Exit")				//Loop runs till the word_name variable is not equal to "exit"
	{
	cout<<"\nEnter the word which you want to find in the dictionary: "<<endl;
	cout<<"If you want to exit, just type \"exit or Exit\" and the program will end"<<endl;
	cin >> word_name;
		if(word_name!="exit")				//If the word which was entered is not equal to "exit", then check whether the word is in the dictionary or not
		{
			if(H1.Contains(word_name)==1)
			cout<<"\""<<word_name<<"\""" is found in the dictionary"<<endl;
			else
			cout<<"\""<<word_name<<"\""" is not found in the dictionary"<<endl;	
		}	
	}
}

