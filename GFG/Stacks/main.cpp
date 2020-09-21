#include <iostream>
using namespace std;
#include "QueueUsingStack.h"

int main(int argc, char const *argv[])
{
	QueueUsingStack list;
	for (int i = 0; i <= 15; ++i)
	{
		list.push(2*i);
		cout<<list.size()<<endl;
		// list.print();
	}
	cout<<list.size()<<" "<<list.front()<<endl;
	list.pop();
	cout<<list.size()<<" "<<list.front()<<endl;
	return 0;
}