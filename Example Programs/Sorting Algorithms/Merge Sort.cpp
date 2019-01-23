#include <iostream>
#define SIZE 8
using namespace std;

void Merge(int Left_Array[], int Right_Array[], int Sorted_Merged_Array[], int length_of_left_Array, int length_of_right_Array)
{
	// i - to mark the index of left subarray (Left_Array)
	// j - to mark the index of right subarray (Right_Array)
	// k - to mark the index of sorted merged array (Sorted_Merged_Array) 
	int i=0;
	int j=0;
	int k=0;
	while(i<length_of_left_Array  && j<length_of_right_Array)
	{
		if(Left_Array[i]<= Right_Array[j])
		{
			Sorted_Merged_Array[k] = Left_Array[i];
			i++;
		}
		else
		{
			Sorted_Merged_Array[k] = Right_Array[j];
			j++;
		}
		k++;
	}
	while(i<length_of_left_Array)
	{
		Sorted_Merged_Array[k] = Left_Array[i];
		i++;
		k++; 
	}
	while(j<length_of_right_Array)
	{
		Sorted_Merged_Array[k] = Right_Array[j];
		j++;
		k++;
	}
}

void MergeSort(int Array[], int length_of_Array)
{
	if(length_of_Array < 2)				//Base condition. If the array is subdivided till the elements in the left subarray has less than 2 elements. This will return to the statement just below the recursive call. 
	return;
	
	else
	{
		int length_of_left_Array = (length_of_Array/2); 		//Left Array will be from the start till the middle of the original array that is why we divided the original array by 2.		
		int Left_Array[length_of_left_Array];
		
		int length_of_right_Array = (length_of_Array - length_of_left_Array);		//Right array will be from middle till the end of the original array so subtracting left length of left array from the length of original array, we will get the length of the right array.
		int Right_Array[length_of_right_Array];
		
		for(int i=0; i<length_of_left_Array; i++)			//Putting elements of the original array in the left subarray. Elements from the start of the orignal array till the middle of the original array will make the left subarray.
			Left_Array[i] = Array[i];
		
		for(int j=0; j<length_of_right_Array; j++)				//Putting elements of the original array in the right subarray. Elements from the middle of the orignal array till the end of the original array will make the right subarray.
			Right_Array[j] = Array[length_of_left_Array+j];
		
		MergeSort(Left_Array, length_of_left_Array);
		MergeSort(Right_Array, length_of_right_Array);
		Merge(Left_Array, Right_Array, Array, length_of_left_Array, length_of_right_Array);
	}
	
}

int main()
{
	int counter = 1;
	int Array[SIZE];
	cout<<"****MERGE SORT ALGORITHM****"<<endl<<endl;
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
	cout<<"Array before appyling Merge Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}

    cout<<endl;

	MergeSort(Array,length_of_Array);  // Calling MergeSort to sort the array. 
	cout<<"\nArray after applying Merge Sort Algorithm is: "<<endl;
	for(int i = 0; i<SIZE ; i++)
	{
	cout<<Array[i]<<" ";	
	}
}
