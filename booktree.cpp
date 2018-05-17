//-------------------------------booktree.cpp file------------------------------
// Member function defintions for Abstract data type BookTree
// Binary search tree that stores pointers to Book Objects.
// Used in BookLibrary class to store the books in the library's database
#include "booktree.h"
#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

//------------------------------------------------------------------------------
//Default constructor
// Initializes the root to NULL
BookTree::BookTree()
{
	root = NULL;
}

//------------------------------------------------------------------------------
//Default destructor
// Deletes all of the nodes in the tree along with all of the pointers.
BookTree::~BookTree()
{
	//go to every node and delete the node
	deleteTree();
}

//------------------------------------------------------------------------------
//isEmpty
// Checks to see if there is anything in the tree. Returns true if tree is empty
bool BookTree::isEmpty() const
{
	return (root == NULL ? true : false);
}

//------------------------------------------------------------------------------
//insert
// Inserts a Book into the tree. Stores Book in a BookNode object, which 
// containts a pointer to the book and pointers to its left and right children.
// Book are sorted by their sorting criteria, which is unique to each book type.
// Sorting is performed alphabetically. Books that come before the Book being 
// compared are stored in the left sub-tree and Books that come after in the 
// right sub-tree. Duplicate Books are discarded. Returns true if succesful, 
// false otherwise.
bool BookTree::insert(Book* theBook)
{
	//Create node to store Book object
	BookNode *node = new BookNode();
	node->bookNodeData = theBook;
	node->left = NULL;
	node->right = NULL;
	
	//Delete pointers
	theBook = NULL;
	delete theBook;

	//Insert Book at root if tree is empty
	if (isEmpty())
	{
		root = node;
		return true;
	}

	bool assigned = false;
	BookNode* cur = root;

	//Traverse the tree until you can insert the node
	while (!assigned) 
	{
		//new node is less than cur, go left
		if (node->bookNodeData->sortingCriteria() 
			< cur->bookNodeData->sortingCriteria()) 
		{
			if (cur->left == NULL) //at a leaf, insert new node
			{
				cur->left = node;
				assigned = true;
			}
			else
				cur = cur->left;
		}

		// new node is greater than cur, go right
		else if (node->bookNodeData->sortingCriteria() 
			> cur->bookNodeData->sortingCriteria()) 
		{
			if (cur->right == NULL) //at a leaf, insert new node
			{
				cur->right = node;
				assigned = true;
			}
			else
				cur = cur->right;
		}

		//node is duplicate, delete new node
		else
		{
			cur = NULL;
			delete node->bookNodeData;
			delete node->left;
			delete node->right;
			delete cur;
			delete node;
			return false;
		}
	}
	//delete temp pointers
	cur = NULL;
	delete cur;
	return true;
	
}

//*****************************************************************************
//------------------------------------------------------------------------------
//remove
// Searches tree for given Book and removes the node that stores the book if 
// found and rearranges pointers in tree. Returns true if Book was found and 
// removed, false otherwise
bool BookTree::remove(Book* theBook)
{
	//Create temporary pointer to traverse tree
	BookNode *cur = root;
	bool found = false;

	while (!found)
	{
		if (*cur->bookNodeData == theBook)
			found = true;

		//theBook is less than current node, go left
		else if (theBook->sortingCriteria() 
			< cur->bookNodeData->sortingCriteria()) 
		{
			if (cur->left != NULL)
				cur = cur->left;
			else
				break;
		}
		else //theBook is greater than current node, go right
		{
			if (cur->right != NULL)
				cur = cur->right;
			else
				break;
		}
	}
	//IMPLEMENT
	return false;
	//delete the node if found, set cur = null
}

//------------------------------------------------------------------------------
//find: One argument
// Searches tree for given Book and returns true if found, false otherwise
bool BookTree::find(Book* theBook) const
{
	//Create temporary pointer to traverse tree
	BookNode *cur = root;
	bool found = false;

	//Search for Book
	while (!found)
	{
		//Book found, return true
		if (*cur->bookNodeData == theBook)
			found = true;

		//theBook is less than current node, go left
		else if (theBook->sortingCriteria() 
			< cur->bookNodeData->sortingCriteria()) 
		{
			if (cur->left != NULL)
				cur = cur->left;
			else
				break;
		}
		else //theBook is greater than current node, go right
		{
			if (cur->right != NULL)
				cur = cur->right;
			else
				break;
		}
	}
	
	//Delete temporary pointers
	cur = NULL;
	delete cur;
	return found;
}

//------------------------------------------------------------------------------
//find: Two arguments
// Searches tree for book and sets the location of the book to location argument
// if Book is found. location is set to NULL if Book is not found or tree is 
// empty. Return true if found, false otherwise. Helper function for retrieve
bool BookTree::find(Book* theBook, Book*&location) const
{
	//Create temporary pointer to traverse tree
	BookNode *cur = root;
	bool found = false;

	//Search the tree for Book
	while (!found)
	{
		if (*cur->bookNodeData == theBook)
		{
			found = true;
			location = cur->bookNodeData;
			cur = NULL;
			delete cur;
		}
		//theBook is less than current node, go left if possible
		else if (theBook->sortingCriteria() 
			< cur->bookNodeData->sortingCriteria()) 
		{
			if (cur->left != NULL)
				cur = cur->left;
			//at a leaf, break out of loop
			else
				break;
		}
		else //theBook is greater than current node, go right if possible
		{
			if (cur->right != NULL)
				cur = cur->right;
			//at a leaf, break out of loop
			else
				break;
		}
	}

	//Book not found, delete temp pointers
	cur = NULL;
	delete cur;
	return found;
}

//------------------------------------------------------------------------------
//retrieve
// Search tree for book and sets location in tempBook if found. tempBook set to
// NULL if tree is empty or Book is not found. Uses find method for recursion.
bool BookTree::retrieve(Book* target, Book* &tempBook) const
{
	//Book is found, store location in tempBook and return true
	if (find(target, tempBook))
		return true;
	//Book not found, set tempBook to NULL and return false
	else
	{
		tempBook = NULL;
		return false;
	}
}

//******************************************************************************
//------------------------------------------------------------------------------
//printSortedBooks
// Prints out the contents of the books stored in the tree in sorted order. Uses
// sortHelper method to perform recursion
void BookTree::printSortedBooks() const
{
	//Print custom header for Book type
	char type = root->bookNodeData->getType();
	switch (type)
	{
	case('F'):
		cout.setf(ios::left, ios::adjustfield);
		cout << "Fiction:" << endl;
		cout << setw(6) << "AVAIL" 
			<< setw(22) << "AUTHOR" 
			<< setw(40) << "TITLE" 
			<< setw(5) << "YEAR" 
			<< endl;
		break;
	case('P'):
		cout.setf(ios::left, ios::adjustfield);
		cout << endl;
		cout << "Periodicals:" << endl;                                  
		cout << setw(6) << "AVAIL" 
			<< setw(5) << "YEAR" 
			<< setw(3) << "MO" 
			<< setw(40) << "TITLE" 
			<< endl;
		break;
	case('Y'):
		cout.setf(ios::left, ios::adjustfield);
		cout << endl;
		cout << "Youth:" << endl;
		cout << setw(6) << "AVAIL" 
			<< setw(40) << "TITLE" 
			<< setw(22) << "AUTHOR" 
			<< setw(5) << "YEAR" 
			<< endl;
		break;
	default:
		break;
	}

	//Tree is not empty, print the contents of the tree
	if (!isEmpty())
	{		
		sortHelper(root);
	}
}

//------------------------------------------------------------------------------
//sortHelper
// Prints out the contents of the books stored in the tree in sorted order.
// Performs recursion for printSortedBooks method. In order traversal or tree.
void BookTree::sortHelper(BookNode* theNode) const
{
	//left
	if (theNode->left != NULL)
		sortHelper(theNode->left);
	//parent
	theNode->bookNodeData->displayBook();
	//right
	if (theNode->right != NULL)
		sortHelper(theNode->right);
}

//------------------------------------------------------------------------------
//deleteTree
// Deletes every node in the tree. Uses makeEmpty method for recursion.
void BookTree::deleteTree()
{
	if (!isEmpty())
		makeEmpty(root);
	delete root;
	
}

//------------------------------------------------------------------------------
//makeEmpty
// Does a breadth -first traversal of the tree and deletes all of the nodes and
// the pointers stored in the nodes. Performs recursive work for deleteTree
void BookTree::makeEmpty(BookNode* theNode)
{
	//left
	if (theNode->left != NULL)
		makeEmpty(theNode->left);
	//right
	if (theNode->right != NULL)
		makeEmpty(theNode->right);
	//parent
	//Delete the contents of the node
	delete theNode->bookNodeData;
	delete theNode->left;
	delete theNode->right;
	
}