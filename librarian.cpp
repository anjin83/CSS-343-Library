//---------------------------librarian.cpp file---------------------------------
// Member function definitions for manager class Librarian
#include "librarian.h"
#include <iostream>
#include <fstream>

//------------------------------------------------------------------------------
//Default constructor
// Creates new factory objects that the class will use to create books and 
// process commands.
Librarian::Librarian()
{
	publish = new Publisher();
	cFactory = new CommandFactory();
}

//------------------------------------------------------------------------------
//Default destructor
// Delete factories.
Librarian::~Librarian()
{
	delete publish;
	delete cFactory;
}

//------------------------------------------------------------------------------
//buildLibrary
// Populates BookLibrary theLibrary with Books created from file inFile. The 
// data provided from inFile is assumed to be formatted correctly. Creates Books
// based on the data provided from inFile. Invalid lines are ignored. Publisher
// class is used to create the Books. Adding of the Books is performed by the
// BookLibrary class.
void Librarian::buildLibrary(ifstream& infile, BookLibrary* theLibrary) {

	//intialize variable to store text read from file
	char bookType;
	string data;

	//create book to store info read from file
	Book* tempBook;
	tempBook = NULL;

	//read the file and build the library
	for (;;)
	{
		//break out of the loop at the end of the text file
		if (infile.eof()) break;

		//read the character and create a book of that type if applicable
		infile >> bookType;

		tempBook = publish->createBook(bookType); //read char and create book 
		if(tempBook != NULL) //char was valid, book was created and returned
		{
			getline(infile, data);
			tempBook->setData(data);
			theLibrary->addBook(tempBook); 
		}
		else //command is invalid, go to next line
		{
			getline(infile, data);
		}
		tempBook = NULL;
	}
	//delete temporary pointers
	delete tempBook;
}

//------------------------------------------------------------------------------
//addUsers
// Populates User database in theLibrary with Users created from file inFile. 
// The data provided from inFile is assumed to be formatted correctly. Invalid 
// lines are ignored. Users are hashed and stored by their User ID. Adding of
// the User is performed by the BookLibrary class.
void Librarian::addUsers(ifstream& infile, BookLibrary* theLibrary)
{
	//create temp variables to store information read from file
	int ID;
	User* tempUser;
	string dataMember;

	//read the text file
	for (;;)
	{
		//create empty User
		tempUser = new User();
		if (!infile.eof())
		{
			//Read file and create user with info provied
			getline(infile, dataMember, ' ');
			if (dataMember == "")
				break;
			ID = atoi(dataMember.c_str());
			tempUser->setUserID(ID);
			getline(infile, dataMember, ' ');
			string last = dataMember;
			getline(infile, dataMember);
			string first = dataMember;
			tempUser->setName(last, first);

			theLibrary->addUser(tempUser); //Set the user in the database

			//delete temporary pointers
			tempUser = NULL;
			delete tempUser;
		}
	}
}

//------------------------------------------------------------------------------
//processCommands
// Processes commands provided by inFile. The data provided from inFile is 
// assumed to be in the correct format. Command objects are created by cFactory
// based on a hash of the first char in the line provided by inFile. The User
// is then pulled based on the ID provided by the line. A temporary Book is then
// created using the rest of the line provided. Action performed is based on the
// char read at the beginning of the line.
void Librarian::processCommands(ifstream& infile, BookLibrary* theLibrary)
{
	//initialize variable to stored text read from file
	char commandType;
	char bookType;
	char bookFormat;
	int ID;
	string dataMember;

	//Create temporary pointers for Book and Command objects
	Command *command;
	Book* tempBook;

	//Read the text file inFile
	for (;;)
	{
		//break out of loop at the end of the file
		if (infile.eof()) break;

		//read the character and create a book of that type if applicable
		infile >> commandType;
		command = cFactory->createCommand(commandType);

		//valid character read from file
		if (command != NULL) 
		{
			//get ID for User 
			infile >> dataMember;
			ID = atoi(dataMember.c_str());

			//Create temp book using info in file
			infile >> bookType;
			tempBook = publish->createBook(bookType);

			//checks if book is a valid type
			if (tempBook != NULL)
			{
				//get format of book do inside setDataFromCommand
				infile >> bookFormat;
				tempBook->setFormat(bookFormat);

				//set tempBook data
				getline(infile, dataMember);
				tempBook->setDataFromCommand(dataMember);

				//do command
				command->perform(theLibrary->getUser(ID), 
					tempBook, theLibrary);

			}
		}
		else //command is invalid, go to next line
		{
			getline(infile, dataMember);
		}

		//delete all temporary pointers
	}
	command = NULL;
	tempBook = NULL;
	delete command;
	delete tempBook;
}