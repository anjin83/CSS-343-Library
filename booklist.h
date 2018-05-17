//--------------------------booklist.h file-------------------------------------
// Abstract data type BookList
// Data structure that stores Book*'s in a doubly linked list. List is used for
// User's history.
#ifndef BOOKLIST_H
#define BOOKLIST_H

#include"book.h"
//------------------------------------------------------------------------------
//Abstract data type BookList: BookList is a doubly linked list that is used by
//        the User class to store information on it's history and it's currently
//        checked out Books. Each node in the list stores a pointer to a Book
//        object as well as a string that contains the command that was 
//        performed on that Book when it was inserted into the list.
//
//Implementation and Assumptions:
//    --All methods assume that they are being passed a valid Book object to 
//    insert into the list. Object validation is performed before these Book's
//    are passed to the methods they are used in.
//    --retrieve function is passed a Book to search for and a pointer that
//    will be used to store the location to the book if found in the list.
//    The pointer will be set to NULL if the book is not found or the database
//    is empty.
//------------------------------------------------------------------------------
class BookList 
{
	//Node for list. Stores a Book* and a command string that records the users
	//actions with the book in the list for the User's history.
	struct ListNode
	{
		Book* nodeData; //Book being added to history
		//used when printing out user history, action taken with book
		string commandType; 
		ListNode* next;  //pointer to next node
		ListNode* prev;  //pointer to previous node
	};

public:
	BookList();  //Default constructor
	~BookList();  //Default destructor

	Book* getFront() const;  //Returns the Book* stored in the first node
	Book* getBack() const;  //Returns the Book* stored in the last node
	bool isEmpty() const;  //Returns true if list is empty, false otherwise
	void makeEmpty();  //Deletes every node in the list
	bool remove(const Book*);  //Searchs list for given book and removes node
	bool insert(Book*, string);  //Inserts book into the list

	//Searches list for a given book, assigns pointer to tempBook
	//argument if it is found. NULL pointer is assigned otherwise
	//returns true if books is found, false otherwise.
	bool retrieve(const Book*, Book* &);  

	//Searches list for given book, returns true if found otherwise false
	bool find(const Book*) const;
	
	//Displays all books in list and commands associated starting from front
	void displayHistory() const;

	//Displays all books in list and commands associated starting from back
	void displayBackwards() const;

private:
	ListNode* front; //pointer to front of list
	ListNode* back; //pointer to back of list

};
#endif