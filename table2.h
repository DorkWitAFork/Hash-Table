/*
	Spencer Le Bleu
	SID #1555744
	CISP 430
	Professor Huang
	Assignment 6

	Header file for our table class.
	We will be using a hash table to store our data. Collisons will be handled by chaining. The underlying data structure will be a linked list.
	I will implement this with a template class to allow for any data type to be stored in the table.

*/

// FILE: table2.h
// TEMPLATE CLASS PROVIDED: Table<RecordType> (a table of records with keys)
// 
// CONSTRUCTOR for the Table<RecordType> template class:
// Table( )
//    Postcondition: The Table has been initialized as an empty Table.
// 
// COPY CONSTRUCTOR for the Table<RecordType> template class:
// Table(const Table<RecordType>& source)
//    Postcondition: The Table has been initialized to be a copy of the Table source.
// 
// ASSIGNMENT OPERATOR for the Table<RecordType> template class:
// Table<RecordType>& operator=(const Table<RecordType>& source)
//   Postcondition: If this Table is not the same object as source, the Table is made a copy of source.
// 
// 
// DESTRUCTOR for the Table<RecordType> class:
// ~Table( )
//   Postcondition: Any dynamic memory allocated for the Table has been released.
// 
//  
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
// void insert(const RecordType& entry)
//   Precondition: entry>= 0. Also if entry is not already a key in the table, then the Table has space for another record.   (i.e., size( ) < CAPACITY).
//   Postcondition: If the table already had a record with a key equal to entry, then that record is replaced by entry. Otherwise, the entry will be added as a new record of the Table.
// 
// void remove(int key)
// Postcondition: If a record was in the Table with the specified key, then that record has been removed; otherwise the table is unchanged.
// 
// 
// void print(int index) const
// Postcondition: The record with the specified key has been printed to the screen.
// 
// 
// void table_delete()
// Postcondition: The table has been deleted.
// 
// 
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
// bool is_present(const RecordType& target) const
// Postcondition: The return value is true if there is a record in the Table with the specified key. Otherwise, the return value is false.
// 
// void find(int key, bool& found, RecordType& result) const
// Postcondition: If a record is in the Table with the specified key, then found is true and result is set to a copy of the record with that key. Otherwise found is false.
// 
// size_t size( ) const
// Postcondition: Return value is the total number of records in the Table.
// 
// VALUE SEMANTICS for the Table<RecordType> template class:
// Assignments and the copy constructor may be used with Table objects.
//

#ifndef TABLE2_H
#define TABLE2_H

#include <cstdlib>
#include "link2.h"



template < class RecordType >
class Table
{
private:

	static const size_t TABLE_SIZE = 10;
	Node<RecordType> *data[TABLE_SIZE];
	size_t total_records;
	size_t hash(int key) const { return key % TABLE_SIZE; }
	Node<RecordType>* find_node(Node<RecordType> *&cursor,Node<RecordType> *&precursor, int key) const;	// done



public:
	// CONSTRUCTOR
    Table();															

	// COPY CONSTRUCTOR
	Table(const Table<RecordType>& source);								
	
	// DESTRUCTOR
	~Table();															
	
	// ASSIGNMENT OPERATOR
	Table<RecordType>& operator=(const Table<RecordType>& source);		

	// MODIFICATION MEMBER FUNCTIONS
	void insert(const RecordType& entry);								
	void remove(int key);												
	void print(int index) const;										
	void table_delete();

	// CONSTANT MEMBER FUNCTIONS
	bool is_present(const RecordType & target) const;					
	void find(int key, bool& found, RecordType& result) const;			
	size_t size() const { return total_records; }						
};

#endif

#include "table2.template"

