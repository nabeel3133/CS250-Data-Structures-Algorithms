/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Lab 4
*/

#include <iostream>
using namespace std;
class Tree
{
public:
	Tree *left, *right;
	int value;
	int other_node;
	Tree *parent = NULL, *current = NULL;
	void insert()
	{
		if (parent == NULL)
		{
			parent = new Tree;
			cout << "Enter value of the parent node in the tree: ";
			cin >> parent->value;
			cout << "The value is successfully stored in parent node of the tree." << endl << endl;
			parent->right = NULL;
			parent->left = NULL;
		}
		else
		{
			current = parent;
			cout << "Enter value of the other node: ";
			cin >> other_node;
			while (true)
			{
				if ( other_node < current->value)
				{
					if (current->left == NULL)
					{
						current->left = new Tree;
						current = current->left;
						current->value = other_node;
						current->left = NULL;
						current->right = NULL;
						cout << "The value was added in the left leaf of the tree." << endl << endl;
						break;

					}
					else if (current->left != NULL)
					{
						current = current->left;
						cout<<"The value was added in the left node of the leaf of the tree. "<<endl << endl;
					}
				}
				else if (other_node > current->value)
				{
					if (current->right == NULL)
					{
						current->right = new Tree;
						current = current->right;
						current->value = other_node;
						current->left = NULL;
						current->right = NULL;
						cout << "The value was added in the right leaf of the tree." << endl << endl;
						break;

					}
					else if (current->right != NULL)
					{
						current = current->right;
						cout<<"The value was added in the right node of the leaf of the tree. "<<endl << endl;
					}
				}
				else if (value == current->value)
				{
					cout << "Can't add the same value in any node of the tree. The values must be distinct. " << endl << endl;
					break;
				}
			}
		}
	}
};

void print_in_order(Tree *parent)
{
	if (parent != NULL)
	{
		print_in_order(parent->left);
		cout << parent->value << "\n";
		print_in_order(parent->right);
	}
}
void print_pre_order(Tree *parent)
{
	if (parent != NULL)
	{
	  
		cout << parent->value << "\n";
		print_pre_order(parent->left);
		print_pre_order(parent->right);
	}
}
void print_post_order(Tree *parent)
{
	if (parent != NULL)
	{
		print_post_order(parent->left);
	    print_post_order(parent->right);
		cout << parent->value << "\n";
	}
}
int main()
{
	char option;
	int choice;
	Tree T1;
	INSERTION:
	do
	{
		cout<<"Do you want to enter a value in the node of a tree(Y/N)? ";
		cin>> option;
		if(option == 'Y'|| option == 'y')
		{
		T1.insert();
		}
		else 
		break;
	}while (option == 'Y');
	
	cout << "\n\nTRAVERSING THE TREE!!!";
	cout << "\nPress \"1\" to do in order traversal";
	cout << "\nPress \"2\" to do pre order traversal";
	cout << "\nPress \"3\" to do post order traversal";
	cout << "\nPress \"4\" to go back and start inserting values in the tree again";
	cout << "\nPress \"5\" to EXIT";
	cout << "\nChoice: ";
	cin>>choice;
	if(choice == 1)
	{
		cout << "\n\nINORDER TRAVERSEL LIST: \n";
		print_in_order(T1.parent);
	}
    else if(choice == 2)
	{
		cout << "\n\nPREORDER TRAVERSEL LIST: \n";
		print_pre_order(T1.parent);
	}
	else if (choice == 3)
	{
	    cout << "\n\nPOSTORDER TRAVERSEL LIST: \n";
		print_post_order(T1.parent);
	}
	else if (choice == 4)
	{
		goto INSERTION;
	}
	else if (choice == 5)
	{
		exit(0);
	}
}

	

