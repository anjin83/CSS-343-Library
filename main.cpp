//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>

#include "librarian.h"
#include "bookLibrary.h"

using namespace std;

int main()
{
	BookLibrary *library = new BookLibrary();
	Librarian *lib = new Librarian();
	ifstream infile("data4books.txt");
	lib->buildLibrary(infile, library);
	library->printLibrary();

	ifstream infile2("data4patrons.txt");
	lib->addUsers(infile2, library);

	ifstream infile3("data4commands.txt");
	lib->processCommands(infile3, library);
	library->printLibrary();
	library->printUsers();
	
}
