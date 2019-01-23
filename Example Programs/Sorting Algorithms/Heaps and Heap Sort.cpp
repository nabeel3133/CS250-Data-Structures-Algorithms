#include<iostream>
using namespace std;
class Heap
{
	private:
	int *heap;
	int total_elements;
	int count;
	
	public:
	Heap(int number_of_elements)
	{
		count = 0;
		heap = new int [number_of_elements];
		heap[0] = number_of_elements;
		total_elements = number_of_elements;
		for(int i=1; i<=total_elements; i++)
		{
		cout<<"Enter the "<<i<<" element: ";
		cin>>heap[i];
		}
	}

	
	void showHeap()
	{
		for(int i=1; i<=total_elements; i++)
		{
		cout<<i<<" element is: "<<heap[i]<<endl;
		}
	}
	
	//Max Heap
	void Build_MaxHeap()
	{
		//cout<<"Heap after applying Max heap function for the "<<count<<" time"<<endl<<endl;
		//showHeap();
		for(int i=total_elements/2; i>=1; i--)
		{
			max_heapify(heap, i, total_elements);				//Passing array and parent node which is "i" and the total elements
		}
		//count++;	
	}
	
	//Max heap down adjust
	void max_heapify(int heap[], int i, int total)			//i here is parent
	{	
		int j = 2*i;		//Calculating child. j will become the left child of i
		int temp = heap[i];			//Temp variable has the parent value 
		while(j<= total)
		{
			if(j<total && heap[j+1]>heap[j])		//If the index of the left child is less than the total indexes and the value of the right child is greater than the left child
			{
				j++;				//Then increase the index of the left child to make it point to the right child of the parent so that we can swap the right child with parent
			}
			if(temp > heap[j])						//Now let us see whether the child is greater than the parent. If the parent is greater than the child then it is already in max heap. we will break out of the loop
			break;
			
			else if(temp <= heap[j])			//else if the parent is not greater than the child
			{
				heap[j/2] = heap[j];			//Here we are initializing child value with parent value
				j = 2*j;						//And now the new j index will be equal to its left child index 
			}
		}
		heap[j/2] = temp;
		return;
	}
	
	//Max Heap Sort
	void MaxHeapSort()
	{
		for(int i = total_elements; i>=2; i--)
		{		
			int temp = heap[i];	
			heap[i] = heap[1];	
			heap[1] = temp;			//Swapping first and last element of the heap
			max_heapify(heap, 1, i-1);  //Adjusting the 1st element of the heap array because we have deleted the root element when we swapped it at first so we again have to apply the MaxHeap property to make the heap a MaxHeap	
		}
	}
	
	
	//Min Heap
	void Build_MinHeap()
	{
		for(int i=total_elements/2; i>=1; i--)
		{
			min_heapify(heap, i, total_elements);				//Passing array and parent node which is "i"
		}
	}
	
	//Min heap up adjust
	void min_heapify(int heap[], int i, int total)			//i here is parent
	{	
		int j = 2*i;		//Calculating child. j will become the left child of i
		int temp = heap[i];
		while(j<= total)
		{
			if(j<total && heap[j+1]<heap[j])
			{
				j++;
			}
			if(temp < heap[j])
			break;
			
			else if(temp >= heap[j])
			{
				heap[j/2] = heap[j];
				j = 2*j;
			}
		}
		heap[j/2] = temp;
		return;
	}
	
	//Min Heap Sort
	void MinHeapSort()
	{
		for(int i = total_elements; i>=2; i--)
		{
			int temp = heap[i];	
			heap[i] = heap[1];	
			heap[1] = temp;
			min_heapify(heap,1,i-1); 	//Adjusting the 1st element of the heap array because we have deleted the root element when we swapped it at first so we again have to apply the MinHeap property to make the heap a MinHeap	
		}
	}
	/*
	void push(int number, int last_position)
	{
	heap[last_position] = number;
	Build_MaxHeap(heap, last_position);
	}

	void pop(int last_position)
	{
	int temp = heap[1];
	heap[1] = a[last_position];
	Build_MaxHeap(heap, last_position-1);
	}
	*/
};

int main()
{
	int elements_in_heap1;
//	int elements_in_heap2;
	
	cout<<"******HEAPS AND HEAP SORT******"<<endl<<endl;			//Best, Worst And Average Case: O(n log(n) )
	cout<<"Enter the number of elements in heap1: ";
	cin>>elements_in_heap1;
	

	Heap H1(elements_in_heap1);
	cout<<"\nObject of First Heap is created(The heap we are trying to make is Max heap)!!\n";
	H1.showHeap();
	cout<<endl;
	
	cout<<"Elements after applying Max heap are: "<<endl;
	H1.Build_MaxHeap();
	H1.showHeap();
	cout<<endl;
	
	cout<<"Elements after applying Heap Sort Algorithm on a Max Heap(This will sort the elements in ascending order): "<<endl;
	H1.MaxHeapSort();
	H1.showHeap();
	cout<<endl<<endl;
	
	
	
	//cout<<"Enter the number of elements in heap2: ";
	//cin>>elements_in_heap2;

	Heap H2(elements_in_heap1);
	cout<<"\nObject of Second Heap is created(The heap we are trying to make is Min heap)!!\n";
	H2.showHeap();
	cout<<endl;
	
	cout<<"Elements after applying Min heap are: "<<endl;
	H2.Build_MinHeap();
	H2.showHeap();
	cout<<endl;
	
	cout<<"Elements after applying Heap Sort Algorithm on a Min Heap(This will sort the elements in descending order): "<<endl;
	H2.MinHeapSort();
	H2.showHeap();
}
