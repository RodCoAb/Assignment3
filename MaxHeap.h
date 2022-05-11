// ASU Spring 2022 CSE310 HW#3
// Your Name: Rodrigo Corrales
// ASU ID: 1216550582
// ASU Email address: rcorral7@asu.edu
// Description: This is the header file with functions detailing a max heap.
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>
// Imports defined above ^^^
using namespace std;

//Each Student will have a unique id
struct Student // Struct data structure for a Student.
{
	int id; // Unique identifying id.
	string firstName, lastName; // Student first and last names.
    double gpa; // Gpa for a student.
};

//class MaxHeap represents a max heap that contains Student objects. The underline data structure
//is a one dimensional array of Student.
class MaxHeap
{
    private:
	struct Student* stuArr;	//an array of Student
	int capacity, size; // Capacity is up to how many elements the heap may hold, size is how many are actually in the heap at the moment.

	public:
	MaxHeap(int capacity); // DONE. Constructor is taken care of.
	~MaxHeap(); // DONE. Destructor is taken care of.

	Student* getStuArr(); // DONE. Accessor method.
	int getSize(); // DONE. Accessor method.
	int getCapacity(); // DONE. Accessor method.
	int isFound(int stuId); // DONE. This is taken care of.
	bool heapIncreaseID(int index, Student oneStudentwithNewID); // DONE. This is taken care of.
	bool heapInsert(int id, string firstName, string lastName, double gpa); // DONE. This is taken care of.
	void heapify(int index); // DONE. This is taken care of.
	Student getHeapMax(); // DONE. Accessor method.
	void extractHeapMax(); // DONE. This is taken care of.
	int leftChild(int parentIndex); // DONE. This is taken care of.
	int rightChild(int parentIndex); // DONE. This is taken care of.
	int parent(int childIndex); // DONE. This is taken care of.
	void printHeap(); // DONE. This is takent care of.
};

MaxHeap::MaxHeap(int capacity) //Constructor to dynamically allocate memory for a heap with the specified capacity
{
	this->capacity = capacity; // Helps set the capacity of the heap.
	size = 0; // Initializes the size of the heap to 0.
	stuArr = new Student[capacity]; // Dynamically allocates memory for "stuArr" of "capacity" number of Student objects.
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
MaxHeap::~MaxHeap() // Destructor. Prints the amount of deleted students.
{
	int studentNum = 0; // Counter variable. Keeps track of number of deleted students.
	studentNum = size; // Setting counter variable to size of the heap.
	delete [] stuArr; // Deletes the student array.
	cout << "\nThe number of deleted Students is: " << studentNum << endl; // Prints the size out of the heap.
}

//Finish all the remaining functions according to the project's description
Student* MaxHeap::getStuArr() //Getter method for the stuArr variable. 
{
	return stuArr; // Returns the stuArr variable.
}
int MaxHeap::getSize() // Getter method for the size variable.
{
	return size; // Returns the size variable.
}
int MaxHeap::getCapacity() // Getter method for the capacity variable.
{
	return capacity; // Returns the capacity variable.
}
int MaxHeap::isFound(int someId) // Method that will declare whether a student is found in the heap based on the id input.
{
	for (int i = 0; i <= size - 1; i++) // Loop to iterate through the array.
	{
		if (stuArr[i].id == someId) // condition to check the student id at that particular input and comparing it to the input id.
		{
			return i; // Return index if criteria is met.
		}
	}
	return -1; // Returns -1 if the student id is not found in the array.
}
void MaxHeap::heapify(int someIndex) // Method that keeps the max heap properties. It's called recursively.
{
		Student temp; // Used to swap values
		int largest; // Variable to hold the biggest.
		int left = leftChild(someIndex); // Variable that holds the index of the left child.
		int right = rightChild(someIndex); // Variable that holds the index of the right child.
		
	if (left <= (size - 1) && stuArr[left].id > stuArr[someIndex].id) // Checks if the left child's id is bigger than the parent.
	{
		largest = left; // If yes, sets the variable largest to the index of the left child.
	}
	else // If the left child is not the larget element.
	{
		largest = someIndex; // If not, the parent remains as the largest.
	}
	if (right <= (size - 1) && stuArr[right].id > stuArr[largest].id) // Checks to see if id of the right child is bigger than the parent's.
	{
		largest = right; // Sets the variable largest to the index of the right child.
	}
	if (largest != someIndex) // If the largest id is not the same as the parent's id.
	{
		temp = stuArr[someIndex]; // Temp holds the value of stuArr[i]. Will be used to exchange later.
		stuArr[someIndex] = stuArr[largest];  // Overrides stuArr[i] with stuArr[largest].
		stuArr[largest] = temp; // Sets stuArr[largest] equal to stuArr[i]. Swap is completed successfully.
		heapify(largest); // Recursive call of heapify on the largest index.
	}
}
bool MaxHeap::heapIncreaseID(int someIndex, Student studentWithNewID) // Method that increases the id of an existing element.
{
	Student temp; // Temp student object.
	if (studentWithNewID.id < stuArr[someIndex].id) // Checks if the id of the new student object is smaller than the id of the student object at someIndex.
	{
		return false; // This would throw an error message, defined in cpp file.
	}
	stuArr[someIndex].id = studentWithNewID.id; // Overrides the student object's id at someindex with new student object's id 
	while (someIndex > 0 && stuArr[parent(someIndex)].id < stuArr[someIndex].id)
	{
		temp = stuArr[someIndex]; // sets temp to A[i].
		stuArr[someIndex] = stuArr[parent(someIndex)]; // Overwrites A[i] with A[parent(i)]
		stuArr[parent(someIndex)] = temp; // Overwrites A[parent(i)] with A[i]. Finishes swap.		
		someIndex = parent(someIndex); // sets someIndex to the parent by using paren
	}
	return true;
}

bool MaxHeap::heapInsert(int someId, string someFirstName, string someLastName, double someGpa) // Method that inserts a student object to the end of the heap, then floats it up if necessary to maintain the max heap property.
{
	if (isFound(someId) != -1) // Checks if id is already in the heap.
	{
		cout << "\nDuplicated Student. Not added";
		return false;
	}
	// Creation of a dummy student to have it's place set to the end of the heap.
	Student smoothbrain; // Dummy student object.
	smoothbrain.id = -10000; // Setting dummy student id to small number so it gets added to the end of the heap.
	smoothbrain.firstName = someFirstName; // Sets dummy first name to soeFirstName.
	smoothbrain.lastName = someLastName; // Sets dummy last name to someLastName
	smoothbrain.gpa = someGpa; // Sets dummy object gpa to someGpa
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	// Creation of the new student object and setting it's info.
	Student insertStudent; // Making the student object we actually wanna insert.
	insertStudent.id = someId; // Sets id.
	insertStudent.firstName = someFirstName; // Sets first name.
	insertStudent.lastName = someLastName; // Sets last name.
	insertStudent.gpa = someGpa; // Sets gpa.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (size == capacity) // Checks if the heap is at full capacity.
	{
		this->capacity = capacity * 2; // Doubles the capacity.
		Student* copyArray = new Student[capacity]; // Creates new array with double the initial capacity.
		for (int i = 0; i <= size - 1; i++) // For loop that goes through all elements.
		{
			copyArray[i] = stuArr[i]; // Copies the elements of old stuArr into new stuArr.
		}
		stuArr = copyArray; // sets the original array to the new array.
		cout << "\nReach the capacity limit, double the capacity now.\nThe new capacity now is " << capacity << endl;
	}  
	
	size++; // Increments length of the array.
	stuArr[size - 1] = smoothbrain; // Places dummy at size - 1 index in the heap.
	heapIncreaseID(isFound(-10000), insertStudent); // Calling heapIncreaseID on new student object to maintain max heap property.
	return true;
}

Student MaxHeap::getHeapMax() // Getter method that returns the Student object at the root of the heap.
{
	return stuArr[0]; // Returns the student object at the root of the heap.
}
void MaxHeap::extractHeapMax() // Method that extracts the root of the heap. Root is replaced by final element, then we heapify() and decrease size of the heap by 1.
{
	if (size < 1) // Error catching.
{
	return;
}
	Student max = stuArr[0]; // Setting the max variable to the first element.
	stuArr[0] = stuArr[size - 1]; // First element is swapped with the last element
	size = size - 1; // Decrements the heap size by one every time.
	heapify(0); // Recursive call to heapify root and maintain the max heap property.
}

int MaxHeap::leftChild(int parentIndex) // Method that defines the left child.
{
	return (2 * (parentIndex + 1) - 1);
}
int MaxHeap::rightChild(int parentIndex) // Method that defines the right child.
{
	return (2 * (parentIndex + 1));
}
int MaxHeap::parent(int childIndex) // Method that defines the parent.
{
	return ((childIndex - 1)/ 2); 
}

void MaxHeap::printHeap() // Method in charge of printing out the heap's elements in a particular order.
{
	if (size == 0) // Checks if the heap is empty.
	{
		cout << "Empty heap, no elements" << endl; // Message to be displayed if the heap is empty.
	}
	else // Prints the heap in the specified format.
	{
		cout << "\nHeap capacity = " << capacity << endl;
		cout << "\nHeap size = " << size << "\n" << endl;

		for (int i = 0; i <= size - 1; i++) // Iterates through the array of students.
		{
			// This below is the formatting for the print function vvv.
			cout << left;
			cout << setw(8) << stuArr[i].id
					<< setw(12) << stuArr[i].firstName
					<< setw(12) << stuArr[i].lastName
					<< setw(8) << fixed << setprecision(2) << stuArr[i].gpa << endl;
		}
	}
}

		    
