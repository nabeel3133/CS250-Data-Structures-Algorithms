/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Lab 10
Data Structures & Algorithms
*/
#include<iostream>
#include<time.h>
#include <stack>
#include <math.h>
#include <conio.h>
#include<ctime>
using namespace std;
stack<clock_t> tictoc_stack;

void tic()
{
	tictoc_stack.push(clock());
}
void toc()
{
	cout << "\nTime elapsed: " << (double)((clock() - tictoc_stack.top())) / CLOCKS_PER_SEC <<" s"<<endl;
	tictoc_stack.pop();
}

//TASK 1 (BOTTOM UP IMPLEMENTATION OF MERGE SORT)
/*
int MAX;
void mergesort(int h,int *a)
{
	int rght, wid, rend;
	int i, j, m, t;

	for (int k = 1; k < h; k *= 2) {
		for (int left = 0; left + k < h; left += k * 2) {
			rght = left + k;
			rend = rght + k;
			if (rend > h) rend = h;
			m = left; i = left; j = rght;
			while (i < rght && j < rend) {
				if (a[i] <= a[j]) {
					a[m] = a[i]; i++;
				}
				else {
					a[m] = a[j]; j++;
				}
				m++;
			}
			while (i < rght) {
				a[m] = a[i];
				i++; m++;
			}
			while (j < rend) {
				a[m] = a[j];
				j++; m++;
			}
			for (m = left; m < rend; m++) {
				a[m] = a[m];
			}
		}
	}
}

int main() {
	clock_t start;
	double duration;
	srand(time(NULL));
	for (;;)
	{
		cout << "Enter Value for N: ";
		cin >> MAX;
		int *arr = new int[MAX];
		int *arrbest = new int[MAX];
		int *arrworst = new int[MAX];
		cout << "\n";
		cout << "\tN = " << MAX << endl;
		cout << "\n";
		for (int i = 0; i < MAX; i++) {
			arr[i] = rand() % 100000;
		}
		for (int i = 0; i < MAX; i++) {
			arrbest[i] = i * 2;
		}
		for (int i = 0; i < MAX; i++) {
			arrworst[i] = i * (-2);
		}
		cout << "***MERGE SORT***";
		cout << endl << "--Average Case--";
		tic();
		mergesort(MAX,arr);
		toc();
		cout << endl;

		cout << "--Best Case--";
		tic();
		mergesort(MAX, arrbest);
		toc();
		cout << endl;

		cout << "-Worst Case--";
		tic();
		mergesort(MAX, arrworst);
		toc();
		cout << endl;
		cout << "\n";
		char ch;
		cout << "\nDo you want to exit? (E) or perform another sorting(Any other key)?" << endl << endl;
		ch = _getch();
		if (ch == 'e' || ch == 'E')
			break;
	}
}
*/


//TASK 2 (ITERATIVE AND RECURSIVE METHOD FOR FIBONACCI SERIES)
/*
//Iterative function for Fibonacci Series
void Fibonacci_Iterative(long series)
{
	long long now = 0;
	long long after = 1;
	long long before;
	cout<<now<<"     ";
    for(int i = 0;i<series-1;i++)
    {
    	before = now;
    	now = after;
    	after = now + before;
		cout<<now<<"     ";   	
	}
}

//Recusrive function for Fibonacci Series
long long Fibonacci_Recursive(long long n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(Fibonacci_Recursive(n-1)+Fibonacci_Recursive(n-2));
    }
}
 

int main()
{
	long long series;
	cout<<"***FIBONACCI SERIES***"<<endl<<endl;
	cout<<"Enter the number upto which you want to see the fibonacci series: ";
	cin>>series;
	cout<<endl;
	cout<<"---Fibonacci Series Using Iterations---"<<endl;
	cout<<"Fibonacci series till "<<series<< " elements is:   ";
	tic();
	Fibonacci_Iterative(series);
	toc();
	
	cout<<endl<<endl;
	cout<<"---Fibonacci Series Using Recursion---"<<endl;
	long long count=0;
    cout<<"Fibonacci series till "<<series<< " elements is:   ";
    tic();
    while(count<series)
    {
        cout<<Fibonacci_Recursive(count)<<"     ";
        count++;
    }
    toc();
}
*/


//TASK 3 (ITERATIVE AND RECURSIVE METHOD FOR FACTORIAL)

//Iterative Method Function for factorial
long long Factorial_Iterative(long long number)
{
	long long fact = number;
	if(number == 0)
	return 1;
	else
	{
		for(long long i = number-1; i > 0; i--)
		{
		fact = fact*i;
		}
		return fact;	
	}
}

//Recursive Method Function for factorial
long long Factorial_Recursive(long long number)
{
	if(number == 0)
	return 1;
	else
	{
	return number*Factorial_Recursive(number-1);	
	}
}

int main()
{
	int num;
	cout<<"***CALCULATING FACTORIAL***"<<endl<<endl;
	cout<<"Enter the number whose factorial you want to calculate: ";
	cin>>num;
	cout<<"---Factorial Using Iterations---"<<endl;
	tic();
	long long fact = Factorial_Iterative(num);
	cout<<"Factorial of "<<num<<" is "<<fact;
	toc();
	
	cout<<endl<<endl;
	cout<<"---Factorial Using Recursion---"<<endl;
	tic();
	fact = Factorial_Recursive(num);
	cout<<"Factorial of "<<num<<" is "<<fact;
	toc();	
}

