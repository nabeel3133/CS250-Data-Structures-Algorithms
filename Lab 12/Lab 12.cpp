/*
Nabeel Hussain Syed
122937
BSCS-5A
Lab#12
Task 1 
&
Task 2 (at the bottom)
*/
#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
using namespace std;
void swap(int*A, int x, int y);
void transform2Maxh(int [], int, int);
void genMAXh(int[], int);
void heapsort(int[], int);
int MAX;
void swap(int*A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
void transform2Maxh(int a[], int i, int n)
{
	int l, r, largest, k;
	l = 2 * i;
	r = (2 * i + 1);
	largest = ((l <= n) && a[l]>a[i]) ? l:i;
	if ((r <= n) && (a[r]>a[largest]))
		largest = r;
	if (largest != i)
	{
		swap(&k,&a[i]);
		transform2Maxh(a, largest, n);
	}
}
void genMAXh(int a[], int n)
{
	for (int k = n / 2; k >= 1; k--)
	{
		transform2Maxh(a, k, n);
	}
}
void heapsort(int arr[], int N)
{
	clock_t start;//for time calculation
	double duration;
	start = clock();

	genMAXh(arr, N);
	int i, temp;
	for (i = N; i >= 2; i--)
	{
		swap(&arr[i],&arr[1]);
		transform2Maxh(arr, 1, i - 1);
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "\ntime: " << duration << " Sec" << endl;
}
void main()
{
	srand(time(NULL));
	cout << "Enter Size: "; cin >> MAX;
	int *arr1 = new int[MAX];
	int *arr2 = new int[MAX];
	int *arr3 = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr1[i] = rand() % 10000;
		arr2[i] = i*(2);
		arr3[i] = i*(-2);
	}

	cout << "\nFor random: ";
	heapsort(arr1,MAX);
	
	cout << "\nFor sorted: ";
	heapsort(arr2, MAX);

	cout << "\nFor unsorted: ";
	heapsort(arr3, MAX);

	getchar();
	getchar();
}
/*
TASK 2

Enter Size : 1000000

For random :
time : 0.195 Sec
For sorted :
time : 0.175 Sec
For unsorted :
time : 0.204 Sec
*/



