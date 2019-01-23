/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Data Structures & Algorithms
*/
#include<iostream>
#include<time.h>
#include<ctime>
#include<stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;


//TASK 1

static int mergeSort_iterations;
stack<clock_t> tictoc_stack;

void tic()
{
	tictoc_stack.push(clock());
}
void toc()
{
	cout << "Time elapsed: " << (double)((clock() - tictoc_stack.top())) / CLOCKS_PER_SEC <<" s"<< endl;
	tictoc_stack.pop();
}

	void Merge(int left_Array[],int right_Array[],int merged_Array[],int length_of_left_Array,int length_of_right_Array)
	{
		mergeSort_iterations = 0;
		// i - to mark the index of left subarray (left_Array)
		// j - to mark the index of right subarray (right_Array)
		// k - to mark the index of merged subarray (merged_Array)
		int i,j,k;
		i = 0;
		j = 0;
		k = 0;
		while(i<length_of_left_Array && j<length_of_right_Array)     //BEST CASE: O(n log (n))
		{ 															//AVERAGE CASE: O(n log (n))
			if(left_Array[i]<=right_Array[j])						//WORST CASE: O(n log (n))
			{
			merged_Array[k]=left_Array[i];
			i++;
			}
			else
			{
			merged_Array[k]=right_Array[j];
			j++;
			}
		k++;
		mergeSort_iterations++;	
		}
		while(i < length_of_left_Array)
		{
			merged_Array[k]=left_Array[i];
			i++;
			k++;
		}
		while(j<length_of_right_Array)
		{
			merged_Array[k]=right_Array[j];
			j++;
			k++;
		}
	}	

	void MergeSort(int Array[], int length_of_Array)
	{
		int length_of_left_Array = (length_of_Array)/2;       //Length of left array is equal to midpoint because we are dividing the original array in half. Here length_of_Array are the total elements in the original array.
		int left_Array[length_of_left_Array];      //Mid elements (from index 0 till mid-1) should be part of left sub-array
		int length_of_right_Array = length_of_Array - length_of_left_Array;   	//And (n-mid) elements (from mid to n-1) will be part of right sub-array
		int right_Array[length_of_right_Array];	
		if(length_of_Array < 2)   // Base condition: If the array has less than two element, do nothing. 
		return;
		else
		{
			for(int i = 0; i<length_of_left_Array; i++)   // Creating left subarray
			left_Array[i] = Array[i];

			for(int j = 0; j<length_of_right_Array; j++)   // Creating right subarray
			right_Array[j] = Array[length_of_left_Array+j];

		MergeSort(left_Array,length_of_left_Array);    //Sorting the left subarray
		MergeSort(right_Array,length_of_Array - length_of_left_Array);        //Sorting the right subarray
		Merge(left_Array,right_Array,Array,length_of_left_Array,length_of_right_Array);	  // Merging left and right subarrays into Array as sorted list.
		}
		
	}
	
int main()
{
	int MAX;
	cout<<"Enter N(data): ";
	cin>>MAX;
	cout<<"With data = "<<MAX<<", given below are the 3 cases for the MERGE SORT Algorithm"<<endl<<endl;
	srand(time(NULL));
	int averageCase_array[MAX];
	int averageCase_array1[MAX];
	int bestCase_array[MAX];
	int worstCase_array[MAX];
	int worstCase_array1[MAX];
		for (int i = 0; i < MAX; i++) {
			averageCase_array[i] = rand() % 100000;
		}

		for (int i = 0; i < MAX; i++) {
			bestCase_array[i] = i + 1;
		}
		
		for (int i = 0; i < MAX; i++) {
			worstCase_array[i] = i*(-2);
		}
	int length_of_Array = sizeof(averageCase_array)/sizeof(averageCase_array[0]);   	// Finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	cout << "\nGETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***MERGE SORT***" << endl;
	
	cout << "Average Case:- " << endl;
	//cout<<"List before sorting in average case: "<<endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout<<averageCase_array[i]<<endl;
	//}
	tic();
	MergeSort(averageCase_array,length_of_Array);
	//cout<<"Merge sort algorithm applied"<<endl;
	cout<<"Number of iterations in average case: "<<mergeSort_iterations<<endl;
	toc();	
    //	cout<<"List after sorting in average case: "<<endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout<<averageCase_array[i]<<endl;
	//}
		
	cout << "\nBest Case:- " << endl;
	//cout<<"List before sorting in best case: "<<endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout<<bestCase_array[i]<<endl;
	//}
	tic();
	MergeSort(bestCase_array,length_of_Array);
	//cout<<"Merge sort algorithm applied"<<endl;
	cout<<"Number of iterations in best case: "<<mergeSort_iterations<<endl;
	toc();
	//cout<<"List after sorting in best case: "<<endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout<<bestCase_array[i]<<endl;
	//}
	
	cout << "\nWorst Case:- " << endl;
	//cout<<"List before sorting in worst case: "<<endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout<<worstCase_array[i]<<endl;
	//}
	tic();
	MergeSort(worstCase_array,length_of_Array);
	//cout<<"Merge sort algorithm applied"<<endl;
	cout<<"Number of iterations in worst case: "<<mergeSort_iterations<<endl;
	toc();
	//cout<<"List after sorting in worst case: "<<endl;
	//	for (int i = 0; i < MAX; i++) {
	//	cout<<worstCase_array[i]<<endl;
	//}
}



//TASK 2
/*
string data_array1[948][4];
double counter;
void Merge(int, int, int);

void MergeSort(int Low, int High)
{
	if (Low < High)
	{
		int	Mid = (Low + High) / 2;
		MergeSort(Low, Mid);
		MergeSort(Mid + 1, High);
		Merge(Low, Mid, High);
	}
}
void Merge(int Low, int Mid, int High)
{
	int h, i, j , k;
	string data_array2[948][4];
	h = Low;
	i = Low;
	j = Mid + 1;

	while ((h <= Mid) && (j <= High))
	{
		counter++;
		//if (data_array1[h][2].compare(data_array1[j][2])>0)
		int x, y;
		x = stoi(data_array1[h][2]); 
		y = stoi(data_array1[j][2]);
		if(x>=y)
		//if (data_array1[h][2]>=data_array1[j][2])
		{
			data_array2[i][0] = data_array1[h][0];
			data_array2[i][1] = data_array1[h][1];
			data_array2[i][2] = data_array1[h][2];
			data_array2[i][3] = data_array1[h][3];
			h++;
		}
		else
		{
			data_array2[i][0] = data_array1[j][0];
			data_array2[i][1] = data_array1[j][1];
			data_array2[i][2] = data_array1[j][2];
			data_array2[i][3] = data_array1[j][3];
			j++;
		}
		i++;
	}
	if (h>Mid)
	{
		for (k = j; k <= High; k++)
		{
			
			data_array2[i][0] = data_array1[k][0];
			data_array2[i][1] = data_array1[k][1];
			data_array2[i][2] = data_array1[k][2];
			data_array2[i][3] = data_array1[k][3];
			i++;
		}
	}
	else
	{
		for (k = h; k <= Mid; k++)
		{
			
			data_array2[i][0] = data_array1[k][0];
			data_array2[i][1] = data_array1[k][1];
			data_array2[i][2] = data_array1[k][2];
			data_array2[i][3] = data_array1[k][3];
			i++;
		}
	}
	for (k = Low; k <= High; k++) {
		
		data_array1[k][0] = data_array2[k][0];
		data_array1[k][1] = data_array2[k][1];
		data_array1[k][2] = data_array2[k][2];
		data_array1[k][3] = data_array2[k][3];
	}
}

int main()
{
	int i = 0, j = 0;
	cout << " Program starts and it will sort the data of the csv data file through Merge Sort Algorithm.\n" << endl;
	std::ifstream  data("data.csv");

	std::string line;
	while (std::getline(data, line))
	{
		std::stringstream  lineStream(line);
		std::string cell;
		j = 0;
		while (std::getline(lineStream, cell, ','))
		{
			data_array1[i][j] = cell;
			j++;
		}
		i++;
	}
	
	MergeSort(0, 947);
	std::ofstream  sorted_data("data.csv");
	for (i = 0; i < 948; i++)
	sorted_data << data_array1[i][0] << "," << data_array1[i][1] << "," << data_array1[i][2] << "," << data_array1[i][3] << endl;
	cout<<"\nProgram ends. Data is now sorted in descending order according to the number of aircrafts.";
	getchar();
	return 0;
}
*/
