//------------------------------------------------------------------------------
// Member function definitions for the method class ReturnBook : Command
#include "returnbook.h"

//------------------------------------------------------------------------------
//Default constructor
ReturnBook::ReturnBook()
{
	//Assign command name
	commandName = "Return";
}

//------------------------------------------------------------------------------
//Default destructor
ReturnBook::~ReturnBook()
{

}

//------------------------------------------------------------------------------
//perform
// Performs the ReturnBook method. Method is given a User, a Book object and is
// handed the library where the Book will be searched for. Method checks for 
// valid User, then searches that Users currently checked out books for the 
// given Book. If the Book is found in the list, the book is then found in the
// library and it's stock is incremented. the Book and Command are then added
// to the User's history. Returns true if successful, false otherwise.
bool ReturnBook::perform(User* theUser, Book* theBook, BookLibrary* theLibrary) const
{
	//Create temp pointer to store location of Book in library
	Book *tempBook;

	//Look for the book in the library and return a pointer to the book if found
	theLibrary->retrieveBook(theBook, tempBook); 

	// found the book and tempbook points to it & Book is currently checked 
	// out by user
	if (tempBook != NULL 
		&& theUser != NULL 
		&& theUser->findBook(theBook))
	{
		//increment stock 
		tempBook->setStock(tempBook->getStock() + 1);

		//Add command and Book to User's history
		theUser->insertBookToHistory(tempBook, commandName);

		//Remove Book from User's currently checked out Books
		theUser->removeBook(tempBook);
		 
		//Delete temp pointer
		tempBook = NULL;
		delete tempBook;
		return true;
	}
	//Delete temp pointer
	tempBook = NULL;
	delete tempBook;
	return false;
}

//------------------------------------------------------------------------------
//create
// Creates and empty ReturnBook object and returns it. Used in CommandFactory 
// class.
ReturnBook* ReturnBook::create() const
{
	ReturnBook* commandObject = new ReturnBook();
	return commandObject;
}