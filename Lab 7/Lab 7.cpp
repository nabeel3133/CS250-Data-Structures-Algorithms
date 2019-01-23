/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Lab 7
Data Strcutres & Algorithms
*/
#include<iostream>
#include<time.h>
#include<ctime>
#include<stdlib.h>
#include <conio.h>

using namespace std;
int MAX;
static int bubblesort_iterations;
static int insertionSort_iterations;
static int  selectionSort_iterations;

void Bubblesort(int averageCase_array[]);
void InsertionSort(int averageCase_array[]);
void SelectionSort(int averageCase_array[]);


void Bubblesort(int averageCase_array[]) {

	bubblesort_iterations = 0;
	clock_t time;
	double Time;
	time = clock();
	int swap;
	for (int i = 0; i < MAX - 1; i++) {
		int flag = 0;
		for (int j = 0; j < MAX - 1; j++) {
			bubblesort_iterations++;
			if (averageCase_array[j] > averageCase_array[j + 1]) {
				swap = averageCase_array[j];
				averageCase_array[j] = averageCase_array[j + 1];
				averageCase_array[j + 1] = swap;
				flag =1;
			}
		}
		if(flag == 0)
		break;

	}
	Time = (double)(clock() - time) / (double)CLOCKS_PER_SEC;

	cout << "Time: " << double(Time) << " ms" << endl;
	cout << "Iterations: " << bubblesort_iterations << endl;

}

void InsertionSort(int averageCase_array[]) {
	
	insertionSort_iterations=0;
    int value;
    int hole;
	clock_t time;
	double Time;
	time = clock();
	int j, swap;
	insertionSort_iterations = 0;
	for(int i=1; i<MAX;i++)    //T(n)--> (MAX-1)(MAX-1)xC = CMAX^2 -2CMAX + 1 
	{ 	
	value = averageCase_array[i];					            //T(n) = O(MAX^2)
	hole = i;
  	while(hole > 0 && averageCase_array[hole-1]>value)
        { 											//BEST CASE: O(MAX)
    	averageCase_array[hole] = averageCase_array[hole-1]; 				//AVERAGE CASE: O(MAX^2)
    	hole = hole-1;							//WORST CASE: O(MAX^2)	
    	insertionSort_iterations++;
	    }	
	averageCase_array[hole] = value;	
    }
	Time = (clock() - time) / (double)CLOCKS_PER_SEC;
	cout << "Time: " << Time << " ms" << endl;
	cout << "Iterations: " << insertionSort_iterations << endl;
}

void SelectionSort(int averageCase_array[]) {
	
	selectionSort_iterations = 0;
	int min;
	int swap;
	clock_t time;
	double Time;
	time = clock();
	  for(int i=0; i<MAX-1;i++)    //Running the loop till MAX-2 because once we are done with all i's till n-2, the element at position n-1 already be at the correct position 
        { 	
	  	min = i;						//T(n) = an^2 + bn + c or O(n^2)
	    for(int j=i+1;j<MAX;j++)
		{          							//BEST CASE: O(MAX^2)
			if(averageCase_array[j]<averageCase_array[min])             //AVERAGE CASE: O(MAX^2)
			{     							//WORST CASE: O(MAX^2)
			min = j;
			}
		selectionSort_iterations++;	
		}
		swap = averageCase_array[i];
		averageCase_array[i]=averageCase_array[min];
		averageCase_array[min]=swap;		
	  }
	Time = (clock() - time) / (double)CLOCKS_PER_SEC;
	cout << "Time: " << Time << " ms" << endl;
	cout << "Iterations: " << selectionSort_iterations << endl;
}

int main() {
	for (;;){
		cout << "Enter the value of data(N): ";
		cin >> MAX;
		srand(time(NULL));
		int *averageCase_array = new int[MAX];
		int *averageCase_array2 = new int[MAX];
		int *averageCase_array3 = new int[MAX];
		int *bestCase_array = new int[MAX];
		int *worstCase_array = new int[MAX];
		int *worstCase_array1 = new int[MAX];
		int *worstCase_array2 = new int[MAX];
		cout << "\n";
		cout << "\tData(N) = " << MAX << endl;
		cout << "\n";
		for (int i = 0; i < MAX; i++) {
			averageCase_array[i] = rand() % 10000;
			averageCase_array2[i] = averageCase_array[i];
			averageCase_array3[i] = averageCase_array[i];
		}
		for (int i = 0; i < MAX; i++) {
			bestCase_array[i] = i * 2;
		}
		for (int i = 0; i < MAX; i++) {
			worstCase_array[i] = i * (-2);
			worstCase_array1[i] = i * (-2);
			worstCase_array2[i] = i * (-2);
		}
		cout << "GETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***BUBBLE SORT***" << endl;
		cout << "Average Case:-" << endl;
		Bubblesort(averageCase_array);
		cout << "\nBest Case:-" << endl;
		Bubblesort(bestCase_array);
		cout << "\nWorst Case:- " << endl;
		Bubblesort(worstCase_array);
		cout << "\n";

		cout << "GETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***INSERTION SORT***" << endl;
		cout << "Average Case:- " << endl;
		InsertionSort(averageCase_array2);
		cout << "\nBest Case:- " << endl;
		InsertionSort(bestCase_array);
		cout << "\nWorst Case:- " << endl;
		InsertionSort(worstCase_array1);
		cout << "\n";

		cout << "GETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***SELECTION SORT***" << endl;
		cout << "Average Case:- " << endl;
		SelectionSort(averageCase_array3);
		cout << "\nBest Case:- " << endl;
		SelectionSort(bestCase_array);
		cout << "\nWorst Case:- " << endl;
		SelectionSort(worstCase_array2);
		cout << "\n";
		char ch;
		cout << "\nPress \"E or e\" to exit. By pressing any other key, you can again check sorts for \ndifferent data" << endl << endl;
		ch = _getch();
		if (ch == 'e' || ch == 'E')
		break;
	}
}
