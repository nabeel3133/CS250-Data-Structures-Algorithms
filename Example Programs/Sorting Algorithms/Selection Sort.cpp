#include <iostream>
#define SIZE 6
using namespace std;


int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****SELECTION SORT ALGORITHM****"<<endl<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<"Enter the "<<counter<<" element of the array: ";
	cin>>Array[i];
	counter++;	
	}
	
	cout<<endl<<endl;
	cout<<"Array before applying Selection Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;
    
    int count = 0;
	
	//SELECTION SORT ALGORITHM
	for(int i=0; i<=SIZE-2; i++)				// Best Case: O(n^2)
	{											// Average Case: O(n^2)
		int iMin = i;							// Worst Case: O(n^2)
		for(int j=i+1; j<=SIZE-1; j++)
		{
			if(Array[j] < Array[iMin])
			iMin = j;
			count++;
		}
		if(iMin == i)
		break;
		int temp = Array[i];
		Array[i] = Array [iMin];
		Array[iMin] = temp;
	}
	
	cout<<"Array after applying Selection Sort Algorithm is: "<<endl;
	for(int i = 0; i< SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}
	cout<<"\nNo of iterations: "<<count<<endl;
}
