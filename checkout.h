//------------------------checkout.h file---------------------------------------
//  method class CheckOut
//  Performs the CheckOut method, is given a user ID and Book, looks for user
//  and Book in Library. If both are found, it checks out the Book from the 
//  Library and adds that Book to the Users history and checkedOut List.
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <iostream>
#include "command.h"
//#include "user.h"
//#include "book.h"
#include "bookLibrary.h"
//------------------------------------------------------------------------------
//Derived Command class CheckOut: CheckOut is a derived Command class object 
//        that performs the action of checking out a Book from the library and
//        adding that Book to a User. The method uses a Command factory class
//        to create the method based on hashing the first character in the 
//        data4commands class. The CheckOut class is associated with the char 
//        'C'. The manager class Librarian receives the CheckOut method when
//        reading it's associated char from the data4commands.txt file and
//        receives the object from the CommandFactory. The perform method
//        performs the action for the class. It takes a User, Book and 
//        BookLibrary object. If the User is valid and the Book is in stock
//        in the BookLibrary, the stock is decremented and the Book is added
//        to the User's history and checked out list.
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
class CheckOut : public Command
{
public:
	CheckOut();  //default constructor
	~CheckOut();  //default destructor
	//perform method performs the actions of checking out a book
	virtual bool perform(User*, Book*, BookLibrary*) const;
	//create an empty CheckOut object, used in comandFactory
	virtual CheckOut* create() const;

private:
	//Name of command as string, Used in when printing user history
	string commandName; 
};
#endif
