#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int size { 10 }, min_n { -100 }, max_n { 100 };

void fillArray(int ar[], int size = ::size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		ar[i] = ::min_n + rand() % (::max_n - ::min_n);
}

void printArray(int ar[], int size = ::size) {
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}

// 2
double avgArray(int ar[], int size = ::size) {
	double d { 0 };
	for (int i = 0; i < size; i++)
		d += ar[i];
	d /= (double) size;
	return d;
}

// 3
int positivesArray(int ar[], int size = ::size) {
	int r { 0 };
	for (int i = 0; i < size; i++)
		if (ar[i] > 0)
			r++;
	return r;
}

int negativesArray(int ar[], int size = ::size) {
	int r { 0 };
	for (int i = 0; i < size; i++)
		if (ar[i] < 0)
			r++;
	return r;
}

int zeroesArray(int ar[], int size = ::size) {
	int r { 0 };
	for (int i = 0; i < size; i++)
		if (ar[i] == 0)
			r++;
	return r;
}

int main() {
	int array[size] { };
	fillArray(array);
	printArray(array);
	cout << "Average value of the array is " << avgArray(array) << endl;
	cout << "There are " << negativesArray(array) << " negative, "
			<< positivesArray(array) << " positive and " << zeroesArray(array)
			<< " zero values in the array." << endl;

	return 0;
}
