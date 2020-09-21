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

class queue
{
private:
	node* back;
	node* front;
	int size;
public:
	queue(){
		this->back = NULL;
		this->size = 0;
		this->front = NULL;
	}
	int getBack();
	int getFront();
	int getSize();
	bool isEmpty();
	void push(int val);
	void pop();
	void print();
	void clear();
};

int queue::getBack()
{
	if(this->size > 0) return this->back->val;
	else return -1;
}

int queue::getFront()
{
	if(this->size > 0) return this->front->val;
	else return -1;
}

int queue::getSize()
{
	return this->size;
}

bool queue::isEmpty()
{
	if(this->size > 0) return false;
	else return true;
}

void queue::push(int val)
{
	node* Node = new node(val);
	if(this->back == NULL) {
		this->back = Node;
		this->front = Node;
	}
	else{
		Node->next = this->front;
		this->front = Node;
	}
	(this->size)++;
}

void queue::pop()
{
	if(!queue::isEmpty()){
		node* temp = this->front;
		if(temp == this->back)
		{
			this->back = NULL;
			this->front = NULL;
		}
		else
		{
			while(temp->next!=this->back) temp = temp->next;
			delete(this->back);
			this->back = temp;
			this->back->next = NULL;
		}
		(this->size)--;
	}
}

void queue::print()
{
	cout<<endl<<"size : "<<this->size<<endl;
	node* temp = this->front;
	if(!temp) return;
	else{
		while(temp)
		{
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<"   <- Front"<<endl;
	}
}

void queue::clear()
{
	if(!(this->front)) return;
	node * trash = this->front->next;
	node * blah = this->front->next;
	while(blah != this->back)
	{
		trash = blah;
		blah = blah->next;
		trash->next = NULL;
		delete(trash);
	}
	if(this->front) {
		this->front->next = NULL;
		this->front = NULL;
	}
	if(this->back) {
		this->back->next = NULL;
		this->back = NULL;
	}
	this->size = 0;
}