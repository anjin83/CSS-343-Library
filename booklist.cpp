//---------------------------booklist.cpp file----------------------------------
// Abstract data type BookList
// Doubly linked list that stores pointers to Book Objects
// Used in User class to store their history and currently checked out books.
#include "booklist.h"

//------------------------------------------------------------------------------
//Default constructor
// Initializes the front and back pointers to NULL
BookList::BookList()
{
	front = NULL;
	back = NULL;
}

//------------------------------------------------------------------------------
//Default destructor
// Iterates through each node of the list and deletes the nodes, then deletes
// the front and back pointers
BookList::~BookList()
{
	//If there are nodes, delete them
	if (!isEmpty())
		makeEmpty();
	//delete front and back pointers
	delete front;
	delete back;
}

//------------------------------------------------------------------------------
//getFront
// Returns the Book* stored in the first node of the list if it exists
Book* BookList::getFront() const
{
	if (!isEmpty())
		return front->nodeData;
	else
		return NULL;
}

//------------------------------------------------------------------------------
//getBack
// Returns the Book* stored at the front of list if it exists
Book* BookList::getBack() const
{
	if (!isEmpty())
		return back->nodeData;
	else
		return NULL;
}

//------------------------------------------------------------------------------
//isEmpty
// Checks to see if there is anything in the list. Returns true if list is empty
bool BookList::isEmpty() const
{
	return(front==NULL && back == NULL);
}

//------------------------------------------------------------------------------
//makeEmpty
// Deletes all of the nodes in the list and sets front and back pointers to NULL
// Used in destructor
void BookList::makeEmpty()
{
	//Point to front of list and iterate through list, deleting all nodes
	ListNode *cur = front;
	//If there are nodes in the list, delete them
	if(!isEmpty())
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
			cur->prev->next = NULL;
			delete cur->prev->next;
			cur->prev->prev = NULL;
			delete cur->prev->prev;
			delete cur->prev;
		}
	}

	//List is empty or cur at end of list, Delete cur's next and prev pointers
	cur->next = NULL;
	cur->prev = NULL;
	delete cur->next;
	delete cur->prev;

	//delete cur and set front and back to NULL
	delete cur;
	front = NULL;
	back = NULL;
}

//------------------------------------------------------------------------------
//remove
// Searches the list for the given Book. If the Book is found, the node that
// contains the book is removed and the pointer to it are fixed. Returns true
// if successful, false if unsuccesful or Book is not found.
bool BookList::remove(const Book *theBook)
{
	//Check if list is empty
	if (isEmpty())
		return false;

	ListNode* cur = new ListNode();
	cur = front;
	bool found = false;

	//Iterate through list and look for book
	while (cur != NULL && !found)
	{
		//go to the next book if the book are different types
		if(theBook->getType() != cur->nodeData->getType())
			cur = cur->next;

		//if the books are the same type, move to next node if they arent equal
		else if(*cur->nodeData != theBook)
			cur = cur->next;

		//otherwise you have found the book
		else
			found = true;
	}

	if (cur != NULL) //Book is found and cur points to node, remove cur
	{
		if (front == back)//found node, only one node in list
		{
			//delete node
			front = NULL;
			back = NULL;
			cur->next = NULL;
			delete cur->next;
			cur->prev = NULL;
			delete cur->prev;
			delete cur;
			return true;
		}
		//node to delete is at front and there are more nodes
		else if(cur == front && cur->next != NULL)
		{
			front = cur->next;
			cur->next->prev = NULL;
			cur->next = NULL;
			delete cur->next;
			cur->prev = NULL;
			delete cur->prev;
			delete cur;	
			return true;
		}
		//node to delete is at the back and there are more nodes
		else if (cur == back)
		{
			back = cur->prev;
			cur->prev->next = NULL;
			cur->next = NULL;
			delete cur->next;
			cur->prev = NULL;
			delete cur->prev;
			delete cur;
			return true;
		}
		//node to delete is in the middle of 2 nodes
		else
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur->next = NULL;
			delete cur->next;
			cur->prev = NULL;
			delete cur->prev;
			delete cur;
			return true;
		}
	}
	return false; //This is reached if the Book was not found
}

//------------------------------------------------------------------------------
//insert
// Inserts the given Book into the list along with the command associated with
// the action being peformed on the Book. Example: Checking out Book "A" would
// add a node with Book = "A" and command = "Check out". Duplicate book are 
// allowed to be checked out, but only if there is stock of the book in the 
// Library.
bool BookList::insert(Book* theBook, string commandType)
{
	//create node to store Book
	ListNode *theNode = new ListNode();
	theNode->nodeData = theBook;
	theNode->commandType = commandType;
	theNode->next = NULL;
	theNode->prev = NULL;

	//If the list is empty place Node at front and set front and back pointers
	if (front == NULL && back == NULL)
	{
		front = theNode;
		back = theNode;
		theNode = NULL;
		delete theNode;
		return true;
	}
	//If there are nodes in the list, place node at the end of the list
	else
	{
		back->next = theNode;
		theNode->prev = back;
		back = theNode;
		theNode = NULL;
		delete theNode;
		return true;
	}
	//delete temporary pointer
	theNode = NULL;
	delete theNode;
	return false;
}

//------------------------------------------------------------------------------
//retrieve
// Searches the list for the given Book and assigns pointer to the Book stored
// in the node to tempBook argument if it exists. Stops at the first found 
// instance of the Book in the list. Assigns NULL if Book is not found or if
// list is empty. Returns true if Book is found, false otherwise.
bool BookList::retrieve(const Book *theBook, Book* &tempBook)
{
	//Return NULL if list is empty
	if (isEmpty())
		return false;

	//Create temp node to iterate through list.
	ListNode* cur = new ListNode();
	cur = front;
	
	//iterate through list and look for book
	while (cur != NULL && *cur->nodeData != theBook)
	{
		cur = cur->next;
	}
	if (cur != NULL) // found the book, return the book
	{
		tempBook = cur->nodeData;
		cur = NULL;
		delete cur;
		return true;
	}

	//end of list, book was not found delete pointers
	tempBook = NULL;
	cur = NULL;
	delete cur;
	return false;
}

//------------------------------------------------------------------------------
//find
// Searches the list for the given Book and returns true if Book was found,
// false otherwise.
bool BookList::find(const Book* theBook) const
{
	//List is empty, return false
	if (isEmpty())
		return false;

	//Create node to iterate through list
	ListNode* cur = front; 
	bool found = false;

	//look for book in list
	while(!found && cur != NULL)
	{
		//if books are different types, go to next node
		if (cur->nodeData->getType() != theBook->getType())
			cur = cur->next;
		//if books are not equal, go to next node
		else if (*cur->nodeData != theBook)
			cur = cur->next;
		//otherwise book was found.
		else
			found = true;
	}
	if (cur == NULL)//book was not found, return false
	{
		delete cur;
		return false;
	}

	//book was found, return true
	cur = NULL;
	delete cur;
	return true;
}

//------------------------------------------------------------------------------
//displayHistory
// Iterates through list and prints out the Book stored at each node along with
// the command associated with that Book. Goes from front to back.
void BookList::displayHistory() const
{
	//List is empty, output nothing.
	if (isEmpty())
	{
		cout << endl;
		return;
	}

	//Create node to iterate through list
	ListNode* cur = front;
	while (cur != NULL) //print every node
	{
		cout.setf(ios::left, ios::adjustfield);
		cout << setw(10) << cur->commandType;
		cur->nodeData->displayBookInfo();
		
		//go to the next node
		cur = cur->next;
	}
	cout << endl;
	cur = NULL;
	delete cur;
}

//------------------------------------------------------------------------------
//displayBackwards
// Iterates through list and prints out the Book stored at each node along with
// the command associated with that Book. Goes from back to front.
void BookList::displayBackwards() const
{
	if (isEmpty())
		return;
	ListNode* cur = new ListNode();
	cur = back;
	while (cur != NULL) //print every node
	{
		cout.setf(ios::left, ios::adjustfield);
		cout << setw(10) << cur->commandType;
		cur->nodeData->displayBookInfo();
		
		//go to the next node
		cur = cur->prev;
	}
	cout << endl;
}
