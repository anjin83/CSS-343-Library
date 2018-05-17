//-----------------------------------book.h file--------------------------------
// Abstract base class Book. Represents a book in a library.
// Derived classes are specialized books in the library 
//
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

//------------------------------------------------------------------------------
//Abstract base class Book: Book is an abstract base class that defines all of
//        methods and fields that are used between all of the derived book 
//        classes. All data members are primitive data types. Numerous pure
//        virtual functions are defined for the specialized derived classes
//        to implement.
//
//Implementation and Assumptions:
//    --Book pointers are stored in the Library class inside of trees and in
//    the User class inside of two lists.
//    --All methods aside from getters and setters of the data fields are 
//    defined in the derived classes.
//    --method sortingCriteria returns as a single string the sorting criteria
//    of the derived specialized book class. this is used to sort the books in
//    the tree they are stored in. Each book will compare the string returned
//    by this method to determine where the book should be placed.
//------------------------------------------------------------------------------

class Book {

public:
	Book(); //Default constructor
	~Book();  //Default destructor

	//operator overloads
	//Compares two books and returns true if they are equal
	virtual bool operator==(const Book*) const = 0;
	//Compares two books and returns false if they are equal
	virtual bool operator!=(const Book*) const = 0;

	//Pure virtual methods

	//creates an empty book object. Implemented in all derived classes
	virtual Book* create() const = 0;

	//returns all of the books data fields in a single string
	virtual string printBook() const = 0;

	//Returns as a single string the sorting criteria for the book
	virtual string sortingCriteria() const = 0;

	//reads the string from the build library text file and sets the data for
	//the book
	virtual void setData(string) = 0;

	//Reads the partial string from the command file and sets the data for the
	//book. Only used for creating temporary books for commands.
	virtual void setDataFromCommand(string data) = 0;

	//Displays the current stock of the book and all of the books information
	virtual void displayBook() const = 0;

	//Displays just the books information
	virtual void displayBookInfo() const = 0;

	//Gets the books name
	virtual string getName() const = 0;

//------------------------------------------------------------------------------	
	// getters 
	virtual char getFormat() const;
	virtual string getTitle() const;
	virtual int getStock() const;
	virtual int getYear() const;
	virtual char getType() const;

//------------------------------------------------------------------------------
	//setters
	virtual void setTitle(string);
	virtual void setFormat(char);
	virtual void setStock(int);
	virtual void setYear(int);
	virtual void setType(char);
	

protected:
	int stock; //Current number of this book in the library
	string title;  //Title of the book
	int year;  //Year the book was published
	char bookFormat; //Format of book i.e. hardcopy, digital, etc.
	char type;  //Type of book i.e. fiction, youth, periodical
	static const int STOCK_OUTPUT_WIDTH = 6;  //Width for outputting stock
	static const int NAME_OUTPUT_WIDTH = 22;  //Width for outputting author
	static const int TITLE_OUTPUT_WIDTH = 40;  //Width for outputting title
	static const int MONTH_OUTPUT_WIDTH = 2;  //Width for outputting month
	static const int YEAR_OUTPUT_WIDTH = 5;  //Width for outputting year
	
};


#endif
