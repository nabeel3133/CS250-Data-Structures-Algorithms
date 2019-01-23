#include<iostream>
using namespace std;

void Fibonacci(long series)
{
	long long now = 0;
	long long after = 1;
	long long before;
	cout<<now<<" ";
    for(long long i = 0;i<series-1;i++)
    {
    	before = now;
    	now = after;
    	after = now + before;
		cout<<now<<" ";   	
	}
}

int main()
{
	int series;
	cout<<"***FIBONACCI SERIES USING ITERATIONS***"<<endl<<endl;
	cout<<"Enter the number upto which you want to see the fibonacci series: ";
	cin>>series;
	cout<<"\nFibonacci series till "<<series<< " elements is: "<<endl;
	Fibonacci(series);
}
