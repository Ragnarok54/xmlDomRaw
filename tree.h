#pragma once
#include "node.h"

class Tree {
private:
	list<Node*> elements;

public:
	//Tree();
	// Adds an Element to the root of the DOM
	void addElement(Node* newNode);
	// Prints tree to the console
	void displayTree();
	// Outputs the tree to the file
	void printTree(ofstream& f);
	// Returns the first node with
	// coressponding name
	Node* findElement(string name);
	// Returns a pointer to the node with 
	// corresponding name and content
	Node* findElement(string name, string content);
	// Returns a pointer to the node with 
	// corresponding name and attribute
	Node* findElement(string name, string attribute, string value);
	// Deletes an element node from the tree
	void deleteElement(Node* node);
	// Deletes the first node with the
	// corresponding name
	void deleteElement(string name);
	// Deletes the node with the
	// corresponding name and content
	void deleteElement(string name, string content);
	// Deletes the node with the
	// corresponding name and attribute
	void deleteElement(string name, string attribute, string value);
	// Moves any node with its child nodes
	// as a child to the destination node
	void moveElement(Node* source, Node* destination);
	// Destructor for every node inside the tree
	~Tree();
};
