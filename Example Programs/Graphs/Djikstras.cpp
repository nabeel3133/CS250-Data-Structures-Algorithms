/*name BADUL BASIT
BSCS 5A
146120.
BFS USED;


Assignment 3: dikstra's algorithm

*/

#include <iostream>
using namespace std;

struct node {
	int info;
	node *next;
};



//queue code from previous lab taken for breath first search.
class Queue {
private:
	node *front;
	node *rear;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	void display();

};

void Queue::display() {
	node *p = new node;
	p = front;
	if (front == NULL) {
		cout << "\nNothing to Display\n";
	}
	else {
		while (p != NULL) {
			cout << endl << p->info;
			p = p->next;
		}
	}
}

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	delete front;
}

void Queue::enqueue(int data) {
	node *temp = new node();
	temp->info = data;
	temp->next = NULL;
	if (front == NULL) {
		front = temp;
	}
	else {
		rear->next = temp;
	}
	rear = temp;
}

int Queue::dequeue() {
	node *temp = new node();
	int value;
	if (front == NULL) {
		cout << "\nQueue is Emtpty\n";
	}
	else {
		temp = front;
		value = temp->info;
		front = front->next;
		delete temp;
	}
	return value;
}

bool Queue::isEmpty() {
	return (front == NULL);
}


class Graph {
private:
	int n;			// n is the number of vertices in the graph
	int **A;		// A stores the edges between two vertices
public:
	Graph(int size = 2);    //graph can have minimum size 2
	~Graph();
	bool isConnected(int, int);
	void addEdge(int u, int v,int value);
	void BFS(int);
	int wight(int u, int v);
	void printSolution(int dist[]);
	int minDistance(int dist[], bool sptSet[]);
	void dijkstra(int src);
};

Graph::Graph(int size) {
	int i, j;
	if (size < 2)   //setting minimum size equal 2
		n = 2;
	else 
		n = size;
	A = new int*[n];
	for (i = 0; i < n; ++i)
		A[i] = new int[n];

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)			//adjancence matrix. 
			A[i][j] = 0;				//n*n matrix with all entries "zero".
}

Graph::~Graph() {
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}


bool Graph::isConnected(int u, int v) {
	if (A[u - 1][v - 1]>0)
		return 1;
	else
		return 0;
}

void Graph::addEdge(int u, int v,int value) {
	A[u - 1][v - 1] = A[v - 1][u - 1] = value;		//simple we are setting 1 on that row and column .
}
void Graph::BFS(int s) {
	Queue Q;


	bool *explored = new bool[n + 1];

	for (int i = 1; i <= n; ++i)
		explored[i] = false;


	Q.enqueue(s);
	explored[s] = true; /** mark it as explored */
	cout << "Breadth first Search starting from vertex ";
	cout << s << " : " << endl;


	while (!Q.isEmpty()) {

		int v = Q.dequeue();

		cout << v << " ";

		for (int w = 1; w <= n; ++w)
				if (isConnected(v, w) && !explored[w])// this condition checks that if v and w are conected and w is not explored  
			{

				Q.enqueue(w);
				explored[w] = true;
			}
	}
	cout << endl;
	delete[] explored;
}

int Graph::wight(int u, int v) {
	return(A[u][v]);
}


int Graph::minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < this->n; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;	
	}

	return min_index;
}

// A utility function to print the constructed distance array
void Graph::printSolution(int dist[])
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < this->n; i++)
		printf("%d \t\t %d\n", i+1, dist[i]);
}


void Graph::dijkstra(int src)
{
	src = src - 1;
	int *dist=new int[this->n];     // The output array.  dist[i] will hold the shortest
									// distance from src to i

	bool *sptSet=new bool[this->n]; // sptSet[i] will true if vertex i is included in shortest
									// path tree or shortest distance from src to i is finalized

									// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i <this->n; i++)
	{
		dist[i] = INT_MAX, sptSet[i] = false;	
	}
								
	dist[src] = 0;				// Distance of source vertex from itself is always 0

	for (int count = 0; count<this->n; count++)	// Find shortest path for all vertices
	{						
									// Pick the minimum distance vertex from the set of vertices not
									// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < this->n; v++)

											// Update dist[v] only if is not in sptSet, there is an edge from 
											// u to v, and total weight of path from src to  v through u is 
											// smaller than current value of dist[v]
		if (!sptSet[v] && wight(u,v) && dist[u] != INT_MAX && dist[u] + wight(u, v) < dist[v])
				dist[v] = dist[u] + wight(u, v);
	}

	// print the constructed distance array
	printSolution(dist);
}



int main() {

	Graph g(5);   //5*5 matrix in the graph.

	int v = INT_MAX;
	cout<<"Value of INT_MAX is: "<<v<<endl;
	g.addEdge(1, 2,4);
	g.addEdge(1, 4,8);
	g.addEdge(2, 3,3);
	g.addEdge(3, 4,4);
	g.addEdge(4, 5,7);
	
	g.BFS(3);
	cout << "\n dikstra's algorithm" << endl;
	g.dijkstra(1);
	return 0;
}
