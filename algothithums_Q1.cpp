// algothithums_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <stdio.h>

std::vector<int> heap;
int heapSize = 0; //bad code bad name :(

void GetInputIntoVector(); //Prototype
void heapMe(int arr[], int n, int i);
void heapSortMe(int arr[], int n);
void OutputVector(std::vector<int> vectorOut);
void swap(int* s1, int* s2);
void printArray(int mydynamicarray[], int size);


//Q1 Heap Sort Algorithm Sam Deadman

int main()
{
	std::cout << "Hello World!\n";
	GetInputIntoVector();
	//convert vector into array start
	int* mydynamicarray = (int*)calloc(heap.size(), sizeof(int)); //gets mem location and wipes it so its empty
	int c = 0;
	heapSize = heap.size();
	for (c = 0; c < heapSize; c++)
	{
		mydynamicarray[c] = heap.back();
		heap.pop_back();
	}
	//convert vector into array end
	int point = sizeof(heap) / sizeof(heap[0]);
	printf("%d\n", point);
	heapSortMe(mydynamicarray, heapSize); //actual heap call

	//OutputVector(heap);

	printf("\n");
	printArray(mydynamicarray, heapSize);//final out
	printf("\n");
	printf("left smallest | right largest END");
}

void swap(int* s1, int* s2) 
{
	int temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

void GetInputIntoVector()
{
	int i;
	bool endInput = false;
	while (endInput == false)
	{
		printf("Input your next value (Insert 0 to end Input): "); //assumption, not other characters will be input
		scanf_s("%d", &i);
		if (i == 0)
		{
			endInput = true;
			break;
		}
		heap.push_back(i);
	}
	OutputVector(heap); //output unsorted list of inputs, in the order they were added
}

void OutputVector(std::vector<int> vectorOut)
{
	for (int i = 0; i < vectorOut.size(); i++) // output test
	{
		std::cout << vectorOut[i];
		std::cout << " ";
	}
}

void printArray(int mydynamicarray[],int size)
{
	for (int i = 0; i < size; i++) // output test
	{
		std::cout << mydynamicarray[i];
		std::cout << " ";
	}
}

void heapMe(int array[], int current, int count)
{
	//set an intial value, allowing for comparisions
	int largest = count;
	//2k + 2k+1 logic
	int l = 2 * count + 1;
	int r = 2 * count + 2;

	
	// if left is bigger than root
	if ((l < current) && (array[l] > array[largest]))
	{
		largest = l; //left is now largest
	}
	// if right is biggest
	if (r < current && array[r] > array[largest])
	{
		largest = r; //right is now largest
	}
	
	if (largest != count) {
		swap(&array[count], &array[largest]);//conducts swap logic 

		// recursively heaping the tree below current 
		heapMe(array, current, largest);
	}
	//printf("heapMe ");
	
	printArray(array, heapSize);//prints array allowing for debugging
	printf("\n");
}

void heapSortMe(int array[], int n) 
{
	// build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapMe(array, n, i);

	// one by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// move current root to end
		swap(&array[0], &array[i]);

		// call max heapify on the reduced heap
		heapMe(array, i, 0);
	}
	printf("heapSortMe ");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
