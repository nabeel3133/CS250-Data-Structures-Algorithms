/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Lab 8
Data Strcutres & Algorithms
*/
#include<iostream>
#include<time.h>
#include<ctime>
#include<stdlib.h>
#include <conio.h>

using namespace std;
int MAX;
static int shellSort_iterations;
static int insertionSort_iterations;

void ShellSort(int specificCase_array[], int size){
	shellSort_iterations = 0;
	clock_t time;
	double Time;
	time = clock();
    int j; 
  //Narrow the array by 2 everytime
  for (int gap = size / 2; gap > 0; gap /= 2)    //BEST CASE: O(n log n)
  {
    for (int i = gap; i < size; ++i)             //AVERAGE CASE: depends on gap sequence     
    {
      int swap = specificCase_array[i];          //WORST CASE: O(n (logn)^2)
      for (j = i; j >= gap && swap < specificCase_array[j - gap]; j -= gap)
      {
        specificCase_array[j] = specificCase_array[j - gap];
        shellSort_iterations++;
      }
      specificCase_array[j] = swap;
    } 
  }
  	Time = (double)(clock() - time) / (double)CLOCKS_PER_SEC;

	cout << "Time: " << double(Time) << " ms" << endl;
	cout << "Iterations: " << shellSort_iterations << endl;
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

int main() {
	for (;;){
		cout << "Enter the value of data(N): ";
		cin >> MAX;
		srand(time(NULL));
		int *averageCase_array = new int[MAX];
		int *averageCase_array1 = new int[MAX];
		int *bestCase_array = new int[MAX];
		int *worstCase_array = new int[MAX];
		int *worstCase_array1 = new int[MAX];
		cout << "\n";
		cout << "\tData(N) = " << MAX << endl;
		cout << "\n";
		for (int i = 0; i < MAX; i++) {
			averageCase_array[i] = rand() % 10000;
			averageCase_array1[i] = averageCase_array[i];
		}
		for (int i = 0; i < MAX; i++) {
			bestCase_array[i] = i * 2;
		}
		for (int i = 0; i < MAX; i++) {
			worstCase_array[i] = i * (-2);
			worstCase_array1[i] = i * (-2);
		}
		
	    cout << "GETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***INSERTION SORT***" << endl;
		cout << "Average Case:- " << endl;
		InsertionSort(averageCase_array);
		cout << "\nBest Case:- " << endl;
		InsertionSort(bestCase_array);
		cout << "\nWorst Case:- " << endl;
		InsertionSort(worstCase_array);
		cout << "\n";
		
		cout << "GETTING TIME AND ITERATIONS FOR THE 3 CASES OF ***SHELL SORT***" << endl;
		cout << "Average Case:-" << endl;
		ShellSort(averageCase_array1,MAX);
		cout << "\nBest Case:-" << endl;
		ShellSort(bestCase_array,MAX);
		cout << "\nWorst Case:- " << endl;
		ShellSort(worstCase_array1,MAX);
		cout << "\n";
		
		char ch;
		cout << "\nPress \"E or e\" to exit. By pressing any other key, you can again check sorts for \ndifferent data" << endl << endl;
		ch = _getch();
		if (ch == 'e' || ch == 'E')
		break;
	}
}
