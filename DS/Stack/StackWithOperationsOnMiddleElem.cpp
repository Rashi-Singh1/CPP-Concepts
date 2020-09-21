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

class SpecialStack
{
private:
	node* head;
	node* tail;
	node* mid;
	int size;
public:
	SpecialStack()
	{
		this->head = NULL;
		this->tail = NULL;
		this->mid = NULL;
		this->size = 0;
	}
	void push(int val); //O(1)
	void pop();			//O(1)
	int top();			//O(1)
	void printList();	//O(n)
	void deleteMid();	//O(1)
	node* getMid();		//O(1)
};


void SpecialStack::push(int val)
{
	node* Node = new node(val);
	if(!(this->head)) {
		this->head = Node;
		this->tail = Node;
		this->mid = Node;
		(this->size)++;
	}
	else{
		if( (this->size) % 2 == 0) this->mid = this->mid->next;
		Node->prev = this->tail;
		this->tail->next = Node;
		this->tail = Node;
		(this->size)++;
	}
}

void SpecialStack::pop()
{
	if(this->head)
	{
		if(this->tail->prev == NULL) {
			this->tail = NULL;
			this->head = NULL;
			this->mid = NULL;
		}
		else{
			if( (this->size) % 2 == 1) this->mid = this->mid->prev;
			this->tail->prev->next = NULL;
			node* trash = this->tail;
			this->tail = this->tail->prev;
			trash->prev = NULL;
			delete(trash);
		}
		(this->size)--;
	}
}

int SpecialStack::top()
{
	if(this->size > 0) return this->tail->val;
}

void SpecialStack::printList()
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
		cout<<"Mid value is : "<<this->mid->val<<" size : "<<this->size<<endl<<endl;
	}
}

void SpecialStack::deleteMid()
{
	if(this->mid == NULL) return;
	if(this->size == 1) this->pop();
	else{
		node* temp = this->mid;
		if(this->size % 2 == 0) this->mid = this->mid->next;
		else this->mid = this->mid->prev;
		if(temp->prev) temp->prev->next = temp->next;
		if(temp->next) temp->next->prev = temp->prev;
		temp->next = NULL;
		temp->prev = NULL;
		delete(temp);
	}
	(this->size)--;
}

node* SpecialStack::getMid()
{
	return this->mid;
}

int main(int argc, char const *argv[])
{
	SpecialStack sta;
	for (int i = 0; i < 16; ++i)
	{
		sta.push(i*2);
		sta.printList();
	}
	sta.pop();
	sta.printList();
	sta.pop();
	sta.printList();
	cout<<"testing getMid "; if(sta.getMid()) cout<<sta.getMid()->val<<endl;
	sta.deleteMid();
	sta.printList();
	sta.deleteMid();
	sta.printList();
	return 0;
}