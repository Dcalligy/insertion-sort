// insertionsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findSmallestRemainingElement(int array[], int size, int index);
void swap(int array[], int first_index, int second_index);
void sort(int array[], int size);
void displayArray(int array[], int size);

int main() {

	int arraySize;
	cout << "Please enter the number of elements you would like to sort: " << "\n";
	cin >> arraySize;
	// dynamic array is used to allow the insertion sort
	// function work with any size array.
	int *array = new int[arraySize];
	srand(time(NULL));

	for (int i = 0; i < arraySize; i++) {

		// keep the numbers small so they're easy to read
		array[i] = rand() % 100;
	}
	cout << "Original array: ";
	displayArray(array, arraySize);
	cout << "\n";

	sort(array, arraySize);

	cout << "Sorted array: ";
	displayArray(array,arraySize);
	cout << "\n";
	system("pause");
	return 0;
}

void sort(int array[], int size) {

	for (int i = 0; i < size; i++) {

		int index = findSmallestRemainingElement(array, size, i);
		swap(array, i, index);
	}
}

int findSmallestRemainingElement(int array[], int size, int index) {

	int index_of_smallest_value = index;

	for (int i = index + 1; i < size; i++) {

		if (array[i] < array[index_of_smallest_value]) {

			index_of_smallest_value = i;
		}
	}
	return index_of_smallest_value;
}

void swap(int array[], int first_index, int second_index) {

	int temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;

}

// used to make the display of the arrays 
// look pretty
void displayArray(int array[], int size) {

	cout << "{";

	for (int i = 0; i < size; i++) {

		if (i != 0) {
			cout << ", ";
		}
		cout << array[i];
	}
	cout << "}";
}
