#include<iostream>
#define INFINITE 10000000
using namespace std;

class Graph
{
	private:
	int **Matrix;				//Adjaceny Matrix
	int *distance;
	int total_vertices;
	int *previous_vertex;
	int next;
	int *visited_vertex;
	
	public:
	Graph(int vertices)
	{
		total_vertices = vertices;
		Matrix = new int*[total_vertices];				//Adjacency Matrix
		for (int i = 0; i < total_vertices; ++i)
		Matrix[i] = new int[total_vertices];
		for (int i = 0; i < total_vertices; ++i)
		for (int j = 0; j < total_vertices; ++j)
		Matrix[i][j] = 0;
		
		distance = new int[total_vertices];
		previous_vertex = new int [total_vertices];
		visited_vertex = new int [total_vertices];
		
		
	}
	
	void VertexConnection()
	{
		for(int i=0; i<total_vertices; i++)
		{
			for(int j=0; j<total_vertices; j++)
			{
				if(i==j)
				Matrix[i][j] = 0;
			}
		}
		
		for(int i=0; i<total_vertices; i++)
		{
			for(int j=i+1; j<total_vertices; j++)
			{
				char option;
				cout<<"Is vertex "<<i<<" and "<<j<<" connected(Y/N): ";
				cin>>option;
				if(option=='Y'||option=='y')
				{
					Matrix[i][j]=1;
					Matrix[j][i]=1;
				}
				else
				Matrix[i][j] = 0;
			}
		}
	}
	
	bool IsGraphConnected()
	{
		bool flag;
		for(int i=0; i<total_vertices; i++)
		{
			for(int j=0; j<total_vertices; j++)
			{
				if(Matrix[i][j] == 0)
				{
					flag = false;
				}
				else if(Matrix[i][j] == 1)
				{
					flag = true;
					break;
				}				
			}
		}
		if(flag == false)
		return false;
		else 
		return true;
	}
	
	void AddWeightedEdges()
	{
		for(int i=0; i<total_vertices; i++)
		{
			for(int j=i+1; j<total_vertices; j++)
			{
				if(Matrix[i][j]==1)					//Means they are connected
				{
				cout<<"Weighted edge between "<<i<<" and "<<j<<" : ";
				cin>>Matrix[i][j];	
				Matrix[j][i] = Matrix[i][j];	
				}
			}
		}
	}
	
	void ShowWeights()
	{
		for(int i=0; i<total_vertices; i++)
		{
			for(int j=i+1; j<total_vertices; j++)
			{
				if(Matrix[i][j]!=0)    			//Means they are connected
				{
				cout<<"Weighted edge between vertice "<<i<<" and vertice "<<j<<" or vertice "<<j<<" and vertice "<<i<<""""" is: "<<Matrix[i][j]<<endl;
				}
			}
		}
	}
			

    void DjikstrasAlgorithm()
    {
    	
    	for(int i=0; i<total_vertices; i++)
		{
			for(int j=i+1; j<total_vertices; j++)
			{
				if(i==0)
				{
				distance[i] = 0;
				}
				if(Matrix[i][j]!=0)    			//Means they are connected
				{
				distance[i] = INFINITE;
				}
			}
		}
    	
    	
    	
        int Minimum;
        distance = Matrix[0]; 
        visited_vertex[0]=1;
        
        for(int i=0;i<total_vertices;i++)
        {
            int size = sizeof(Matrix)/sizeof(Matrix[0]);
       		int Minimum = Matrix[0][0];
        	for(int i=0;i<size;i++)
        	{
            	for(int j=0;j<size;j++)
            	{
                	if(Minimum>Matrix[i][j])
                	{
                    Minimum = Matrix[i][j];
                	}
            	}
        	}
				
            for(int j=0;j<total_vertices;j++)
            {
                if(Minimum>distance[j] && visited_vertex[j]!=1) 
                {
                    Minimum = distance[j];
                    next = j; 
                }
            }
            
            visited_vertex[next]=1;
            for(int k=0; k<total_vertices; k++)
            {
                if(visited_vertex[k]!=1) 
                {
                    if(Minimum+Matrix[next][k]<distance[k]) 
                    {
                        distance[k] = Minimum+Matrix[next][k];
                        previous_vertex[k] = next;
                    }
                }
            }
        }
		
        cout<<"Shortest distance of edges are:"<<endl;
        for(int i=0;i<total_vertices;i++)
        {
        	int startVertex = 0;
        	cout<<"Shortest distance of vertex "<<i<<" from "<<startVertex<<" is: "<<distance[i]<<endl;
        }	
    }
};

int main()
{
	int vertices;
	START:
	cout<<"Enter the number of vertices: ";
	cin>>vertices;
	if(vertices == 1)
	{
		cout<<"Cannot enter vertices less than 2"<<endl;
		goto START;
	}
	Graph G1(vertices);
	
	cout<<endl;
	
	ConnectVertices:
	G1.VertexConnection();
	cout<<endl<<endl;
	if(G1.IsGraphConnected() == 1)
	cout<<"Graph is connected"<<endl<<endl;
	else
	{
	cout<<"Graph is not connected. Update the vertex connection again and make sure that the graph is connected. Otherwise we \ncannot apply Djikstras Algorithm"<<endl<<endl;
	goto ConnectVertices;	
	}

	
	G1.AddWeightedEdges();
	cout<<endl;
	
	G1.ShowWeights();
	cout<<endl;
	
	G1.DjikstrasAlgorithm();
	
	
}
