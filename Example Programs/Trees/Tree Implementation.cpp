#include<iostream>

using namespace std;

class nodes {

	friend class Tree;

private:
	int data;
	nodes *left;
	nodes *right;

public:
	nodes() 
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	~nodes() { }
};

class Tree {
private:
	nodes *rootptr;
	nodes *curr;

public:
	Tree() {
		rootptr = NULL;
		curr = NULL;
	}

	void insertdata(int d) {
		
		if (rootptr == NULL) {
			nodes *newptr = new nodes;
			newptr->data = d;
			rootptr = newptr;			
		}
		else
			insertdatahelper(rootptr, d);
	}

	void insertdatahelper(nodes *temptr, int d) {
		if ( (d < (temptr->data)) ) 
		{
			curr = temptr->left;
			
			if (curr == NULL) 
			{
				nodes *newptr = new nodes;
				newptr->data = d;
				curr = newptr;
				temptr->left = newptr;
				
			}
			else
				insertdatahelper(curr, d);
		}
		else if ( (d>(temptr->data)) ) 
		{
			curr = temptr->right;

			if (curr == NULL) {
				nodes *newptr = new nodes;
				newptr->data = d;
				curr = newptr;
				temptr->right = newptr;
				
			}
			else
				insertdatahelper(curr, d);
		}
	}	
	
	int maximum()
	{
		curr = rootptr;
		if(curr = rootptr)
		{
			while(curr->right != NULL)
		    {
			curr = curr->right;
		    }
		    return curr->data;
		}

	}
	
	int minimum()
	{
		curr = rootptr;
		if(curr == NULL)
		{
			cout<<"The tree is empty";
		}
		else
		{
			recursive_minimum(curr);
			/*while(curr->left != NULL)
		    {
			curr = curr->left;
		    }
		    return curr->data;*/
		}
	}
	
	int recursive_minimum(nodes *root)
	{
		if(root->left == NULL)
		{
			return root->data;
		}
		else
		{
			return recursive_minimum(root->left);
		}
		
	}
	
	
	int searchelement(int search)
	{
		if (rootptr != NULL) 
		{
			curr = rootptr;
			int returning = printsearchelementhelper(curr, search);
			return returning;
		}
		else {
			cout << "**** Tree is empty ****" << endl;
		}
	}
	int printsearchelementhelper(nodes *temptr, int search)
	{
		if(temptr == NULL)
		{
		cout<<search<< " does not exist in the tree\n\n";	
		return 0;
		}
		else if(search < temptr->data)
		printsearchelementhelper(temptr->left,search);
		else if(search > temptr->data)
		printsearchelementhelper(temptr->right,search);
		else if(search == temptr->data)
		{
		cout<<search<< " is found\n\n";		
		return 1;
		}
	}
	
    
    int delete_specific(int d)
    {
    	if(searchelement(d))
    	{
    		if(rootptr != NULL)
    	    {
       	    curr = rootptr;
    	    delete_specific_helper(curr, d);		
		    }
    	    else
    	    {
    		cout<<"The tree is empty";
		    }
		}
		else
		{
			return 0;
		}
	}
	nodes* delete_specific_helper(nodes *root,int del)
	{
		if(del<root->data)
		root->left = delete_specific_helper(root->left,del);
		else if(del > root->data)
		root->right = delete_specific_helper(root->right,del);
		else
		{
			//Case 1: No child
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
			//Case 2: One child
			else if(root->left == NULL)
			{
				curr = root;
				root = root->right;
				delete curr;
			}
			else if(root->right == NULL)
			{
				curr = root;
				root = root->left;
				delete curr;
			}
			//Case 3: 2 children
			else 
			{
				curr = FindMin(root->right);
				root->data = curr->data;
				root->right = delete_specific_helper(root->right, curr->data);
			}
			return root;
		}
	}
	nodes* FindMin(nodes *root)
	{
		while(root!=NULL)
		{
			root = root->left;
		}
		return root;
	}
	
	void delete_whole_tree()
    {
    	if(rootptr != NULL)
    	{
       	curr = rootptr;
    	delete_treeHelper(curr);		
		}
    	else
    	{
    		cout<<"The tree is empty";
		}
	}	
   	void delete_treeHelper ( nodes *root )
    {
       if ( root != NULL ) 
 	   {
       delete_treeHelper ( root->left );
       delete_treeHelper ( root->right );
       delete root;
       }
    }

	
	
	int successor(int d)
	{
		if(searchelement(d))
		{
			if (rootptr != NULL) 
			{
			curr = rootptr;
			printsuccessorhelper(d,curr);
		    }
		    else {
			cout << "**** Tree is empty ****" << endl;
		    }	
		}
		else
		{
			return 0;
		}
	}
	void printsuccessorhelper(int d, nodes *temptr)
	{
		if(temptr!=NULL)
		{
			if(temptr->data == d)
			{
				nodes *successor;
				if(temptr->right != NULL)     //Case in which the element we have to find (the node) has a right subtree and then through that we go to its left most leaf which will be the successor of that element
				{
				   successor = temptr->right;
				   while(successor->left!=NULL)
				   {
					successor = successor->left;
				   }
				   cout<<successor->data;
				}
				else if(temptr->right == NULL)   //Case in which the element we have to find (the node) has no right subtree.
				{
					nodes *ancestor = rootptr;
					while(ancestor != temptr)
					{
						if(temptr->data < ancestor->data)
						{
							successor = ancestor;
							ancestor = ancestor->left;
						}
						else
						ancestor = ancestor->right;
					}
					cout<<successor->data;
				}				
			}
		else if(maximum() == d)
		{
			cout<<"Error! The element whose sucessor you're trying to find is the maximum element in the tree";
		}
		else
		{
			printsuccessorhelper(d, temptr->left);
			printsuccessorhelper(d, temptr->right);	
		}
		}
	}
	
	
	int predecessor(int d)
	{
		if(searchelement(d))
		{
		    if (rootptr != NULL) 
			{
			curr = rootptr;
			printpredecessorhelper(d,curr);
		    }
		    else 
			{
			cout << "**** Tree is empty ****" << endl;
		    }		
		}
		else
		{
			cout<<"The element whose predecessor you want to find is not in the tree"<<endl;
			return 0;
		}

	}
	void printpredecessorhelper(int d, nodes *temptr)
	{
	    if(temptr!=NULL)
		{
		if(temptr->data == d)
			{
				nodes *predecessor;
				if(temptr->left != NULL)     //Case in which the element we have to find (the node) has a left subtree and then through that we go to its left most leaf which will be the predecessor of that element
				{
				   predecessor = temptr->left;
				   while(predecessor->right!=NULL)
				   {
					predecessor = predecessor->right;
				   }
				   cout<<predecessor->data;
				}
				else if(temptr->left == NULL)   //Case in which the element we have to find (the node) has no left subtree.
				{ 
					nodes *ancestor = rootptr;
					while(ancestor != temptr)
					{
						if(temptr->data > ancestor->data)
						{
							predecessor = ancestor;
							ancestor = ancestor->right;
						}
						else
						ancestor = ancestor->left;
					}
					cout<<predecessor->data;
				}	
			}
		else if(minimum() == d)
		{
			cout<<"Error! The element whose predecesor you're trying to find is the minimum element in the tree";
		}
		 else
		 { 
		 printpredecessorhelper(d, temptr->left);
		 printpredecessorhelper(d, temptr->right);
		 }
		}
	}


	void printtreeinorder() {
		if (rootptr != NULL) {

			curr = rootptr;
			printtreeinorderhelper(curr);
		}
		else {
			cout << "**** Tree is empty ****" << endl;
		}
	}
	void printtreeinorderhelper(nodes* temptr) 
	{
		if (temptr != NULL) 
		{
			curr = temptr->left;
			printtreeinorderhelper(curr);
			cout<<temptr->data<<", ";	
			curr = temptr->right;
			printtreeinorderhelper(curr);
			
		}
	}
	
	void printtreepreorder() 
	{
		if (rootptr != NULL) 
		{	
			curr = rootptr;
			printtreepreorderhelper(curr);
		}
		else 
		{
			cout << "**** Tree is empty ****" << endl;
		}
	}
	void printtreepreorderhelper(nodes* temptr) {
		if (temptr != NULL) {
		    cout<<temptr->data<<", ";
			curr = temptr->left;
			printtreepreorderhelper(curr);
			curr = temptr->right;
			printtreepreorderhelper(curr);
		}
	}
	
	void printtreepostorder()
	{
		if(rootptr!=NULL)
		{
			curr = rootptr;
			printtreepostorderhelper(curr);
		}
		else
		{
			cout<<"**** Tree is empty ****"<<endl;
		}
	}
	void printtreepostorderhelper(nodes *temptr)
	{
		if(temptr!=NULL)
		{
		printtreepostorderhelper(temptr->left);
	    printtreepostorderhelper(temptr->right);
		cout<<temptr->data<<", ";	
		}
	}

};

int main() {

	Tree t1;
	t1.insertdata(100);         cout<<"Inserting 100\n";
	t1.insertdata(70);          cout<<"Inserting 70\n";
	t1.insertdata(110);         cout<<"Inserting 110\n";
	t1.insertdata(65);          cout<<"Inserting 65\n";
	t1.insertdata(115);         cout<<"Inserting 115\n";
	t1.insertdata(105);         cout<<"Inserting 105\n";
	t1.insertdata(75);          cout<<"Inserting 75\n";
	t1.insertdata(60);          cout<<"Inserting 60\n";
	t1.insertdata(68);          cout<<"Inserting 68\n";
	t1.insertdata(67);          cout<<"Inserting 67\n";
	t1.insertdata(69);          cout<<"Inserting 69\n";	
	t1.insertdata(103);         cout<<"Inserting 103\n";	
	t1.insertdata(107);         cout<<"Inserting 107\n";
	
	cout<<endl;
	
	cout<<"INORDER TRAVERSAL: ";
	t1.printtreeinorder();

	cout << endl << endl;
	cout<<"PREORDER TRAVERSAL: ";
    t1.printtreepreorder();
    
    cout << endl << endl;
	cout<<"POSTORDER TRAVERSAL: ";
    t1.printtreepostorder();
    
    cout<<endl<<endl;
    cout<<"Maximum number in the tree is: ";
    cout<<t1.maximum();
    
    cout<<endl<<endl;
    cout<<"Minimum number in the tree is: ";
    cout<<t1.minimum();
    
    cout<<endl <<endl;
    
    int number;   
    cout<<"Enter the number (exisiting in the tree) whose successor and predecessor you want to find: ";
    cin>>number;
    cout<<"Search function: ";
    t1.searchelement(number);
    cout<<"Succesor of "<<number<< " is: ";
    t1.successor(number);
    cout<<endl;
    cout<<"Predecessor of "<<number<< " is: ";
    t1.predecessor(number);
    cout<<endl;
    cout<<"\nDeleting "<<number<< " from the tree!";
    cout<<"\nDelete specific function: ";
    t1.delete_specific(number);
    
    cout<<"Search function: ";
    t1.searchelement(number);
    cout<<endl <<endl;  
    
    /*cout<<"Deleting the entire tree!!";
  	t1.delete_whole_tree();  
	
    cout<<endl <<endl;  
    
    cout<<"INORDER TRAVERSAL: ";
	t1.printtreeinorder();

	cout << endl << endl;
	cout<<"PREORDER TRAVERSAL: ";
    t1.printtreepreorder();
    
    cout << endl << endl;
	cout<<"POSTORDER TRAVERSAL: ";
    t1.printtreepostorder();*/
  
   
    
}




