//---------------------commandfactory.h file------------------------------------
//  Factory class for Command method classes
//  Stores empty Command objects, creates empty Command objects and returns
//  them through the createCommand method
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "command.h"
#include "checkout.h"
#include "returnbook.h"
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------
//Command factory class CommandFactory: CommandFactory is a factory class that
//        returns Command objects to the manager class Librarian. These command
//        objects perform all of the BookLibrary-User actions such as checking
//        out books and returning books. Each derived command class has a char
//        associated with it that is read by the manager class from the 
//        data4commands text file. When the manager class reads a char from the
//        text file it is pass to the CommandFactory to see if it has an 
//        associated Command attached to it. If there is a Command associated
//        with it the Command factory then returns the associated Command object
//        to the manager class to process
//
//Implementation and Assumptions
//    --Commands are stored in 26 element array in the index associated with the
//    char that they are represented by. For example CheckOut is associated with
//    the char 'C'. The hash function returns 'C''s int represenation, which is
//    2, and the CheckOut object is stored in element 2 of the array.
//    --The default constructor for the CommandFactory class initializes every 
//    element of the Command[] to NULL. After that it places each derived 
//    Command object in it's associated index.
//    --hash function returns the integer value associated with the char that
//    is passed to it. Example 'C' = 2, 'R' = 17 etc.
//    --createCommand method hashes the character that is passed to it and 
//    returns the command object stored in the index represented by the char.
//------------------------------------------------------------------------------
class CommandFactory
{
public:
	CommandFactory();  //Default constructor
	~CommandFactory();  //Default destructor
	//creates an empty command object and returns it
	Command* createCommand(char) const;
	
private:
	//Stores command objects for creation
	Command* commandFactory[26];
	//hash gives the index for the desired Command object. Returns the int
	//value of the character given to it. i.e. 'A' = 0, 'C' = 2
	int hash(char type) const;
};

#endif

