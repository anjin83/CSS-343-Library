//-------------------------fbook.h file-----------------------------------------
//  Derived class FBook : Book. Represents a Fiction book in a library
//
#ifndef FBOOK_H
#define FBOOK_H
#include"book.h"
//------------------------------------------------------------------------------
//Derived class Fbook : Book : Fbook is a derived class of Book that represents
//        Fiction books. It has the additional fields firstName and lastName to
//        store the authors first and last names
//
//Implementation and Assumptions
//    --FBooks type is stored as the char 'F'
//    --FBook default format is stored as the char 'H', represents hardcopy
//    --FBooks default stock value is 5
//    --Stock, type and format is set in the default contructor
//    --FBooks are first by Author, then by title. sortingCriteria method 
//    returns the sortingCriteria in a single string for sorting purposes
//    --setData and setDataFrom command assume that the string being passed to 
//    them are formatted correctly.
//    --setData takes the string extracted from the data4books.txt file
//    --setDataFromCommand takes the string extracted from the data4commands.txt
//    --displayBook outputs the FBook's stock, then it's information in the 
//    following order: Author, Title, Publish year
//------------------------------------------------------------------------------
class FBook : public Book {
	friend ostream &operator<<(ostream &, const FBook &);

public:
	FBook();  //Default constructor
	~FBook();  //Default destructor

	//Operator overload
	//Overloaded ==, compares 2 FBooks
	virtual bool operator==(const Book*) const; 

	 //Overloaded !=, compares 2 FBooks
	virtual bool operator!=(const Book*) const;

	//Returns book info including stock as a string
	virtual string printBook() const;

	virtual FBook* create() const; //creates an empty FBook and returns it

	//Returns sorting criteria as a string to compare 2 FBooks for sorting
	virtual string sortingCriteria() const; 

	//Reads the string from the build library text file and sets the data for
	//the FBook
	virtual void setData(string);

	//Reads the partial string from the command file and sets the data for the
	//FBook. Only used for creating temporary books for commands.
	virtual void setDataFromCommand(string data);

	//Displays the current stock of the book and all of the books information
	void displayBook() const;

	//Displays just the books information, i.e. Author, Title, not stock
	virtual void displayBookInfo() const;
//------------------------------------------------------------------------------
	//Getters 
	//Returns author as string in format "lastname firstname"
	virtual string getName() const; 

//------------------------------------------------------------------------------
	//Setters
	//Sets authors first and last names
	virtual void setName(string first, string last);

protected:
	string firstName; //Authors first name
	string lastName;  //Authors last name

};



#endif