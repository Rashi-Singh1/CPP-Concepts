#include <iostream>
using namespace std;

//O(n) pop, clear and print, rest are O(1)
struct node
{
	int val;
	node* next;
	node(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};

class stack
{
private:
	node* top;
	node* tail;
	int size;
public:
	stack(){
		this->top = NULL;
		this->size = 0;
		this->tail = NULL;
	}
	int getTop();
	int getSize();
	bool isEmpty();
	void push(int val);
	void pop();
	void print();
	void clear();
};

int stack::getTop()
{
	if(this->size > 0) return this->top->val;
	else return -1;
}

int stack::getSize()
{
	return this->size;
}

bool stack::isEmpty()
{
	if(this->size > 0) return false;
	else return true;
}

void stack::push(int val)
{
	node* Node = new node(val);
	if(this->top == NULL) {
		this->top = Node;
		this->tail = Node;
	}
	else{
		this->top->next = Node;
		this->top = Node;
	}
	(this->size)++;
}

void stack::pop()
{
	if(!stack::isEmpty()){
		node* temp = this->tail;
		if(temp == this->top)
		{
			this->top = NULL;
			this->tail = NULL;
		}
		else
		{
			while(temp->next!=this->top) temp = temp->next;
			delete(this->top);
			this->top = temp;
			this->top->next = NULL;
		}
		(this->size)--;
	}
}

void stack::print()
{
	cout<<endl<<"size : "<<this->size<<endl;
	node* temp = this->tail;
	if(!temp) return;
	else{
		while(temp)
		{
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<"   <- top"<<endl;
	}
}

void stack::clear()
{
	if(!(this->tail)) return;
	node * trash = this->tail->next;
	node * blah = this->tail->next;
	while(blah != this->top)
	{
		trash = blah;
		blah = blah->next;
		trash->next = NULL;
		delete(trash);
	}
	if(this->tail) {
		this->tail->next = NULL;
		this->tail = NULL;
	}
	if(this->top) {
		this->top->next = NULL;
		this->top = NULL;
	}
	this->size = 0;
}