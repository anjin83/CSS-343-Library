//---------------------------booktree.h file------------------------------------
// Abstract data type BookTree
// Binary search tree data structure that stores the books.
// Each book type is stored in its own tree
#ifndef BOOKTREE_H
#define BOOKTREE_H
#include "book.h"
#include "fbook.h"
#include "pbook.h"
#include "ybook.h"
//------------------------------------------------------------------------------
//Abstract data type BookTree: BookTree is a binary search tree that is used to 
//        stores the Book objects that are added to the library. The BookTrees
//        are used and stored in the BookLibrary class in the bookDB array. Each
//        specialized type of Book object is stored in it's own tree.
//
//Implementation and Assumptions
//    --All methods assume that the Book object being handed to them is valid.
//    Object validation is performed before the Book is handed to the BookTree
//    class.
//    --Book are sorted by their sorting criteria. Sorting criteria is returned
//    by the Book's sortingCriteria method and then stored in tree accordingly.
//    --printSortedBooks performs an in-order traversal of the tree and outputs
//    each node's Book object. The output will be in order of the Book's sorting
//    criteria. It uses the sortHelper method to perform recursive work.
//    --find(Book*) takes a Book object and searches the tree to see if the 
//    Book is stored there. It returns true if found, false otherwise.
//    --find(Book*, Book* &) takes a Book object and searches the tree to see
//    if the Book is stored there. If found it sets the location to the other
//    Book* argument that is passed by reference.
//    --deleteTree() removes every node from the tree. It uses the make 
//    makeEmpty helper method to perform the recursive work.
//    
//------------------------------------------------------------------------------
class BookTree {

public:
	BookTree();  //default constructor
	~BookTree();  //default destructor
	bool isEmpty() const; //returns if tree is empty
	bool insert(Book*);  //insert the given book into the tree
	bool remove(Book*);  //remove the given book from the tree, deletes node
	bool find(Book*) const; //finds a book, true if found, false otherwise
	
	//finds a book and sets second argument pointer as location
	//returns true if found,false otherwise
	bool find(Book*, Book*&) const;
	//looks for given book in tree and returns pointer to book if found
	//returns NULL otherwise
	bool retrieve(Book*, Book* &) const; 
	//prints the contents of the tree in sorted order
	void printSortedBooks() const;  
	void deleteTree();  //Deletes all nodes in the tree


private:
	//Node for tree
	struct BookNode 
	{
		Book* bookNodeData;  //pointer to book stored in node
		BookNode* left;  //pointer to left child
		BookNode* right;  //pointer to right child
	};
	BookNode* root;  //root of the tree
	void sortHelper(BookNode*) const;// performs recursion for sort method
	void makeEmpty(BookNode*); //used by destructor to delete all nodes in tree

};
#endif