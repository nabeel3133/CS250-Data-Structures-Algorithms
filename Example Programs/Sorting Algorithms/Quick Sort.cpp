#include<iostream>
#define SIZE 8
using namespace std;

int Partition(int Array[], int Start_Index, int End_Index)
{	
	int Pivot = Array[End_Index];
	int Partition_Index = Start_Index;
	for(int i = Start_Index; i<=End_Index-1; i++)
	{
		if(Array[i]<=Pivot)       //Scanning the array from 0 index till End-1 index. If any element is less than the pivot element, swap the element from that index with the element of parition index.
		{
			int temp = Array[i];
			Array[i] = Array[Partition_Index];
			Array[Partition_Index] = temp;
			Partition_Index++; 
		}
	}
	int temp = Array[Partition_Index];       		//At the end swapping the end index element (pivot) with the parition index element so that all the elements at the left side of the pivot are less than the pivot and all the elements on the right side of the pivot are greater than the pivot.
	Array[Partition_Index] = Array[End_Index];
	Array[End_Index] = temp; 
	return Partition_Index;
}


void QuickSort(int Array[], int Start_Index, int End_Index)
{
	if(Start_Index < End_Index)
	{
	int Partition_Index = Partition(Array, Start_Index, End_Index);    //Rearranging of segment 
	QuickSort(Array, Start_Index, Partition_Index-1);		//Sort the segment left of the partition index
	QuickSort(Array, Partition_Index+1, End_Index); 		//Sort the segment right of the partition index or toward higher index of partition index).  			
	}	
}


int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****QUICK SORT ALGORITHM****"<<endl<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<"Enter the "<<counter<<" element of the array: ";
	cin>>Array[i];
	counter++;	
	}
	
	int length_of_Array = sizeof(Array)/sizeof(Array[0]);   	// Finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	
	cout<<endl<<endl;
	cout<<"Array before appyling Quick Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;

	int End_Index = SIZE-1;    //OR length_of_Array-1
	int Start_Index = 0;
	QuickSort(Array, Start_Index, End_Index);  // Calling QuickSort to sort the array. 
	cout<<"\nArray after applying Quick Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}
}
