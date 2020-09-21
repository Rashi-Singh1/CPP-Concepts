#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;
	node* prev;
	node(int val)
	{
		this->val = val;
		this->prev = NULL;
		this->next = NULL;
	}
};

class DoubleLinkedList
{
private:
	node* head;
	node* tail;
public:
	DoubleLinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	void addAtEnd(int val);
	void addAtStart(int val);
	void clear();
	void printList();
	node* find(int val);
	node* getHead();
	node* getTail();
};


void DoubleLinkedList::addAtEnd(int val)
{
	node* Node = new node(val);
	if(!(this->head)) {
		this->head = Node;
		this->tail = Node;
	}
	else{
		Node->prev = this->tail;
		this->tail->next = Node;
		this->tail = Node;
	}
}

void DoubleLinkedList::addAtStart(int val)
{
	node * Node = new node(val);
	if(this->head) this->head->prev = Node;
	Node->next = this->head;
	this->head = Node;
}

void DoubleLinkedList::clear()
{
	if(!(this->head)) return;
	node * trash = this->head->next;
	node * blah = this->head->next;
	while(blah!= this->tail)
	{
		trash = blah;
		blah = blah->next;
		trash->next = NULL;
		delete(trash);
	}
	if(this->head) {
		this->head->next = NULL;
		this->head = NULL;
	}
	if(this->tail) {
		this->tail->next = NULL;
		this->tail = NULL;
	}
}

void DoubleLinkedList::printList()
{
	if(!(this->head)) return;
	else{
		node* temp = this->head;
		while(temp->next)
		{
			cout<<temp->val<<" <-> ";
			temp = temp->next;
		}
		cout<<temp->val<<endl;
	}
}

node* DoubleLinkedList::find(int val)
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


node* DoubleLinkedList::getHead()
{
	return this->head;
}

node* DoubleLinkedList::getTail()
{
	return this->tail;
}

int main(int argc, char const *argv[])
{
	DoubleLinkedList list;
	for (int i = 0; i <= 15; ++i)
	{
		list.addAtStart(2*i);
		list.printList();
	}
	list.clear();
	list.printList();
	for (int i = 0; i <= 15; ++i)
	{
		list.addAtEnd(2*i);
		list.printList();
	}
	if(list.find(26)) cout<<list.find(26)->val<<endl;
	// if(blah) cout<<"Found : "<<blah->val<<" vs "<<"26"<<endl;
	else cout<<"Not Found";
	return 0;
}