#include <iostream>
using namespace std;
#include "Queue_LinkedListWay.h"

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

*/

int main(int argc, char const *argv[])
{
	queue list;
	for (int i = 0; i <= 15; ++i)
	{
		list.push(2*i);
		list.print();
	}
	cout<<list.getFront()<<endl;
	list.pop();
	list.print();
	list.clear();
	list.print();
	return 0;
}