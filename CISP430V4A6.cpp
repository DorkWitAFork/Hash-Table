/*
	Spencer Le Bleu
	SID #1555744
	CISP 430
	Professor Huang
	Assignemnt 6

	This is our main driver file, which will be used to test the Table class.
	We will instantiate two Table objects, and then use the random number generator to add 70 numbers to each object.
	We will then call the remove function to remove all the contents of the first object.
	Lastly, we will use the assignment operator overload to assign the contents of the second object to the first object.
	
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "table2.h"

using namespace std;

int main()
{
	// feed random number generator with the current time
	srand(time(0));

	// Our table objects
	Table<int> t1;
	Table<int> t2;

	cout << "Instantiate two Table objects." << endl << endl;
	cout << "                     Total records in the first Table object is " << t1.size() << endl;
	cout << "                     Contents of the first object displayed here:" << endl;

	// Display the contents of the first object
	for (size_t i = 0; i < 10; ++i) t1.print(i);
	cout << "---------------------------------------------------------------------------" << endl;

	cout << "                     Total records in the second Table object is " << t2.size() << endl;
	cout << "                     Contents of the second object displayed here:" << endl;

	// Display the contents of the second object
	for (size_t i = 0; i < 10; ++i) t2.print(i);
	cout << "===========================================================================" << endl;

	cout << endl << endl << endl << "**Using random number generator to add 70 numbers to each Table object.**" << endl << endl << endl;

	// Add 70 random numbers to each object
	for (size_t i = 0; i < 70; i++)
	{
		int random = rand() % 201;
		t1.insert(random);
	}
	// Add 70 random numbers to each object
	for (size_t i = 0; i < 70; i++)
	{
		int random = rand() % 201;
		t2.insert(random);
	}

	// Display the contents of the first object
	cout << "                     Total records in the first Table object is " << t1.size() << endl;
	cout << "                     Contents of the first object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t1.print(i);
	cout << "---------------------------------------------------------------------------" << endl;

	// Display the contents of the second object
	cout << "                     Total records in the second Table object is " << t2.size() << endl;
	cout << "                     Contents of the second object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t2.print(i);
	cout << "===========================================================================" << endl;


	// Remove all the contents of the first object
	t1.table_delete();
	cout << endl << endl << endl << "** Calling remove function removes all the contents of the first object. **";
	cout << endl << endl << endl;

	// Display the contents of the first object
	cout << "                     Total records in the first Table object is " << t1.size() << endl;
	cout << "                     Contents of the first object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t1.print(i);
	cout << "---------------------------------------------------------------------------" << endl;


	// Display the contents of the second object
	cout << "                     Total records in the second Table object is " << t2.size() << endl;
	cout << "                     Contents of the second object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t2.print(i);
	cout << "===========================================================================" << endl;


	// Use the assignment operator overload to assign the contents of the second object to the first object
	t1 = t2;
	cout << endl << endl << endl;


	cout << "Lastly, we will use the assignment operator overload." << endl;
	cout << " ** Using TBObject1 = TBObject2 displays the assignment operator overloading. **";
	cout << endl << endl << endl;

	// Display the contents of the first object
	cout << "                     Total records in the first Table object is " << t1.size() << endl;
	cout << "                     Contents of the first object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t1.print(i);
	cout << "---------------------------------------------------------------------------" << endl;


	// Display the contents of the second object
	cout << "                     Total records in the second Table object is " << t2.size() << endl;
	cout << "                     Contents of the second object displayed here:" << endl;
	for (size_t i = 0; i < 10; ++i) t2.print(i);
	cout << "===========================================================================" << endl;

	// Pause the system to allow the user to view the output before automatically exiting. 
	system("pause");

	return 0;
}