#include<iostream>
using namespace std;

int Recursive_Factorial(int Number)
{
	if(Number==1 || Number==0)
	return 1;
	
	else
	{
		return Number*(Recursive_Factorial(Number-1));
	}
}

int Iterative_Factorial(int Number)
{
	if(Number==1 || Number==0)
	return 1;
	
	int Fact;
	int temp;
	for(int i=Number; i>0; i--)
	{
		if(i==Number)
		{
		temp = i*(i-1);
		i--;	
		}
		else
		{
		temp=temp*i;
		}
		Fact = temp;
	}
	return Fact;
}

int main()
{
	int number;
	cout<<"Enter the number whose factorial you want to find: ";
	cin>> number;
	cout<<"Factorial of "<<number<<" using recursive is: "<<Recursive_Factorial(number); 
	
	cout<<endl<<endl;
	
	cout<<"Factorial of "<<number<<" using iterations is: "<<Iterative_Factorial(number); 
}
