//--------------------------fbook.cpp file--------------------------------------
// Member function definitions for derived class FBook : Book

#include "fbook.h"

using namespace std;
//------------------------------------------------------------------------------
//Default constructor
// Sets the format, type and stock of the book. Default format is 'H' for 
// hardcopy, type = 'F' for fiction and default stock for fiction books is 5.
FBook::FBook()
{
	setFormat('H');
	setType('F');
	setStock(5);
}

//------------------------------------------------------------------------------
//Default destructor
FBook::~FBook()
{

}

//------------------------------------------------------------------------------
//Operator== overload
// Compares two FBooks and returns true if their author and title match. 
// Operator is passed a Book object which is downcast to an FBook object. This
// is done so that the function can work polymorphically in ADTs that store Book
// objects.
bool FBook::operator==(const Book *theBook) const
{
	//Downcast theBook into an FBook so that it can be compared.
	const FBook *book = dynamic_cast<const FBook*>(&*theBook);

	bool isEqual = true;

	//Check if author and title match
	if(getName() != book->getName())
		isEqual = false;
	if(getTitle() != theBook->getTitle())
		isEqual = false;

	//Delete temporary pointer
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
bool FBook::operator!=(const Book *theBook) const
{
	//Downcast theBook so it can be compared correctly
	const FBook *book = dynamic_cast<const FBook*>(&*theBook);
	bool equality = (*this == book);

	//Delete temp pointers
	book = NULL;
	delete book;

	//Return inequality
	return !(equality);
}

//------------------------------------------------------------------------------
//create
// Creates an empty FBook and returns it. Used in the Book factory class 
// Publisher.
FBook* FBook::create() const
{
	return new FBook();
}

//------------------------------------------------------------------------------
//printBook
// Returns the books information such as title, author, publish date and stock
// as a string.
string FBook::printBook() const
{
	
	string output = string(1, getType()) + " " + string(1, getFormat()) + ' ' + getName() + 
		", " + getTitle() + 
		", " + to_string(getYear());
	return output;
}

//------------------------------------------------------------------------------
//displayBook
// Displays stock information of the book along with the books information such
// as the title, author and publish date.
void FBook ::displayBook() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(STOCK_OUTPUT_WIDTH) << getStock();
	displayBookInfo();
}

//------------------------------------------------------------------------------
//displayBookInfo
// Displays the books information such as title, author, publish date
void FBook::displayBookInfo() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(NAME_OUTPUT_WIDTH) << getName().substr(0, NAME_OUTPUT_WIDTH)
		<< setw(TITLE_OUTPUT_WIDTH) << getTitle().substr(0, TITLE_OUTPUT_WIDTH)
		<< setw(YEAR_OUTPUT_WIDTH) << getYear() << endl;
}

//------------------------------------------------------------------------------
//sortingCriteria
// Returns the books sorting criteria as a single string. Used for comparing two
// books and determining where to store the book in relation to other books of 
// the same type
string FBook::sortingCriteria() const
{
	string sorting = getName() + getTitle();
	return sorting;
}

//------------------------------------------------------------------------------
//setData
// Takes a string formatted in the method provided in the data4books.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format.
void FBook::setData(string data)
{
	//Create stringstream object to extract data from
	stringstream ss(data);
	//Create string that will hold each individual piece of data
	string dataMember;

	//get and set first and last name
	string last;
	getline(ss, last, ' ');//handle blank at the beginning of string
	getline(ss, last, ' ');
	string first;
	getline(ss, first, ',');//Next data member ends at the next comma
	setName(last, first);

	//get and set title
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ',');//Next data member ends at the next comma
	setTitle(dataMember);

	//get and set year
	getline(ss, dataMember);
	int year =  atoi(dataMember.c_str()); //Convert string to int
	setYear(year);
}

//------------------------------------------------------------------------------
//setDataFromCommand
// Takes a string formatted in the method provided in the data4commands.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format. Used only for creating temporary FBooks.
void FBook::setDataFromCommand(string data)
{
	//Create stringstream object to extract data from
	stringstream ss(data);
	//Create string that will hold each individual piece of data
	string dataMember;

	//get and set first and last name
	string last;
	getline(ss, last, ' '); //handle blank at beginning of string
	getline(ss, last, ' ');
	string first;
	getline(ss, first, ',');//Next data member ends at the next comma
	setName(last, first);

	//get and set title
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ',');//Next data member ends at the next comma
	setTitle(dataMember);
}

//------------------------------------------------------------------------------
//getName
// Returns the authors name in the format "lastname firstname" as a string
string FBook::getName() const
{
	string authorName = lastName + " " + firstName;
	return authorName;
}

//------------------------------------------------------------------------------
//setName
// Sets the authors name
void FBook::setName(string last, string first)
{
	firstName = first;
	lastName = last;
}
