//-------------------booklibrary.cpp file---------------------------------------
// Member function definitions for abstract data type BookLibrary
#include "booktree.h"
#include "bookLibrary.h"

//------------------------------------------------------------------------------
//Default constructor
// Initializes the BookTree*[] bookDB that is used to store the books in the 
// Library. Also initializes the User*[] userDB that is used to store users. 
// bookDB[] creates an empty tree for each element of the array. userDB[] sets
// all elements initially to NULL values.
BookLibrary::BookLibrary()
{
	//Create empty BookTrees in each element of bookDB[]
	for(int i = 0; i < 26; i++)
		bookDB[i] = new BookTree();
	//Initialize all elements of userDB[] as NULL
	for (int i = 0; i < 10000; i++)
		userDB[i] = NULL;
}

//------------------------------------------------------------------------------
//Default destructor
// Iterates through each element of the BookTree*[] bookDB and deletes the tree
// that is stored their. Deletion of the tree is handled by the BookTree object.
// Iterates through each element of the User*[] userDB and deletes any User that
// is stored there. Deletion of Users is handled by the User object.
BookLibrary::~BookLibrary()
{
	//Delete all of the BookTree stored in the database
	for(int i = 0; i < 26; i++)
	{
		delete bookDB[i];
	}
	delete[] *bookDB;  //Delete the array pointer

	//Delete all of the Users stored in the database
	for(int i = 0; i < 10000; i++)
	{
		delete userDB[i];
	}
	delete[] *userDB; //Delete the array pointer
}

//------------------------------------------------------------------------------
//addBook
// Takes a given Book object and adds it to database. hash function determines
// which tree the Book should be inserted to based on the Book's type. Actual
// insertion of the Book into the tree is handled by the BookTree object. 
// Duplicate books are not inserted into the database. Duplicate Books are 
// handled by BookTree object.
bool BookLibrary::addBook(Book* theBook)
{
	int index = hash(theBook->getType()); //Determine which tree to insert book
	bookDB[index]->insert(theBook); //BookTree handles Book insertion
	return true;
}

//------------------------------------------------------------------------------
//addUser
// Takes a given User object and adds it to the database. index to store User is
// determined by the User's unique library ID. If a User already exists with 
// given ID number the Library will not insert the User.
bool BookLibrary::addUser(User* theUser)
{
	//Insert the User at index userDB[userID]
	userDB[theUser->getID()] = theUser;
		return true;
}

//------------------------------------------------------------------------------
//hash
// Returns an integer value of the given character. For example, 'A' returns 0,
// 'B' returns 1 etc. Books are hashed by type to determine which tree to insert
// them into.
int BookLibrary::hash(char bookType) const
{
	return (bookType - 'A');
}


////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
//printLibrary
// Prints the contents of the entire library database in order of the Books
// sorting criteria. Actual output of BookTrees is handled in BookTree object
void BookLibrary::printLibrary() const
{
	//Iterate through book database and print every BookTree stored there
	for(int i =0; i<26; i++)
	{
		if(!bookDB[i]->isEmpty())
			bookDB[i]->printSortedBooks();
	}
}

////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
//printUsers
// Prints the contents of the entire Userdatabase in order of User Id.
// Actual output of User is handled in User object
void BookLibrary::printUsers() const
{
	for (int i = 0; i < 10000; i++)
	{
		if (userDB[i] != NULL)
			userDB[i]->printHistory();
	}
}

////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
//retrieveBook
// Looks for given Book in the library database. Assigns pointer  to the 
// tempBook argument if it is found. Actual searching for Book in BookTrees is 
// handled in the BookTree object.
bool BookLibrary::retrieveBook(Book* theBook, Book* &tempBook)
{
	//Determine which tree to search for Book in
	int index = hash(theBook->getType());
	//Search for the book in that tree
	bookDB[index]->retrieve(theBook, tempBook);
	return true;
}

//------------------------------------------------------------------------------
//getUser
// Returns user with given user ID if they exist. Returns NULL other wise.
User* BookLibrary::getUser(int userID)const
{
	return userDB[userID];
}