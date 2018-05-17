//---------------------------publisher.cpp file---------------------------------
// Member function definitions for Publisher class
// Factory class for Book objects. Used to create empty Books for Librarian 
#include "publisher.h"

//------------------------------------------------------------------------------
//Default constructor
// Initializes factory with Book classes derived class objects. Objects are
// stored in the factory based on a hash of the char that represents the book's
// type.
Publisher::Publisher()
{
	//Initiailize each element of factory to NULL
	for (int i = 0; i < 26; i++)
	{
		bookFactory[i] = NULL;
	}

	//Populate factory with empty Book's derived class objects
	bookFactory[5] = new FBook();
	bookFactory[15] = new PBook();
	bookFactory[24] = new YBook();

}

//------------------------------------------------------------------------------
//Default destructor
// Deletes each element of the Book*[] and then deletes the pointer to the array
Publisher::~Publisher()
{
	for (int i = 0; i < 26; i++)
	{
		delete bookFactory[i];
		bookFactory[i] = NULL;
	}
	delete[] *bookFactory;
}

//------------------------------------------------------------------------------
//createBook
// Hashes the character provided by the text file and creates an empty Book
// class associated with that character. Returns the derived Book class if a 
// valid char is hashed, returns NULL otherwise;
Book* Publisher::createBook(char bookType) const
{
	int index = hash(bookType);
	if(bookFactory[index] != NULL)
		return bookFactory[index]->create();
	else
		return NULL;
}

//------------------------------------------------------------------------------
//hash
// Returns an integer value of the given character. For example, 'A' returns 0,
// 'B' returns 1 etc. Books are hashed by type to determine which Command
// object to create and return
int Publisher::hash(char type) const
{
	return (type - 'A');
}
