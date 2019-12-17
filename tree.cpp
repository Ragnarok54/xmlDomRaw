#include "Tree.h"


void  Tree::addElement(Node* newNode) {
	elements.push_back(newNode);
}

void  Tree::displayTree() {
	list <Node*> ::iterator it;
	int i = 0;

	cout << "<?xml version = '1.0' encoding='UTF-8 standalone='yes'?>\n";
	cout << "<RootElement>\n";
	for (it = elements.begin(); it != elements.end(); it++) {
		(*it)->displayChildren(2);
		cout << endl;
	}
	cout << "</RootElement>\n\n";
}

void  Tree::printTree(ofstream& f) {
	list <Node*> ::iterator it;
	int i = 0;

	cout << "<?xml version = '1.0' encoding='UTF-8 standalone='yes'?>\n";
	f << "<RootElement>\n";
	for (it = elements.begin(); it != elements.end(); it++) {
		(*it)->printChildren(f, 2);
		f << endl;
	}
	f << "</RootElement>\n\n";
}

Node* Tree::findElement(string name) {
	Node* x = NULL;

	list <Node*> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		x = (*it)->findNode(name);
		if (x != NULL)
			return x;
	}
	return NULL;
}

void Tree::deleteElement(Node* node) {
	if(node->getParent() != NULL)
		node->getParent()->removeChild(node);
	node->deleteNode();
}

void Tree::deleteElement(string name) {
	Node* x = NULL;

	x = findElement(name);

	if (x == NULL) {
		cout << "Element not found\n";
	}
	else {
		list <Node*> ::iterator it;
		for (it = elements.begin(); it != elements.end(); it++) {
			if ((*it)->getName() == name) {
				elements.erase(it);
				break;
			}
		}
		if (x->getParent() != NULL) {
			x->getParent()->removeChild(x);
		}
		x->deleteNode();
	}
}

void Tree::deleteElement(string name, string content) {
	Node* x = NULL;

	x = findElement(name, content);

	if (x == NULL) {
		cout << "Element not found\n";
	}
	else {
		list <Node*> ::iterator it;
		for (it = elements.begin(); it != elements.end(); it++) {
			if ((*it)->getName() == name && (*it)->getContent() == content) {
				elements.erase(it);
				break;
			}
		}
		if (x->getParent() != NULL) {
			x->getParent()->removeChild(x);
		}
		x->deleteNode();
	}
}

void Tree::deleteElement(string name, string attribute, string value) {
	Node* x = NULL;

	x = findElement(name, attribute, value);

	if (x == NULL) {
		cout << "Element not found\n";
	}
	else {
		list <Node*> ::iterator it;
		for (it = elements.begin(); it != elements.end(); it++) {
			if ((*it)->getName() == name && (*it)->hasAttribute(attribute, value)) {
				elements.erase(it);
				break;
			}
		}
		if (x->getParent() != NULL) {
			x->getParent()->removeChild(x);
		}
		x->deleteNode();
	}
}

void Tree::moveElement(Node* source, Node* destination) {

	source->getParent()->removeChild(source);
	destination->addChild(source);
}

Node* Tree::findElement(string name, string atribute, string value) {
	Node* x = NULL;

	list <Node*> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		x = (*it)->findNode(name, atribute, value);
		if (x != NULL)
			return x;
	}
	return NULL;
}

Node* Tree::findElement(string name, string content) {
	Node* x = NULL;

	list <Node*> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		x = (*it)->findNode(name, content);
		if (x != NULL)
			return x;
	}
	return NULL;
}

Tree::~Tree() {
	list<Node*> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		(*it)->deleteNode();
	}
}