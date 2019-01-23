/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Data Structures & Algorithms
Lab 11
*/

#include<iostream>
#define SIZE 15
using namespace std;

/*
//TASK 1 (QUICK SORT) (Implement Quick Sort and implement a practical improvement by adding insertion sort for smaller sub arrays using a cutoff of less than equal to 10 items.) 
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

void InsertionSort(int Array[], int Start_Index, int End_Index)
{
	for(int i = Start_Index+1; i<=End_Index; i++)
	{
	int value = Array[Start_Index+1];
	int hole = Start_Index+1;
		while(hole > 0 && Array[hole-1]>value)
		{
			Array[hole] = Array[hole-1];
			hole--;
		}
		Array[hole] = value;	
	}

}


void QuickSort(int Array[], int Start_Index, int End_Index)
{
	if(Start_Index < End_Index)
	{
		if( (Start_Index - End_Index) <= 10)
		{
			cout<<"Insertion Sort is called "<<endl;
			InsertionSort(Array, Start_Index, End_Index);
		}

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
*/



//TASK 2 (Implement Binary Heap using Arrays. Implement the Push, Pop and Top functions.)
class BinaryHeap
{
	private:
	int *Array = new int[SIZE];
	int Index;
	int Top_value;
		
	public:
		
	BinaryHeap()
	{
	Index = 0;	
	}	
	int Top()
	{
		Top_value = Array[0];
		return Top_value;
	}
	
	int Push(int pushed_value)
	{
		int parent, child;
		Array[Index] = pushed_value;
		Index++;
		
		parent = Index/2;
		child = Index-1;
		while(Array[parent]<Array[child] && Array[parent]>0)
		{
			int temp = Array[parent];
			Array[parent] = Array[child];
			Array[child] = temp;
			
			child = parent;
			parent = (child/2);
		}
	}
	
	int Pop()
	{
		int *temp = new int;
		int *left_child = new int;
		int *right_child = new int;
		int *parent = new int;
		
		int pop_value = Array[0];
		temp = &Array[0];
		Array[0] = Array[1];
		temp = NULL;
		delete temp;
		
		for(int i = 0; i<Index; i++)
		{
				parent = &Array[i];
				left_child = &Array[2*i+1];
				right_child = &Array[2*i+2];
				if (left_child > right_child)
				{
					parent = left_child;
					left_child = right_child;		
				}
				else if(right_child > left_child)
				{
					parent = right_child;
					right_child = NULL;
					delete right_child;
				}				
		}
		
		for(int i=0; i<Index; i++)
		{
			int swap = Array[i];
			Array[i] = Array[i+1];
			Array[i+1] = swap;
		}
		Index--;
		
		cout<<pop_value<<" is succesfully popped from the heap";
	}
	
	void Display_Heap()
	{
		if(Index<0)
		{
			cout<<"Heap is empty";
		}
		else
		{
		for(int i=0; i<Index; i++)
		cout<<Array[i]<<" ";	
		}
	
	}
	
};

int main()
{
	BinaryHeap BH;
	char choice;
	cout<<"****BINARY HEAP(MAX HEAP)****"<<endl;
	cout<<"In Max heap, we have array in descending order because the value in parent node is always greater than its left and right child.";
	
	MENU:
	cout<<"\n\n----MENU----"<<endl;
	cout<<"1) Push a value into the binary heap"<<endl;
	cout<<"2) Pop a value(top value) from the binary heap"<<endl;
	cout<<"3) Return the top value of the binary heap"<<endl;
	cout<<"4) Display the heap"<<endl;
	cout<<"Press \"E or e\" to exit the program"<<endl;
	cout<<"Choice: ";
	cin>>choice;
	switch (choice)
	{
		case('1'):
			{
				int value;
				cout<<"Enter the value which you want to push in the heap: ";
				cin>>value;
				BH.Push(value);
				cout<<value<<" is succesfully pushed into the heap";
				goto MENU;
			}
		case('2'):
			{
				BH.Pop();
				goto MENU;
			}
		case('3'):
			{
				cout<<"The top value of the heap is "<<BH.Top();
				goto MENU;
			}
		case('4'):
			{
				cout<<"Heap: ";
				BH.Display_Heap();
				goto MENU;
			}
		case('E' || 'e'):
			{
				char yes_or_no;
				cout<<"Are you sure you want to exit the program\n(Y/N): ";
				cin>>yes_or_no;
				if(yes_or_no == 'Y' || yes_or_no == 'N')
				exit(0);
				else
				goto MENU;
			}
	}
}

