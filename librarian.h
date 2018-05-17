//------------------------librarian.h file--------------------------------------
// Manage class for Library. 
// Handles processing the given text files for building the library, adding
// library patrons, and processing commands.
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "publisher.h"
#include "bookLibrary.h"
#include "commandfactory.h"
//------------------------------------------------------------------------------
//Manager class Librarian: Librarian is the manager class for the BookLibrary
//        class. It performs the actions of reading the text files provided and
//        building the library, adding the library's users and processing the 
//        commands. It contains both a Book factory class Publisher and a 
//        command factory class CommandFactory to create Books and Command
//        objects respectively.
//
//Implementation and Assumptions
//    --Librarian constructor creates a Publisher object and a CommandFactory
//    object that are used to create books and Command objects.
//    --buildLibrary method assumes that the data provided by data4books.txt is
//    formatted correctly.
//    --buildLibrary method reads the character at the beginning of each line of
//    the data4books.txt file and creates the associated Book if the char is 
//    valid. If the character is invalid the line is skipped and the method
//    moves on to the next line.
//    --buildLibrary method creates the Books through the Publisher class. The
//    Book's data fields are then populated by the rest of the text in the line.
//    The method assumes this text is correctly formatted.
//    --addUsers method reads the int given at the beginning of the data4users
//    text file. If the number is out of range or is already taken the line is
//    ignored and the method moves to the next line.
//    --addUser method assumes that the data is formatted correctly in the 
//    text file.
//    --processCommands processes the commands through the CommandFactory class.
//    It reads the character at the beginning of each line of data4commands and
//    creates the associated command object if the char is valid. If the char
//    is invalid the method ignores the line and moves on to the next one.
//    --processCommands creates a temporary Book object through the Publisher
//    class by reading the first character of the line after the Command char.
//    if the character is invalid it skips the rest of the line and goes to the
//    next.
//    --processCommands assumes the data in the rest of line is formatted 
//    correctly for its associated book type.
//------------------------------------------------------------------------------
class Librarian
{
    public:
		Librarian();  //Default constructor
		~Librarian();  //Default destructor

		//Builds the library from the given text file
		void buildLibrary(ifstream&, BookLibrary*);

		//Adds library patrons from the given text file
		void addUsers(ifstream&, BookLibrary*);

		//Processes commands from the given text file
		void processCommands(ifstream& infile, BookLibrary* theLibrary);
		
    private:
		//BookFactory handles creating Books for building the Library for
		//buildLibrary() method
		Publisher* publish;  

		//CommandFactory handles creating Command objects for processing
		//commands for processCommands() method.
		CommandFactory* cFactory;
};

#endif
