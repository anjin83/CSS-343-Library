//--------------------------user.h file-----------------------------------------
// ADT class User
// Stores all of the relevant information for Library patrons
#ifndef USER_H
#define USER_H
#include "booklist.h"
//------------------------------------------------------------------------------
//Abstract Data Type User: User class represents a user of the library. It is
//        stored in the BookLibrary class by it's unique ID. The User is created
//        by the manager class when it processes the data4users file. Each User
//        object has a name, and ID and two BookList's; one for currently 
//        checked out books and one for the Users history.
//
//Implementation and Assumptions
//    --Default constructor creates empty lists for history and checkedOut
//    --printUser returns as a single string the User's name and ID
//    --findBook checks the User's currently checked out books for the given 
//    Book object.
//    --insertBook will insert the Book and it's associated command to both 
//    lists.
//    --insertBookToHistory will only insert the Book and it's associated 
//    command to the history list.
//    --findBook, insertBook and insertBookToHistory assume that the Book
//    being passed to it is valid. Data validation occurs before the method
//    is called.
//    --removeBook only removes the given Book from the checkedOut list. It does
//    not affect the history list.
//------------------------------------------------------------------------------
class User {

public:
	User(); //default constructor
	~User(); //default destructor

	//Returns User info as a string. Does not return Book history
	string printUser() const; 

	//Looks for given Book object in Users checked out Books.
	bool findBook(Book*) const;

	//Prints the Users Library history
	void printHistory() const;
	
	//Inserts given Book and Command into history list. Also inserts Book into 
	//User's currently checked out books.
	void insertBook(Book*, string);

	//Inserts a Book and Command into just Users history list. Only used when 
	//returning a Book and you don't want info inserted into checked out books.
	void insertBookToHistory(Book*, string);

	//Removes given Book from Users currently checked out Books list.
	void removeBook(Book*);

//------------------------------------------------------------------------------
	//Setters
	//Sets Users first and last name.
	void setName(string last, string first);

	//Sets Users unique Library ID
	bool setUserID(int ID);

//------------------------------------------------------------------------------
	//Getters
	string getFirstName() const;  //Gets Users first name
	string getLastName() const;  //Gets Users last name
	string getName() const;  //Gets users name in format "lastName, firstName"
	int getID() const;  //Returns Users unique Library ID

private:
	//List that stores all actions performed by Users and the Books that action
	//was performed on. Stored in a doubly linked list.
	BookList *history;

	//List that stores all currently checked out Books. Stored in doubly linked
	//list.
	BookList *checkedOut;

	string firstName; //Users first name
	string lastName;  //Users last name
	int userID;  //Users unique Library ID
};
#endif