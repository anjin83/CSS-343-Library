//-----------------------------user.cpp file------------------------------------
// Member function definitions for class User
#include "user.h"

//------------------------------------------------------------------------------
//Default constructor
// Creates two empty BookLists, one to store User's history and the other to 
// store the Book's currently checked out by the User
User::User()
{
	history = new BookList();
	checkedOut = new BookList();
}

//------------------------------------------------------------------------------
//Default destructor
// Deletes the two BookLists that store the Users history and checked out Books.
// Deletion of list is handled by BookList class.
User::~User()
{
	delete history;
	delete checkedOut;
}

//------------------------------------------------------------------------------
//setName
// Sets the User's first and last names
void User::setName(string last, string first)
{
	lastName = last;
	firstName = first;
}

//------------------------------------------------------------------------------
//setUserID
// Sets the User's unique ID. ID can only be between 0 and 9999
bool User::setUserID(int ID)
{
	if (ID > 0 && ID < 10000)
	{
		userID = ID;
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
//getFirstname
// Returns User's firstName
string User::getFirstName() const
{
	return firstName;
}

//------------------------------------------------------------------------------
//getLastName
// Returns User's lastName
string User::getLastName() const
{
	return lastName;
}

//------------------------------------------------------------------------------
//getName
// Returns User's full name as a single string in format "lastName firstName"
string User::getName() const
{
	return getLastName() + " " + getFirstName();
}

//------------------------------------------------------------------------------
//getId
// Returns User's unique ID
int User::getID() const
{
	return userID;
}

//------------------------------------------------------------------------------
//printUser
// Returns User's info as single string in format "lastName firstName ID"
string User::printUser() const
{
	return getName() + " " + to_string(getID());
}

//------------------------------------------------------------------------------
//findBook
// Searches the list of Books the User currently has checked out for the book
// provided as an argument. Returns true if found, false otherwise
bool User::findBook(Book* theBook) const
{
	return checkedOut->find(theBook);
}

//------------------------------------------------------------------------------
//printHistory
// Prints the Users name and ID along with a history of the checkouts and 
// returns performed and what books they were performed on.
void User::printHistory() const
{
	cout << "*** Patron ID = " << getID() 
		<< " " << getLastName() 
		<< " " << getFirstName() 
		<< endl;
	history->displayHistory();
}

//------------------------------------------------------------------------------
//insertBook
// Adds Book and Command to User's history and list of currently checked out
// Books. Actual insertion of Books into lists is handled by BookList class.
void User::insertBook(Book* theBook, string commandType)
{
	history->insert(theBook, commandType);
	checkedOut->insert(theBook, commandType);
}

//------------------------------------------------------------------------------
//insertBookToHistory
// Adds Book and Command just to User's history list. Actual insertion of Book
// is handled by BookList class.
void User::insertBookToHistory(Book* theBook, string commandType)
{
	history->insert(theBook, commandType);
}

//------------------------------------------------------------------------------
// Removes provided Book from the User's list of currently checked out Books if
// Book is presenet in list.
void User::removeBook(Book* theBook)
{
	checkedOut->remove(theBook);
}