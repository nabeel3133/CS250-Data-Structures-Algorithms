/*
Nabeel Hussain Syed
122937
lab # 13
task 2
*/

#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;
class hashtable{
	int max;
	int *regnums;
	struct otherdata{
		string name;
		string sectiom;
		string gender;
		string grade;
	}*otherinfo;
public:
	hashtable(int x)
	{
		cout << "number of elements : " <<x<<endl;
		max = x;
		regnums = new int[max];
		otherinfo = new otherdata[max];
		for (int i = 0; i < max; i++)
		{
			regnums[i] = NULL;
			otherinfo[i].name.clear();
			otherinfo[i].sectiom.clear();
			otherinfo[i].grade.clear();
			otherinfo[i].gender.clear();
		}
	}
	void printtable(){
		cout << endl;
		for (int i = 0; i < max; i++)
		{
			if (regnums[i] != NULL)
			{
				cout << regnums[i] << "\t";
				cout << otherinfo[i].name << "\t";
				cout << otherinfo[i].gender<< "\t";
				cout << otherinfo[i].sectiom << "\t";
				cout << otherinfo[i].grade << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	int hash(int x)
	{//x=key
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
	void insert(int x, char name[], char section[], char grade[], char gender[])
	{
		int h;
		int index = hash(x);
		h = index;
		for (;;){
			if (regnums[index] == NULL)
			{
				regnums[index] = x;
				otherinfo[index].name= name;
				otherinfo[index].sectiom = section;
				otherinfo[index].grade = grade;
				otherinfo[index].gender = gender;
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
			if (regnums[index] == x)
			{
				regnums[index] = NULL;
				otherinfo[index].name.clear();
				otherinfo[index].sectiom.clear();
				otherinfo[index].grade.clear();
				otherinfo[index].gender.clear();
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
	void search()
	{
		cout << "\nEnter reg# of student you wanna search :";
		int x;
		cin >> x;
		int h;
		int index = hash(x);
		h = index;
		for (;;){
			if (regnums[index] == x)
			{
				cout << "\nElement found at " << index;
				cout << "\nINFORMATION\n" << regnums[index] << "\n" << otherinfo[index].name << "\n" << otherinfo[index].sectiom << "\n" << otherinfo[index].gender << "\n" << otherinfo[index].grade << endl;
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
	hashtable hash(2);
	hash.insert(123, "yasir", "bscs", "A", "male");
	hash.insert(223, "atif", "bsse", "B", "male");
	hash.printtable();
	hash.del(223);
	hash.printtable();
	hash.insert(444, "amna", "bsme", "C", "female");
	hash.insert(555, "azka", "bee", "D", "female");
	hash.printtable();
	hash.search();


	getchar();
	getchar();
}

