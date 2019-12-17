#include "node.h"

void Node::addAttribute(string name, string value) {
	Attribute* atb = new Attribute;

	atb->name = name;
	atb->value = value;
	attributes.push_back(atb);
}
void Node::addChild(Node* newChild) {
	child.push_back(newChild);
	newChild->parent = this;
}

string Node::getName() {
	return name;
}
string Node::getContent() {
	return content;
}

Node::Attribute* Node::getAttribute(int i) {
	list <Attribute*> ::iterator it = attributes.begin();

	advance(it, i);
	return *it;
}

Node* Node::getParent() {
	return parent;
}

Node* Node::getChild(int i) {
	list <Node*> ::iterator it = child.begin();

	advance(it, i);
	return *it;
}

void Node::displayAttributes() {
	list<Attribute*> ::iterator it;

	for (it = attributes.begin(); it != attributes.end(); it++) {
		cout << " " << (*it)->name << "='" << (*it)->value << "'";
	}
}

void Node::printAttributes(ofstream& f) {
	list<Attribute*> ::iterator it;

	for (it = attributes.begin(); it != attributes.end(); it++) {
		f << " " << (*it)->name << "='" << (*it)->value << "'";
	}
}

bool Node::hasAttribute(string name, string value) {
	bool flag = 0;
	list<Attribute*> ::iterator it;

	if (attributes.size() > 0) {
		for (it = attributes.begin(); it != attributes.end(); it++) {
			if ((*it)->name == name && (*it)->value == value) {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

Node* Node::findNode(string name) {
	Node* x = NULL;

	if (this->name == name) {
		return this;
	}
	else {
		list <Node*> ::iterator it;
		for (it = child.begin(); it != child.end(); it++) {
			x = (*it)->findNode(name);
			if (x != NULL)
				return x;
		}
	}
	return NULL;
}

Node* Node::findNode(string name, string content) {
	Node* x = NULL;

	if (this->name == name && this->content == content) {
		return this;
	}
	else {
		list <Node*> ::iterator it;
		for (it = child.begin(); it != child.end(); it++) {
			x = (*it)->findNode(name, content);
			if (x != NULL)
				return x;
		}
	}
	return NULL;
}

Node* Node::findNode(string name, string attribute, string value) {
	Node* x = NULL;

	if (this->name == name && hasAttribute(attribute, value) ) {
		return this;
	}
	else {
		list <Node*> ::iterator it;
		for (it = child.begin(); it != child.end(); it++) {
			x = (*it)->findNode(name, attribute, value);
			if (x != NULL)
				return x;
		}
	}

	return NULL;
}



void Node::displayChildren(int spaces) {
	int i = spaces;
	list <Node*> ::iterator it;

	while (i) {
		cout << " ";
		i--;
	}
	cout << "<" << name;
	displayAttributes();
	cout << ">";
	
	for (it = child.begin(); it != child.end(); it++) {
		cout << endl;
		(*it)->displayChildren(spaces + 2);
	}
	
	if (content != "") {
		if (child.size() > 0) {
			cout << '\n';
			i = spaces;
			while (i) {
				cout << " ";
				i--;
			}
		}
		cout << content;
	}
	else {
		cout << endl;
		i = spaces;
		while (i) {
			cout << " ";
			i--;
		}
	}
	cout << "</" << name << ">";
}

void Node::printChildren(ofstream& f,int spaces) {
	int i = spaces;
	list <Node*> ::iterator it;

	while (i) {
		f << " ";
		i--;
	}
	f << "<" << name;
	printAttributes(f);
	f << ">";

	for (it = child.begin(); it != child.end(); it++) {
		f << endl;
		(*it)->printChildren(f, spaces + 2);
	}
	if (content != "")
		f << content;
	else {
		f << endl;
		i = spaces;
		while (i) {
			f << " ";
			i--;
		}
	}
	f << "</" << name << ">";
}

void Node::deleteAttributes() {
	if (attributes.size() > 0) {
		list<Attribute*> ::iterator it;
		for (it = attributes.begin(); it != attributes.end(); it++) {
			delete* it;
		}
		attributes.clear();
		// Remove the comment on the line below to check for deleted items
		//cout << "\ndeleted attributes for " << this->name << endl;
	}
}

void Node::deleteNode() {
	
	deleteAttributes();

	if (child.size() > 0) {
		list<Node*> ::iterator it = child.begin(), a;
		for (it = child.begin(); it != child.end(); it++) {
			(*it)->deleteAttributes();
			(*it)->deleteNode();	
		}
	}
	// Remove the comment on the line below to check for deleted items
	//cout << "\ndeleted node " << this->name << endl;
	delete this;
}

void Node::removeChild(Node* child) {
	list<Node*> ::iterator it;
	for (it = this->child.begin(); it != this->child.end(); it++) {
		if ((*it) == child) {
			this->child.erase(it);
			break;
		}
	}
}

void Node::removeAttribute(string name, string value) {
	list<Attribute*> ::iterator it;
	for (it = attributes.begin(); it != attributes.end(); it++) {
		if ( (*it)->name == name &&  (*it)->value == value) {
			delete* it;
			attributes.erase(it);
			break;
		}
	}
}

void Node::displayNode() {
	cout << name << " ";
	if (content != "") {
		cout << "with the content: " << content<<"and";
	}
	cout << "with the attributes: ";
	displayAttributes();
}

