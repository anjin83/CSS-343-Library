//--------------------------ybook.cpp file--------------------------------------
// Member function definitions for derived class YBook : Book

#include "ybook.h"

//------------------------------------------------------------------------------
//Default constructor
// Sets the format, type and stock of the book. Default format is 'H' for 
// hardcopy, type = 'Y' for fiction and default stock for fiction books is 5.
YBook::YBook()
{
	setFormat('H');
	setStock(5);
	setType('Y');
}

//------------------------------------------------------------------------------
//Default destructor
YBook::~YBook()
{

}

//------------------------------------------------------------------------------
//Operator== overload
// Compares two YBooks and returns true if their author and title match. 
// Operator is passed a Book object which is downcast to an YBook object. This
// is done so that the function can work polymorphically in ADTs that store Book
// objects.
bool YBook::operator==(const Book *theBook) const
{
	//Downcast theBook so it can be compared correctly
	const YBook *book = dynamic_cast<const YBook*>(&*theBook);
	bool isEqual = true;

	//Check if Author and Title match
	if(getName() != book->getName())
		isEqual = false;
	if(getTitle() != book->getTitle())
		isEqual = false;

	//Delete temp pointers
	book = NULL;
	delete book;

	//Return equality
	return isEqual;
}

//------------------------------------------------------------------------------
//Operator!= overload
// Compares two FBooks and returns false if their author and title do not match. 
// Operator is passed a Book object which is downcast to an FBook object. This
// is done so that the function can work polymorphically in ADTs that store Book
// objects.
bool YBook::operator!=(const Book *theBook) const
{
	//Downcast theBook so it can be compared correctly
	const YBook *book = dynamic_cast<const YBook*>(&*theBook);
	bool equality = (*this == book);

	//Delete temp pointers
	book = NULL;
	delete book;
	
	//return inequality
	return !(equality);
}

//------------------------------------------------------------------------------
//create
// Creates an empty YBook and returns it. Used in the Book factory class 
// Publisher.
YBook* YBook::create() const
{
	return new YBook();
}

//------------------------------------------------------------------------------
//printBook
// Returns the books information such as title, author, publish date and stock
// as a string.
string YBook::printBook() const
{
	string output = string(1, getType()) + " " + string(1, getFormat()) + " " + getName() 
		+ ", " + getTitle() 
		+ ", " + to_string(getYear());
	return output;
}

//------------------------------------------------------------------------------
//sortingCriteria
// Returns the books sorting criteria as a single string. Used for comparing two
// books and determining where to store the book in relation to other books of 
// the same type
string YBook::sortingCriteria() const
{
	string sorting = getTitle() + getName();
	return sorting;
}


//------------------------------------------------------------------------------
//setData
// Takes a string formatted in the method provided in the data4books.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format.
void YBook::setData(string data)
{
	stringstream ss(data);
	string dataMember;

	//get and set first and last name
	string last;
	getline(ss, last, ' '); //handle blank at beginning of string
	getline(ss, last, ' ');
	string first;
	getline(ss, first, ',');
	setName(last, first);

	//get and set title
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ',');
	setTitle(dataMember);

	//get and set year
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember);
	int year =  atoi(dataMember.c_str());
	setYear(year);
}


//------------------------------------------------------------------------------
//setDataFromCommand
// Takes a string formatted in the method provided in the data4commands.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format. Used only for creating temporary FBooks.
void YBook::setDataFromCommand(string data)
{
	stringstream ss(data);
	string dataMember;

	//get and set title
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ',');
	setTitle(dataMember);

	//get and set first and last name
	string last;
	getline(ss, last, ' '); //handle blank at beginning of string
	getline(ss, last, ' ');
	string first;
	getline(ss, first, ',');
	setName(last, first);
}


//displayBook
// Displays stock information of the book along with the books information such
// as the title, author and publish date.
void YBook::displayBook() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(STOCK_OUTPUT_WIDTH) << getStock();
	displayBookInfo();
}


//------------------------------------------------------------------------------
//displayBookInfo
// Displays the books information such as title, author, publish date
void YBook::displayBookInfo() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(TITLE_OUTPUT_WIDTH) 
		    << getTitle().substr(0, TITLE_OUTPUT_WIDTH - 1)
		<< setw(NAME_OUTPUT_WIDTH) 
		    << getName().substr(0, NAME_OUTPUT_WIDTH - 1)
		<< setw(YEAR_OUTPUT_WIDTH) << getYear() << endl;
}


//------------------------------------------------------------------------------
//getName
// Returns the authors name in the format "lastname firstname" as a strin
string YBook::getName() const
{
	string authorName = lastName + " " + firstName;
	return authorName;
}

//------------------------------------------------------------------------------
//setName
// Sets the authors name
void YBook::setName(string last, string first)
{
	firstName = first;
	lastName = last;
}