/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Data Structures And Algorithms
Lab 14
*/ 

#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

class Queue
{
private:
	node *front;
	node *rear;
public:
	Queue()
	{
	front = NULL;
	rear = NULL;
	}
	
	~Queue()
	{
	delete front;
	}
	
	Enqueue(int data)
	{
	node *temp = new node();
	temp->info = data;
	temp->next = NULL;
		if (front == NULL)
		{
		front = temp;
		}
		else
		{
		rear->next = temp;
		}
		rear = temp;
	}
	
	Dequeue()
	{
	node *temp = new node();
	int value;
		if (front == NULL)
		{
		cout << "\nQueue is Emtpty\n";
		}
		else
		{
		temp = front;
		value = temp->info;
		front = front->next;
		delete temp;
		}
	return value;
	}	
	
	bool isEmpty()
	{
	return (front == NULL);
	}
	
};

class Graph 
{
private:
	int total_vertices; 
	int **A; 
public:
	Graph(int size)
	{	
	int i, j;
	if (size < 2) 
	total_vertices = 2;
	else 
	total_vertices = size;
	A = new int*[total_vertices];
		for (i = 0; i < total_vertices; ++i)
		A[i] = new int[total_vertices];
		for (i = 0; i < total_vertices; ++i)
		for (j = 0; j < total_vertices; ++j)
		A[i][j] = 0;
	}
	
	~Graph()
	{
	for (int i = 0; i < total_vertices; ++i)
		delete[] A[i];
		delete[] A;
	}

	bool isConnected(int startVertex, int endVertex) 
	{
		if(A[startVertex - 1][endVertex - 1] == 1)
		return 1;
		else
		return 0;
	}
	
	void EdgeAdd(int startVertex, int endVertex) 
	{
	A[startVertex - 1][endVertex - 1] = A[startVertex - 1][endVertex - 1] = 1;
	}
	
	
	void BFS(int search)  
	{
	Queue Q;

	bool *Explore = new bool[total_vertices + 1];

	for (int i = 1; i <= total_vertices; ++i)
		Explore[i] = false;

	Q.Enqueue(search); 

	Explore[search] = true; 
	cout << "Breadth first Search starting from vertex ";
	cout << search << ": " << endl;

	while (!Q.isEmpty()) {

		int startVertex = Q.Dequeue(); 		

		cout << startVertex << " ";

		for (int endVertex = 1; endVertex <= total_vertices; ++endVertex)
		{
			if (isConnected(startVertex, endVertex) && !Explore[endVertex]) 
			{
			Q.Enqueue(endVertex); 
			Explore[endVertex] = true;  
			}	
		}

	}
	cout << endl;
	delete[] Explore;
	}
};


int main()
{
	Graph G1(8); // Creates a graph with 8 vertices 

	char choice;
	MENU:
	cout<<"\n-------------MENU---------------"<<endl;
	cout<<"1) Add edge to the graph"<<endl;
	cout<<"2) Breadth first search through the graph"<<endl;
	cout<<"Press \"E or e\" to exit"<<endl;
	cout<<"Choice: ";
	cin>>choice;
	switch (choice)
	{
		char Menu_choice;
		case ('1'):
			{
				int startVertex;
				int endVertex;
				BACK1:
				cout<<"Enter the start vertex: ";
				cin>>startVertex;
				if(startVertex == 0)
				{
					cout<<"Cannot enter vertex with value equal to zero";
					goto BACK1;
				}
				else
				{
				BACK2:
				cout<<"\nEnter the end vertex: ";
				cin>>endVertex;
				if(endVertex == 0)
				{
					cout<<"Cannot enter vertex with value equal to zero";
					goto BACK2;
				}
				else
				cout<<"Edge with start vertex "<<startVertex<<" and end vertex "<<endVertex<<" is successfully added in the graph";
				G1.EdgeAdd(startVertex, endVertex);	
				}
	
				goto MENU;
			}
		case ('2'):
			{
				int vertex;
				cout << "\nEnter vertex to start BFS from: ";
				cin>> vertex;
				G1.BFS(vertex);
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
	return 0;
}
