using namespace std;
#include <iostream>
#include <stack>

class QueueUsingStack
{
private:
	stack<int> stack1;
	stack<int> stack2;
public:
	QueueUsingStack()
	{
		while(!stack1.empty()) stack1.pop();
		while(!stack2.empty()) stack2.pop();
	}
	void push(int x);
	void pop();
	int front();
	int size();
};

void QueueUsingStack::push(int x)
{
	stack1.push(x);
}

void QueueUsingStack::pop()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		if(!stack2.empty()) stack2.pop();
	}
	else stack2.pop();
}

int QueueUsingStack::front()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		if(!stack2.empty()) return stack2.top();
	}
	else return stack2.top();
}

int QueueUsingStack::size()
{
	return stack1.size() + stack2.size();
}