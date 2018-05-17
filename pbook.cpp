//----------------------------pbook.cpp file------------------------------------
// Member function defintions for derived class PBook : Book
#include "pbook.h"

//------------------------------------------------------------------------------
//Default constructor
// Sets the format, type and stock of the book. Default format is 'H' for 
// hardcopy, type = 'P' for periodical and default stock for periodicals books 
// is 1.
PBook::PBook()
{
	setFormat('H');
	setType('P');
	setStock(1);
}

//------------------------------------------------------------------------------
//Default destructor
PBook::~PBook()
{

}

//------------------------------------------------------------------------------
//Operator== overload
// Compares two PBooks and returns true if their title, year and month match. 
// Operator is passed a Book object which is downcast to an PBook object. This
// is done so that the function can work polymorphically in ADTs that store Book
// objects.
bool PBook::operator==(const Book *theBook) const
{
	//Downcast theBook so it can be compared correctly
	const PBook *book = dynamic_cast<const PBook*>(&*theBook);
	bool isEqual = true;

	//Check if title and publish date match
	if (getTitle() != book->getTitle())
		isEqual = false;
	if (getYear() != book->getYear())
		isEqual = false;
	if (getMonth() != book->getMonth())
		isEqual = false;

	//Delete temp pointers
	book = NULL;
	delete book;

	//Return equality
	return isEqual;
}

//------------------------------------------------------------------------------
//Operator!= overload
// Compares two PBooks and returns false if their author and title do not match. 
// Operator is passed a Book object which is downcast to an PBook object. This
// is done so that the function can work polymorphically in ADTs that store Book
// objects.
bool PBook::operator!=(const Book *theBook) const
{
	//Downcast theBook into an FBook so that it can be compared.
	const PBook *book = dynamic_cast<const PBook*>(&*theBook);
	bool equality = (*this == book);

	//Delete temp pointers
	book = NULL;
	delete book;

	//Return inequality
	return !(equality);
}

//------------------------------------------------------------------------------
//printBook
// Returns the books information such as title, publish date and stock
// as a string.
string PBook::printBook() const
{
	string output = string(1, getType()) + " " + string(1, getFormat()) + " " 
		+ ((getMonth() < 1 || getMonth() >12) ? "" : to_string(getMonth())) + " "
		+ ((getYear() < 1 || getYear() > 2017) ? "": to_string(getYear())) + " "  // go back and add static const int for current year
		+ getTitle();
	return output;
}

//------------------------------------------------------------------------------
//create
// Creates an empty PBook and returns it. Used in the Book factory class 
// Publisher.
PBook* PBook::create() const
{
	return new PBook();
}

// Returns the books sorting criteria as a single string. Used for comparing two
// books and determining where to store the book in relation to other books of 
// the same type
string PBook::sortingCriteria() const
{
	string sorting = to_string(getYear()) + to_string(getMonth()) + getTitle();
	return sorting;
}

//------------------------------------------------------------------------------
//setData
// Takes a string formatted in the method provided in the data4books.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format.
void PBook::setData(string data)
{
	stringstream ss(data);
	string dataMember;

	//get and set title
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ',');
	setTitle(dataMember);

	//get and set month
	getline(ss, dataMember, ' '); //take care of blank space at beginning of strings
	getline(ss, dataMember, ' ');
	int month =  atoi(dataMember.c_str());
	setMonth(month);

	//get and set year
	getline(ss, dataMember);
	int year =  atoi(dataMember.c_str());
	setYear(year);
}

//------------------------------------------------------------------------------
//setDataFromCommand
// Takes a string formatted in the method provided in the data4commands.txt and
// sets the books data members. Assumes that string data provided is in the 
// correct format. Used only for creating temporary FBooks.
void PBook::setDataFromCommand(string data)
{
	//Create stringstream object to extract data from
	stringstream ss(data);
	//Create string that will hold each individual piece of data
	string dataMember;

	//get and set year
	//handle blank
	getline(ss, dataMember, ' ');
	getline(ss, dataMember, ' ');
	int year = atoi(dataMember.c_str());
	setYear(year);

	//get and set month
	getline(ss, dataMember, ' ');
	int month = atoi(dataMember.c_str());
	setMonth(month);

	//get and set title
	getline(ss, dataMember, ',');//Next data member ends at the next comma
	setTitle(dataMember);
}

//------------------------------------------------------------------------------
//displayBook
// Displays stock information of the periodical along with the periodicals 
// information such as the title, author and publish date.
void PBook::displayBook() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(STOCK_OUTPUT_WIDTH) << getStock();
	displayBookInfo();
}

//------------------------------------------------------------------------------
//displayBookInfo
// Displays the periodical information such as title, author, publish date
void PBook::displayBookInfo() const
{
	cout.setf(ios::left, ios::adjustfield);
	cout<< setw(YEAR_OUTPUT_WIDTH) << getYear()
		<< setw(MONTH_OUTPUT_WIDTH) << getMonth()
		<< setw(TITLE_OUTPUT_WIDTH) 
		<< getTitle().substr(0, TITLE_OUTPUT_WIDTH - 1) 
		<< endl;
}

//------------------------------------------------------------------------------
// Returns the publish month of the periodical
int PBook::getMonth() const
{
	return month;
}

//------------------------------------------------------------------------------
// Sets the publish month of the periodical
void PBook::setMonth(int theMonth)
{
	month = theMonth;
}
string PBook::getName() const
{
	return "";
}

