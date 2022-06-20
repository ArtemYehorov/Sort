#include<iostream>
using namespace std;

#pragma once

template < typename T >
class Sorter
{
	Sorter() {};

	static void swapEl(T* ar, int i);

public:

	static void Buble(T* ar, int SIZE);
	static void Shaker(T* ar, int SIZE);
	static void Choise(T* ar, int SIZE);
	static void Inserts(T* ar, int SIZE);
	static void Fast(T* ar, int SIZE);

	static void PrintAr(T* ar, int SIZE);
	static void AddAr(T* ar, int SIZE);

};

template < typename T >
Sorter<T>::Sorter();

//ф-ция для обмена значений ячеек (SHAKER)
template < typename T >
void Sorter<T>::swapEl(T* ar, int i)
{
	T buff;
	buff = ar[i];
	ar[i] = ar[i - 1];
	ar[i - 1] = buff;
}

template < typename T >
void Sorter<T>::Buble(T* ar, int SIZE)
{
	T temp; // временная переменная для обмена элементов местами

// Сортировка массива пузырьком

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				// меняем элементы местами
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
}

template < typename T >
void Sorter<T>::Shaker(T* ar, int SIZE)
{
	//ф-ция "шейкер"-сортировки

	int leftMark = 1;
	int rightMark = SIZE - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (ar[i - 1] > ar[i]) swapEl(ar, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (ar[i - 1] > ar[i]) swapEl(ar, i);
		rightMark--;
	}

}

template < typename T >
void Sorter<T>::Choise(T* ar, int SIZE)
{
	T min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями 

	for (int i = 0; i < SIZE; i++)
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < SIZE; j++)
			min = (ar[j] < ar[min]) ? j : min;
		// cделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = ar[i];
			ar[i] = ar[min];
			ar[min] = buf;
		}
	}
}


template < typename T >
void Sorter<T>::Inserts(T* ar, int SIZE)
{
	T buff = 0; // для хранения перемещаемого значения
	int j;

	for (int i = 1; i < SIZE; i++)
	{
		buff = ar[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		for (j = i - 1; j >= 0 && ar[j] > buff; j--)
			ar[j + 1] = ar[j];

		ar[j + 1] = buff; // и поставим запомненный на его новое место 
	}
}


template < typename T >
void Sorter<T>::Fast(T* ar, int SIZE)
{
	//Указатели в начало и в конец массива
	int i = 0;
	int j = SIZE - 1;

	//Центральный элемент массива
	T mid = ar[SIZE / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (ar[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (ar[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			T tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		Fast(ar, j + 1);
	}
	if (i < SIZE) {
		//"Првый кусок"
		Fast(&ar[i], SIZE - i);
	}
}



template < typename T >
void Sorter<T>::PrintAr(T* ar, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << ar[i] << ",";
	}
}


template < typename T >
void Sorter<T>::AddAr(T* ar, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		ar[i] = rand() % 10;
	}
}

