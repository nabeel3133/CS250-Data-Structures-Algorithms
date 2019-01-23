#include <iostream>
#define SIZE 6
using namespace std;


int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****SHELL SORT ALGORITHM****"<<endl<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<"Enter the "<<counter<<" element of the array: ";
	cin>>Array[i];
	counter++;	
	}
	
	cout<<endl<<endl;
	cout<<"Array before applying Shell Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;
	
	//SHELL SORT ALGORITHM
	cout<<"\nArray before applying Shell Sort Algorithm is: ";
	for(int i=0; i<=SIZE-1; i++)
	cout<<Array[i]<<" ";
	
    int j; 
    //Narrow the array by 2 everytime
    for (int gap = SIZE/ 2; gap > 0; gap /= 2)			//BEST CASE: O(n log n)
    {
    	for (int i = gap; i < SIZE; i++)				//AVERAGE CASE: depends on gap sequence 
    	{
      		int temp = Array[i];  						 //WORST CASE: O(n (logn)^2) 
      		for (j = i; j >= gap && temp < Array[j - gap]; j -= gap)
      		{
        	Array[j] = Array[j - gap];
      		}
      	Array[j] = temp;
    	}	 
  	} 
	cout<<"\nArray after applying Shell Sort Algorithm is: ";
	for(int i=0; i<=SIZE-1; i++)
	cout<<Array[i]<<" "; 	
}
