//-------------------------pbook.h file-----------------------------------------
//  Derived class PBook : Book. Represents a Periodical in a library
//
#ifndef PBOOK_H
#define PBOOK_H
#include"book.h"
//------------------------------------------------------------------------------
//Derived class Pbook : Book : Pbook is a derived class of Book that represents
//        periodicals. PBooks have the additional field month to store the 
//        periodicals publish month.
//
//Implementation and Assumptions
//    --PBooks type is stored as the char 'P'
//    --PBook default format is stored as the char 'H', represents hardcopy
//    --PBooks default stock value is 1
//    --Stock, type and format is set in the default contructor
//    --PBooks are sorted first by year, then by month, then by title. 
//    sortingCriteria method returns the sorting Criteria in a single string for
//    sorting purposes
//    --setData and setDataFrom command assume that the string being passed to 
//    them are formatted correctly.
//    --setData takes the string extracted from the data4books.txt file
//    --setDataFromCommand takes the string extracted from the data4commands.txt
//    --displayBook outputs the PBook's stock, then it's information in the 
//    following order: Year, Month, Title
//------------------------------------------------------------------------------
class PBook : public Book {
	friend ostream &operator<<(ostream &, const PBook &);

public:
	PBook(); //Default constructor
	~PBook();  //Default destructor

	//operator overload
	//overloaded ==, compares 2 PBooks
	virtual bool operator==(const Book*) const; 

	//overloaded !=, compares 2 FBooks
	virtual bool operator!=(const Book*) const; 

	//returns book infor including stock as a string
	virtual string printBook() const;

	virtual PBook* create() const; //creates an empty PBook and returns it

	//returns sorting criteria as a string to compare 2 PBooks for sorting
	virtual string sortingCriteria() const; 

	//reads the string from the build library text file and sets the data for
	//the PBook
	virtual void setData(string);

	//Reads the partial string from the command file and sets the data for the
	//book. Only used for creating temporary books for commands.
	virtual void setDataFromCommand(string data);

	//Displays the current stock of the book and all of the books information
	void displayBook() const;

	//Displays just the books information, i.e. title, year, not stock
	virtual void displayBookInfo() const;

	//getters 
	virtual int getMonth() const;  //get publish month
	virtual string getName() const;  //get publish year

	//setters
	virtual void setMonth(int month);  //set publish month

protected:
	int month; //stores publish month for periodical
	//sets output width for month when formatting book output
	static const int MONTH_OUTPUT_WIDTH = 3; 

};
#endif