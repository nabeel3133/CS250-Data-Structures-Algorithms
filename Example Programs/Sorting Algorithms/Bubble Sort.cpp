#include <iostream>
#define SIZE 6
using namespace std;


int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****BUBBLE SORT ALGORITHM****"<<endl<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<"Enter the "<<counter<<" element of the array: ";
	cin>>Array[i];
	counter++;	
	}
	
	cout<<endl<<endl;
	cout<<"Array before appyling Bubble Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;
	
	//BUBBBLE SORT ALGORITHM
	for(int i = 0; i <= SIZE-2; i++)			// T(n) = (n-1) x (n-1) x C
	{	
		int flag = 0;											//  = Cn^2 - 2Cn + 1	
		for(int j = 0; j <= SIZE-2-i; j++)		// Worst Case: O(n^2)
		{										// Average Case: O(n^2)
			if(Array[j] > Array[j+1])			// Best Case: O(n)
			{
			int temp = Array[j];
			Array[j] = Array[j+1];
			Array[j+1] = temp;
			flag = 1;	
			}
		}
		if (flag == 0)    // Means there has not been one swap. The list was already sorted that is why no swap took place in the inner loop. As the list is already sorted so we will break out of the outer loop.
		break;
	}
	
	cout<<"Array after applying Bubble Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}
}
