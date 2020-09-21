#include <iostream>
using namespace std;

struct node
{
	int val;
	node * next;
	node(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};

class LinkedList
{
private:
	node * head;
public:
	LinkedList()
	{
		this->head = NULL;
	}
	void addAtEnd(int val);
	void addAtStart(int val);
	void clear();
	void printList();
	node* find(int val);
	node* getHead();
};

void LinkedList::addAtEnd(int val)
{
	node* Node = new node(val);
	if(!(this->head)) this->head = Node;
	else{
		node * start = this->head;
		while(start->next)
		{
			start = start->next;
		}
		start->next = Node;
	}
}

void LinkedList::addAtStart(int val)
{
	node * Node = new node(val);
	Node->next = this->head;
	this->head = Node;
}

void LinkedList::clear()
{
	if(!(this->head)) return;
	node * trash = this->head->next;
	node * blah = this->head->next;
	while(blah)
	{
		trash = blah;
		blah = blah->next;
		trash->next = NULL;
		delete(trash);
	}
	if(blah) {
		blah->next = NULL;
		delete(blah);
	}
	if(this->head) {
		this->head->next = NULL;
		this->head = NULL;
	}
}

void LinkedList::printList()
{
	if(!(this->head)) return;
	else{
		node* temp = this->head;
		while(temp->next)
		{
			cout<<temp->val<<" -> ";
			temp = temp->next;
		}
		cout<<temp->val<<endl;
	}
}

node* LinkedList::find(int val)
{
	if(!this->head) return NULL;
	node * temp = this->head;
	while(temp)
	{
		if(temp->val == val) return temp;
		temp = temp->next;
	}
	return NULL;
}


node* LinkedList::getHead()
{
	return this->head;
}