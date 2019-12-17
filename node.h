#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

class Node {
	// Struct used to store an attribute and its value
	struct Attribute {
		string name;
		string value;
	};

private:
	string name;
	string content;
	Node* parent;
	list<Attribute*> attributes;
	list<Node*> child;
	friend class Tree;

protected:
	// Do not use this function unless used from Tree class
	void deleteNode();
	// Recursive function to display a node and
	// the child nodes linked to it to the console
	void displayChildren(int spaces);
	// Recursive function to display a node and
	// the child nodes linked to it to the file
	void printChildren(ofstream& f, int spaces);

public:
	// Constructor for the class
	Node(string name, string content = "") : name(name), content(content), parent(NULL) {};
	// Adds an attribute to the node it's called from
	void addAttribute(string name, string value);
	// Links the given node as child of the node it's called from
	void addChild(Node* newChild);
	// Returns the name of the node
	string getName();
	// Returns the content of the node
	string getContent();
	// Returns true if the node has the given attribute
	bool hasAttribute(string name, string value);
	// Returns a pointer to the i-th attribute
	Attribute* getAttribute(int i);
	// Returns a pointer to the parent of the node it's called from
	Node* getParent();
	// Returns the i-th child of the node it's called from
	Node* getChild(int i);
	// Returns a pointer to the first node with given name
	Node* findNode(string name);
	// Returns a pointer to the node 
	// with the given name and content
	Node* findNode(string name, string content);
	// Returns a pointer to the node 
	// with the given name and attribute
	Node* findNode(string name, string atribute, string value);
	// Outputs the attributes of the given node to the console
	void displayAttributes();
	// Outputs the attributes of the given node to the file
	void printAttributes(ofstream& f);
	// Used to display a node and it's 
	// attributes to the console
	void displayNode();
	// Removes a given attribute from it's node
	void removeAttribute(string name, string value);
	// Removes all the attributes from a node
	// Also frees the memory for the attributes
	void deleteAttributes();
	/* Removes the node "child" from the list of
	   children of the parent. 
	   Does not free the memory!
	*/
	void removeChild(Node* child);
	~Node() {};
};