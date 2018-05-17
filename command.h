//----------------------------command.h file------------------------------------
// Abstract base class for command method objects
// 
#ifndef COMMAND_H
#define COMMAND_H
#include "bookLibrary.h"
//------------------------------------------------------------------------------
//Abstract base class Command: Command is an abstract base class that all 
//        library-patron methods derive from. It has two pure virtual functions
//        that are defined by it's derived classes: perform and create. Perform
//        is the action that will be performed by derived classes and create
//        will return a copy of the derived class from the CommandFactory.
//------------------------------------------------------------------------------
class Command
{
public:
	Command(); //Default constructor
	~Command();  //Default destructor
	//perform method performs the actions of the derived class object
	virtual bool perform(User*, Book*, BookLibrary*) const = 0;
	//create an empty Command object, used in comandFactory
	virtual Command* create() const = 0;
private:

};
#endif
