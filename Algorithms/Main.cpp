#include <Windows.h>
#include <iostream>
#include "DynamicArray.h"
using namespace std;

template <typename T>
void printArray(T array[], int arraysize)
{
	//Prints the array
	for (int i = 0; i < arraysize; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << "" << std::endl; //Makes a blank line 
}

void printDynamicArray(DynamicArray<int> arr)
{
	for (int i = 0; i < arr.getLength(); i++)
	{
		std::cout << arr.getItem(i) << std::endl;
	}
}

template <typename T>
void bubbleSort(T array[], int arraysize)
{
	T temp;
	//Uses a Nested for loop to go through the array 
	for (int i = 0; i < arraysize - 1; i++)
	{
		for (int q = 0; q < arraysize - 1; q++)
		{
			if (array[q] > array[q + 1])
			{
				temp = array[q];
				array[q] = array[q + 1];
				array[q + 1] = temp;
			}
		}
	}

	//Prints new array
	printArray(array, 5);
}

template <typename T>
void insertionSort(T array[], int arraysize)
{
	int j = 0;
	T key = 0;
	for (int i = 1; i < arraysize; i++)
	{
		key = array[i]; //Sets key to current index
		j = i - 1;//sets j to pervious index
		while (j >= 0 && array[j] > key)//While j is greater than oe equal to o and the value at j is greater than key
		{
			array[j + 1] = array[j];//Set array at the index of j + 1 to be the value at index of j
			j--;//Decrments
		}
		array[j + 1] = key;//Set array at the index of j+1 to be the key

	}
	printArray(array, 5);
}

int main()
{
	DynamicArray<int>arr = DynamicArray<int>();

	arr.addItem(1);
	arr.addItem(4);
	arr.addItem(3);
	arr.addItem(2);
	printDynamicArray(arr);

	arr.sortItems();
	std::cout << std::endl;
	printDynamicArray(arr);

	arr.removeItem(1);
	arr.removeItem(4);
	arr.removeItem(3);
	arr.removeItem(2);

	std::cout << std::endl;//ends line or skips line
	printDynamicArray(arr);
	return 0;
	/*int arrnumbers[] = { 23,3,4,56,8 };
	float arrFloat[] = { 1.3f,0.4f,7.9f,17.6f,2.6f };

	bubbleSort(arrnumbers, 5);
	insertionSort(arrnumbers, 5);
	bubbleSort(arrFloat, 5);
	insertionSort(arrFloat, 5);
	return 0;*/
}