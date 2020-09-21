#include <iostream>
using namespace std;
#include "Stack_LinkedListWay.h"

/*
For reference :
			
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

*/

int main(int argc, char const *argv[])
{
	stack list;
	for (int i = 0; i <= 15; ++i)
	{
		list.push(2*i);
		list.print();
	}
	cout<<list.getTop()<<endl;
	list.pop();
	list.print();
	list.clear();
	list.print();
	return 0;
}