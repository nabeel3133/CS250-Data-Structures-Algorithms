/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Lab 6
Data Structures & Algorithms
*/
#include<iostream>
using namespace std;
#define MAX 5
class bubbleSort
{
	private:
	int arr[MAX];
	
	public:
		
	void setter()
	{
		int n=1;
		for(int i=0;i<MAX;i++)
		{
		
		cout<<"Enter "<<n<<" element of array: ";
		cin>>arr[i];
		n++;	
		}
	}
	void algorithm()
	{
	  for(int i=1; i<=MAX-1;i++)    //T(n)--> (MAX-1)(MAX-1)xC = CMAX^2 -2CMAX + 1 
	  { 	
	  	int flag = 0;						//T(n) = O(MAX^2)
	    for(int j=0;j<=MAX-i-1;j++)
		{          							//BEST CASE: O(MAX)
			if(arr[j]>arr[j+1])             
			{     							//WORST CASE: O(MAX^2)
			int swap;
			swap = arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=swap;
			flag = 1;
			}
		}
	  if(flag == 0)
	  break;		
	  }
	}
	
	void show()
	{
		cout<<"\nList after applying bubble sort algorithm is: "<<endl;
		for(int i=0; i<MAX;i++)
		{
			cout<<arr[i]<<endl;
		}
	}
		
};

int main()
{
	bubbleSort b1;
	b1.setter();
	b1.algorithm();
	b1.show();
}
