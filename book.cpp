//--------------------------book.cpp file---------------------------------------
// Member function definitions for abstract base class Book
// Class can not be instantiated as it has several pure virtual methods that
// are implemented in its derived classes
#include "book.h"


//------------------------------------------------------------------------------
//Default constructor
Book::Book()
{
	
}

//------------------------------------------------------------------------------
//Default destructor
Book::~Book()
{

}

//------------------------------------------------------------------------------
//getFormat
// Returns the char that represents the format of the book. 'H' = Hard copy etc.
char Book::getFormat() const
{
	return bookFormat;
}

//------------------------------------------------------------------------------
//getTitle
// Returns the title of the Book as a string
string Book::getTitle() const
{
	return title;
}

//------------------------------------------------------------------------------
//getStock
// Returns the current stock of the Book as an int
int Book::getStock() const
{
	return stock;
}

//------------------------------------------------------------------------------
//getYear
// Returns the publish year of the Book
int Book::getYear() const
{
	return year;
}

//------------------------------------------------------------------------------
//getType
// Returns the char that represents the type of the Book. i.e. FBook = 'F'
char Book::getType() const
{
	return type;
}

//------------------------------------------------------------------------------
//setTitle
// Takes string theTitle as an argument as sets the title of the book with it.
// theTitle is read from the given text files
void Book::setTitle(string theTitle)
{
	title = theTitle;
}

//------------------------------------------------------------------------------
//setFormat
// Takes char theFormat as an argument and sets the format of the book with it.
// theFormat is read from the given text files
void Book::setFormat(char theFormat)
{
	bookFormat = theFormat;
}

//------------------------------------------------------------------------------
//setStock
// Takes int theStock as an argument and sets the current stock of the book
// theStock is determined by the type of Book being created. Defined in derived
// classes.
void Book::setStock(int theStock)
{
	stock = theStock;
}

//------------------------------------------------------------------------------
//setYear
// Takes int theYear as an argument and sets the publish year of the book
// theYear is read from the given text files
void Book::setYear(int theYear)
{
	year = theYear;
}

//------------------------------------------------------------------------------
//setType
// Takes char theType as an argument and sets the type of the book with it.
// theType is read from the given text files
void Book::setType(char theType)
{
	type = theType;
}