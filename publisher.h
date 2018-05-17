//---------------------publisher.h file-----------------------------------------
// Publisher is the Books factory class
// Handles creating Book objects 
#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "book.h"
#include "fbook.h" //figure out how to not have to include all derived classes
#include "pbook.h"
#include "ybook.h"
#include "command.h"
//------------------------------------------------------------------------------
//Book factory class BookFactory: Publisher is a factory class that returns an
//        empty Book object to the manager class Librarian. Each derived class
//        of Book has a char associated with it which is defined in their class
//        This char is read from the data4books and data4commands text files.
//        When the manager class reads a char from the text files it is passed
//        to the Publisher class to see if it has an associated Book attached to
//        it. If there is a Book associated with it the Publisher class returns
//        the associated Book object to the manager to process.
//
//Implementation and Assumptions
//    --Empty Books are stored in a 26 element array in the index associated 
//    with the char they are represented by. For example FBook has the char 'F'
//    associated with it, so it it stored in element 5.
//    --hash function returns the integer value associated with the char that
//    is passed to it. Example 'C' = 2, 'R' = 17 etc.
//    --The default constructor initializes every element of the Book*[] to NULL
//    After that it places each derived Book class object in it's associated 
//    index.
//    --createBook method hashes the char passed to it and returns the empty
//    Book object associated with the char if it exists.
//------------------------------------------------------------------------------
class Publisher
{
public:
	
	Publisher();  //default constructor
	~Publisher();  //default destructor

	//creates an empty book of the given type and returns it
	Book* createBook(char) const; 

private:
	//Stores Book and derived class objects for creation of Book objects
	Book* bookFactory[26]; 

	//returns integer value of char. a=1, b=2 etc
	int hash(char type) const; 

};

#endif