//********************************************************************************
// ASU Spring 2022 CSE310 HW#3
// Name: Rodrigo Corrales
// ASU ID: 1216550582
// ASU Email Address: rcorral7@asu.edu
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

#include <iostream>
#include <string>
//include the header file here
#include "MaxHeap.h"

using namespace std;

void printMenu(); // Displays option menu.
void heapSort(MaxHeap* oneMaxHeap);

int main()
{
	char input1 = 'Z';
    string firstName, lastName;
	int id, newID;
	int capacity, index = -1;   //1D array capacity and index
	double gpa;
	bool success = false;

    Student oneStudent; // Student object.

	//a variable used to represent a MaxHeap object
	MaxHeap* heap1 = nullptr; // MaxHeap object initialized to a null pointer.
	printMenu(); // Displays the menu.

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		input1 = toupper(input1);
		cin.ignore(20, '\n');	//flush the buffer

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the initial capacity
			{
				cout << "\nPlease enter the heap capacity: ";
				cin >> capacity; // User input capacity for the heap.
				cin.ignore(20, '\n');	//flush the buffer for above capacity entered
				
				heap1 = new MaxHeap(capacity); // Creates a new maxheap with size of capacity.
				break;
			}

			//delete the heap, call the destructor explicitly. Re-initialize heap1
			//with default capacity 5
			case 'D':
			{
				cout << "\nDelete the heap" << endl;
				heap1->~MaxHeap(); // Calls destructor explicitely.
				capacity = 5; // Sets the standard capacity to 5.
				heap1 = new MaxHeap(capacity); // Initializes a maxheap with default capacity of 5.
				break;
			}
			case 'E':	//Extract the root, remove it from the heap
			{
				if (heap1 == nullptr) // Checks for the case "Trying to extract max heap before initializing it."
				{
					cout << "\nEmpty heap, can NOT extract max" << endl; // Prints error message.
				}
				else if (heap1->getSize() == 0) // This checks if the heap is empty.
				{
					cout << "Empty heap, can NOT extract max" << endl; // Prints error message.
				}
				else
				{
					cout << "\nBefore extract heap max operation:" << endl;
					heap1->printHeap(); // Prints heap.
					cout << "\nAfter extract heap max operation:" << endl;
					heap1->extractHeapMax(); // Extracts the max the root of heap1 object.
					heap1->printHeap(); // Prints the heap after removing the root.
				}
				break;
			}
			case 'F':	//Find a Student
			{
				cout << "\nEnter the student ID you want to search: ";
				cin >> id;
				cin.ignore(20, '\n');	//flush the buffer

				if (heap1->isFound(id) != -1) // Checks to see if the student was found in the heap.
				{
					cout << "\nStudent with id: " << id << " is found" << endl;
				}
				else // If the student was not found in the heap.
				{
					cout << "\nStudent with id: " << id << " is NOT found" << endl;
				}
				break;
			}
			case 'I':	//Insert a Student
			{
				cout << "\nEnter the student first name: ";
				cin >> firstName;
				cout << "\nEnter the student last name: ";
				cin >> lastName;
				cout << "\nEnter the student id: ";
				cin >> id;
				cout << "\nEnter the student gpa: ";
				cin >> gpa;
				cin.ignore(20, '\n');	//flush the buffer
				bool isSuccessful = heap1->heapInsert(id, firstName, lastName, gpa); // Creates a bool with all student info to use and check.
				if (isSuccessful == true) // If student is inserted successfully.
				{
					cout << "\nStudent \"" << firstName << " " << lastName << "\" is added" << endl;
				}
				else
				{
					cout << "\nStudent \"" << firstName << " " << lastName << "\" is NOT added" << endl;
				}
				break;
			}
			case 'K':	//increase the ID
			{
				cout << "\nEnter the old student id you want to increase: ";
				cin >> id;
				cout << "\nEnter the new id: ";
				cin >> newID;
				cin.ignore(20, '\n');	//flush the buffer

				if (newID <= id) // If the new id is the same or less than the old id.
				{
					cout << "\nIncrease ID error: new id is smaller than current id" << endl;
				}
				else if (heap1->isFound(id) == -1) // If the old id is nonexistent.
				{
					cout << "\nThe old ID you try to increase does not exist" << endl;
				}
				else if (heap1->isFound(newID) != -1) // If the new id is already in the heap.
				{
					cout << "\nThe new ID you entered already exist, increase ID operation failed" << endl;
				}
				else // If all criteria are met, the operation is succesfful and it prints the heap in this order
				{
					cout << "\nBefore increase ID operation:" << endl;
					heap1->printHeap();
					cout << "\nStudent with old id: " << id << " is increased to new id: " << newID << endl;
					oneStudent.id = newID;
					heap1->heapIncreaseID(heap1->isFound(id),  oneStudent);
					cout << "\nAfter increase id operation: " << endl;
					heap1->printHeap();
				}	
				break;
			}
			case 'M':	//get the maximum node info.
			{
				if (heap1->getSize() == 0) // Checks if the heap is empty.
				{
					cout << "\nEmpty heap, can NOT get max node" << endl; // Prints error message.
				}
				else
				{
					cout << "\nThe maximum heap node is:" << endl;
					Student maxStudent = heap1->getHeapMax(); // Variable that holds the root of the heap (aka max student)
					cout << left;
					cout << setw(8) << maxStudent.id
     					<< setw(12) << maxStudent.firstName
     					<< setw(12) << maxStudent.lastName
     					<< setw(8) << fixed << setprecision(2) << maxStudent.gpa << endl;
				}
				break;
			}
			case 'P':	//Print heap contents
			{
				if (heap1->getSize() == 0) // Checks for an empty heap.
				{
					cout << "\nEmpty heap, no elements" << endl;
				}
				else // If the heap is not empty, it prints the heap.
				{
					heap1->printHeap(); // Prints heap.
				}
				break;
			}
			case 'S':	//HeapSort
			{
				cout << "\nHeap sort. Students will be sorted in increasing order of their IDs" << endl;
				heapSort(heap1); // Calls heapsort on the heap1 object.
				break;
			}
			case 'Q':	//Quit
				delete heap1; // Deletes heap object.
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "Unknown action\n";
				break;
		}
	} 
	while (input1 != 'Q');
	return 0;
}

//************************************************************
//The function displays the menu
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind a student by ID\n";
	cout << "I\t\tInsert a student\n";
	cout << "K\t\tIncrease the ID\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "S\t\tHeap Sort\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}

//***************************************************************************
//Given a max heap, this function sorts all elements in increasing order of
//their IDs. Note: we explicitly separate the HeapSort algorithm with
//its underline MaxHeap data structure. You can put the sorted elements inside
//another array, then print them out.
void heapSort(MaxHeap* oneMaxHeap) 
{
	Student* newStuArr = oneMaxHeap->getStuArr(); // Creates a new student pointer called newStuArr to access the stuArr
	Student* incOrderArray = new Student[oneMaxHeap->getSize()]; // Will be used for the swap.
	int elementsHeld = oneMaxHeap->getSize() - 1; // Integer used to hold the size of the array.
	for (int i = elementsHeld; i >= 0; i--) // For loop that goes through the elements.
	{
		incOrderArray[i] = newStuArr[0]; // Setting the root of stuArr to the index we're at in incOrderArray.
		oneMaxHeap->extractHeapMax(); // We extract the heap max so that every passing of the for loop the new root of the array gets stored in the next index of incOrderArray.
	}
    //print out format is given as below
	for (int i = 0; i <= elementsHeld; i++)
	{
    	cout << left << setw(8) << incOrderArray[i].id
             << setw(12) << incOrderArray[i].firstName
             << setw(12) << incOrderArray[i].lastName
             << setw(8) << fixed << setprecision(2) << incOrderArray[i].gpa << endl;	
	}
}
