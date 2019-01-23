/* LAb 10 name
Abdul Basit*/
#include<iostream>
#include<time.h>
using namespace std;
int counts;
int a[100000];
int b[100000];
int sizeA = 100000;
void merge_sort(long num)
{
	int rght, wid, rend;
	int i, j, m, t;

	for (int k = 1; k < num; k *= 2) {
		for (int left = 0; left + k < num; left += k * 2) {
			rght = left + k;
			rend = rght + k;
			if (rend > num) rend = num;
			m = left; i = left; j = rght;
			while (i < rght && j < rend) {
				counts++;
				if (a[i] <= a[j]) {
					b[m] = a[i]; i++;
				}
				else {
					b[m] = a[j]; j++;
				}
				m++;
			}
			while (i < rght) {
				b[m] = a[i];
				i++; m++;
			}
			while (j < rend) {
				b[m] = a[j];
				j++; m++;
			}
			for (m = left; m < rend; m++) {
				a[m] = b[m];
			}
		}
	}
}





int main() {
	clock_t t;
	int i;
	for (i = 0; i < sizeA; i++) {    //INPUT LOOP
									 //	a[i] = i; //best case
									 //a[i] = size - i;//worst case
		a[i] = rand() % sizeA + 2; 		//rand input
	}
	t = clock();
	merge_sort(sizeA);
	t = clock() - t;
	cout << "\n Shell sort \n It took me " << t << " clicks  and seconds:" << ((float)t) / CLOCKS_PER_SEC;

	cout << "\ncouts " << counts << endl;       //gives number of not moves
	cout << "\n";

	getchar();
	return 0;
}
