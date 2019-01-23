/*
Nabeel Hussain Syed
122937
lab # 13
task 1
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class hashtable{
	int max;
	int *values;
public:
	hashtable(int x)
	{
		cout << "number of elements : " <<x<<endl;
		max = x;
		values = new int[max];
		for (int i = 0; i < max; i++)
		{
			values[i] = NULL;
		}
	}
	void printtable(){
		cout << endl;
		for (int i = 0; i < max; i++)
		{
			if (values[i] != NULL)
				cout << values[i] << " ";
		}
		cout << endl;
	}
	int hash(int x){//x=key
		srand(time(NULL));
		int value;
		value = x*(rand() % max);
		for (;;)
		{
			if (value >= max){
				value = value / max;
			}
			else
				break;
		}
		return value;
	}
	void insert(int x)
	{
		int h;
		int index = hash(x);
		h = index;
		for (;;){
			if (values[index] == NULL)
			{
				values[index] = x;
				break;
			}
			else
			{
				index += 1;
				if (index == max) index = 0;
				if (index == h)
				{
					cout << "\nError!, Hash overflow!" << endl;
					break;
				}
			}
		}
	}
	void del(int x)
	{
		int h;
		int index = hash(x);
		h = index;
		for (;;)
		{
			if (values[index] == x)
			{
				values[index] = NULL;
				break;
			}
			else
			{
				index += 1;
				if (index == max) index = 0;
				if (index == h)
				{
					cout << "\nError!, element not found in te hash table!" << endl;
					break;
				}
			}
		}
	}
	void search(int x)
	{
		int h;
		int index = hash(x);
		h = index;
		for (;;){
			if (values[index] == x)
			{
				cout << "\nElement found at " << index;
				break;
			}
			else
			{
				index += 1;
				if (index == max) index = 0;
				if (index == h){
					cout << "\nError!, element not found in te hash table!" << endl;
					break;
				}
			}
		}
	}
};

void main()
{
	hashtable hasht(10);
	hasht.insert(3);
	hasht.insert(5);
	hasht.insert(213);
	hasht.insert(433);
	hasht.insert(543);
	hasht.printtable();
	hasht.del(213);
	hasht.printtable();
	hasht.insert(323);
	hasht.insert(555);
	hasht.insert(2123);
	hasht.insert(4353);
	hasht.insert(5543);
	hasht.insert(9983);
	hasht.printtable();
	hasht.search(433);
	getchar();
	getchar();
}
