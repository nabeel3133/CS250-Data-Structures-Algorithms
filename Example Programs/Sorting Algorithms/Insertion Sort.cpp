#include <iostream>
#define SIZE 6
using namespace std;


int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****INSERTION SORT ALGORITHM****"<<endl<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<"Enter the "<<counter<<" element of the array: ";
	cin>>Array[i];
	counter++;	
	}
	
	cout<<endl<<endl;
	cout<<"Array before applying Insertion Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;
	
	//INSERTION SORT ALGORITHM
	for(int i = 1; i <=SIZE-1; i++)						// Best Case: O(n)		
	{													// Average Case: O(n^2)			
		int value = Array[i];							// Worst Case: O(n^2)
		int hole = i;
		while (hole>0 && Array[hole-1]>value)
		{
			Array[hole] = Array[hole-1];
			hole--;
		}
		Array[hole] = value;
	}
	
	cout<<"Array after applying Insertion Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}
}
