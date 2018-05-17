//---------------------------booklibrary.h file---------------------------------
// Abstract data type BookLibrary. 
// Data structure that stores the library patrons and Books
//
#ifndef BOOKLIBRARY_H
#define BOOKLIBRARY_H
#include <string>
#include <iostream>
#include "booktree.h"
#include"user.h"
using namespace std;
//------------------------------------------------------------------------------
//Abstract data type BookLibrary: BookLibrary is the database class that stores
//        all of the Books in the library as well as the information on the 
//        patrons that use the library. The Books are store in binary search
//        trees, one for each type of book, arranged in an array. The index
//        at which the Book is stored is based on the integer value of the 
//        type of Book. Users are stored in a 10000 element array by their
//        unique ID.
//
//Implementation and Assumptions:
//    -- addBook and addUser methods assume that the arguments passed to them
//    are valid. These methods are only called after the data being passed to 
//    them has been verified good.
//    -- Books are stored in binary search trees in a 26 element array. Each
//    element of the array points to the root of a tree. The Book's type is
//    hashed by the library's hash function which returns the index that 
//    contains the tree they will be stored in.
//    -- userDB has all elements initialized to NULL when the BookLibrary's 
//    constructor is called.
//    -- bookDB is initialized with an empty tree at each element of it's array
//    in the BookLibrary's constructor
//------------------------------------------------------------------------------
class BookLibrary {

public:
	BookLibrary();  //Default constructor
	~BookLibrary();  //Default destructor
	
	//Adds a Book* to array bookDB[]
	bool addBook(Book*);

	//Adds a User* to array userDB[]
	bool addUser(User*);

	//Returns index for storing and accessing books in bookDB[] array
	int hash(char bookType) const;

	//Prints out all of the books in the library in sorted order
	void printLibrary() const;

	//Prints out all of the users in the library in order of ID
	void printUsers() const;

	//Looks for a given book in array bookDB[], assigns pointer to tempBook
	// argument if it is found. NULL pointer is assigned otherwise
	bool retrieveBook(Book*, Book* &);

	//Retrieves User* from userDB[] if it exists, given int is userID
	User* getUser(int) const;

private:
	//An array of BookTree*'s that stores all of the books. Each book type has
	//an index in the array. Books hashed by book type i.e. FBook.type = 'f',
	//hash('f') = 5, so FBooks are stored in the BookTree stored in index 5.
	BookTree* bookDB[26];

	//An array of User*'s that stores all of the library patrons. Users are
	//hashed by the User's ID. The ID is the index they are stored in. Duplicate
	//ID's are not allowed.
	User* userDB[10000];
};

#endif

