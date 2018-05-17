//------------------------commandfactory.cpp file-------------------------------
// Member function definitions for CommandFactory Class
// Factory class for Command objects. Used to create empty derived Command class
// objects.
#include "commandfactory.h"

//------------------------------------------------------------------------------
//Default constructor
// Initializes factory with Command classes derived class objects. Objects are
// stored in factory based on a hash of the char that represents the class in
// the provided text file. CheckOut = 'C' = 2 and ReturnBook = 'R' = 17
CommandFactory::CommandFactory()	
{
	//Initialze all elements in Command*[] commandFactory to NULL;
	for (int i = 0; i < 26; i++)
	{
		commandFactory[i] = NULL;
	}
	//Store Command classes derived classes in factory
	commandFactory[2] = new CheckOut();
	commandFactory[17] = new ReturnBook();
}

//------------------------------------------------------------------------------
//Default destructor
// Deletes each element of the Command*[] and then deletes the pointer to the 
// array.
CommandFactory::~CommandFactory()
{
	//delete pointers in commandFactory
	for(int i = 0; i < 26; i++)
		delete commandFactory[i];
	//delete array pointer
	delete[] *commandFactory;
}

//------------------------------------------------------------------------------
//createCommand
// hashes the character provided by the text file and creates the
// empty Command object associated with that character. Returns the Command 
// object if it exists, returns NULL otherwise.
Command* CommandFactory::createCommand(char commandType) const
{
	int index = hash(commandType);
	if (commandFactory[index] != NULL)
		return commandFactory[index]->create();
	else
		return NULL;
}

//------------------------------------------------------------------------------
//hash
// Returns an integer value of the given character. For example, 'A' returns 0,
// 'B' returns 1 etc. Commandss are hashed by type to determine which Command
// object to create and return
int CommandFactory::hash(char type) const
{
	return (type - 'A');
}