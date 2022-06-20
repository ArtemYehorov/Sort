#include"Sorter.h"

int main()
{
	srand(time(0));
	int SIZE = 15;
	int* arr = new int[SIZE];

	Sorter<int>::AddAr(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl;
	Sorter<int>::Buble(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl << endl;

	Sorter<int>::AddAr(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl;
	Sorter<int>::Fast(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl << endl;

	Sorter<int>::AddAr(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl;
	Sorter<int>::Inserts(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl << endl;

	Sorter<int>::AddAr(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl;
	Sorter<int>::Choise(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl << endl;


	Sorter<int>::AddAr(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl;
	Sorter<int>::Shaker(arr, SIZE);
	Sorter<int>::PrintAr(arr, SIZE);
	cout << endl << endl;
}