//----------------------------checkout.cpp file---------------------------------
// Member function definitions for the Method class CheckOut
#include "checkout.h"

//------------------------------------------------------------------------------
//Default constructor
CheckOut::CheckOut()
{
	//Assign command name
	commandName = "Checkout";
}

//------------------------------------------------------------------------------
//Default destructor
CheckOut::~CheckOut()
{

}

//------------------------------------------------------------------------------
//perform
// Performs the CheckOut method. Method is given a User, a Book object and is
// handed the library where the Book will be searched for. Method checks for 
// valid User, then searches the BookLibrary for the given Book. If the Book is
// found, the User's currently checked out books are searched to see if the 
// Book has already been check out by User. If the Book has not been checked out
// by User the Book is added to their history and currently checked out Books 
// list and the stock of the Book is decremented. Returns true if action was
// successful, false otherwise.
bool CheckOut::perform(User* theUser, Book* theBook, BookLibrary* theLibrary) const
{
	//Check if User is valid
	if(theUser == NULL)
		return false;

	//Create temporary Book to store data read from file.
	Book *tempBook;

	//Look for book in library and return a pointer to book if found
	theLibrary->retrieveBook(theBook, tempBook); 
	if (tempBook != NULL)// found the book and tempBook points to it
	{
		//At least one book in stock and user has not checked book out already
		if (tempBook->getStock() > 0
			&& !theUser->findBook(tempBook))
		{
			//Decrement stock and add Book to User
			tempBook->setStock(tempBook->getStock() - 1);
			theUser->insertBook(tempBook, commandName);
		}
		//Delete temp pointers
		tempBook = NULL;
		delete tempBook;
		return true;
	}
	//Action was not succesful, delete temp pointers and return false.
	tempBook = NULL;
	delete tempBook;
	return false;
}

//------------------------------------------------------------------------------
//create
// Creates and empty CheckOut object and returns it. Used in CommandFactory 
// class.
CheckOut* CheckOut::create() const
{
	CheckOut* commandObject = new CheckOut();
	return commandObject;
}