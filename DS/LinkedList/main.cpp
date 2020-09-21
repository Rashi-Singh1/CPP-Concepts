#include <iostream>
using namespace std;
#include "LinkedList.h"

/*
For reference :
	int val;
	LinkedList * next;
	LinkedList(int val)
	{
		this->val = val;
		this->next = NULL;
	}
	~LinkedList();
	LinkedList* addAtEnd(LinkedList * head, int val);
	LinkedList* addAtStart(LinkedList * head, int val);
	void clear(LinkedList * head);
	void printList(LinkedList * head);
	LinkedList* find(LinkedList * head, int val);

*/

int main(int argc, char const *argv[])
{
	LinkedList list;
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