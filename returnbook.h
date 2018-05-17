//-----------------------returnbook.h file--------------------------------------
// Method class ReturnBook
// Performs the ReturnBook method, is given a user ID and a Book, looks for User
// in Library. If User is found, the Book is searched for in their currently
// checked out books list. If it is found, the Book is returned to the Library
#ifndef  RETURNBOOK_H
#define RETURNBOOK_H
#include "command.h"
//------------------------------------------------------------------------------
//Derived Command class ReturnBook: ReturnBook is a derived Command class object 
//        that performs the action of returning a Book to the library and
//        removing that Book from a User. The method uses a Command factory 
//        to create the method based on hashing the first character in the 
//        data4commands class. The ReturnBook class is associated with the char 
//        'R'. The manager class Librarian receives the ReturnBook method when
//        reading it's associated char from the data4commands.txt file and
//        receives the object from the CommandFactory. The perform method
//        performs the action for the class. It takes a User, Book and 
//        BookLibrary object. If the User is valid and the Book is in the 
//        User's currently checked out books, it removes the book from that
//        list, increments the stock in the library, and add the Book and
//        the Command to the User's history.
//
//Implementation and Assumptions
//    --perform method assumes that the Book handed to it is valid. Object
//    validation is performed before the Book is handed to the method.
//    --perform method checks to see if the User ID given has a valid User
//    associated with it. If the ID is invalid the method returns false
//    --constructor assigns commandName string with associated command. This
//    is used for the User's history list to associate Commands with Books
//    --create method returns a CheckOut object. It is used in the command 
//    factory to return methods to the manager class Librarian.
//------------------------------------------------------------------------------
class ReturnBook : public Command
{
public:
	ReturnBook();  //Default constructor
	~ReturnBook();  //Default destructor
	//perform method perfoms the actions of returning a book
	virtual bool perform(User*, Book*, BookLibrary*) const;
	//create an empty ReturnBook object and return it.
	virtual ReturnBook* create() const;

private:
	//Name of command as string, Used in when printing user history
	string commandName;
};


#endif

