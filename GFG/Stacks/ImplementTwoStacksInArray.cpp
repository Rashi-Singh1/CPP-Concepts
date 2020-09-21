#include <iostream>
using namespace std;

class ImplementTwoStacksInArray
{
private:
	int stack1;
	int stack2;
	int size;
public:
	int* array;
	ImplementTwoStacksInArray(int size)
	{
		stack1 = 0;
		stack2 = size-1;
		array = new int[size];
		this->size = size;
	}
	void push1(int val);
	void push2(int val);
	int top1();
	int top2();
	void pop1();
	void pop2();
	int size1();
	int size2();
	bool isEmpty1();
	bool isEmpty2();
	void print();
};

void ImplementTwoStacksInArray::push1(int val)
{
	if(stack1 <= stack2) array[stack1++] = val; 
}

void ImplementTwoStacksInArray::push2(int val)
{
	if(stack1 <= stack2) array[stack2--] = val; 
}

int ImplementTwoStacksInArray::top1()
{
	if(stack1 > 0) return array[stack1-1];
}

int ImplementTwoStacksInArray::top2()
{
	if(stack2 < (this->size)-1) return array[stack2+1];
}

void ImplementTwoStacksInArray::pop1()
{
	if(stack1 > 0) stack1--;
}

void ImplementTwoStacksInArray::pop2()
{
	if(stack2 < (this->size)-1) stack2++;
}

int ImplementTwoStacksInArray::size1()
{
	return stack1;
}

int ImplementTwoStacksInArray::size2()
{
	return this->size-stack2-1;
}

bool ImplementTwoStacksInArray::isEmpty1()
{
	if(stack1 > 0) return false;
	else return true;
}

bool ImplementTwoStacksInArray::isEmpty2()
{
	if(stack2 < (this->size)-1) return false;
	else return true;
}

void ImplementTwoStacksInArray::print()
{
	for(int i = 0;i<stack1;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<" <- top"<<endl;
	for(int i = this->size - 1;i>stack2;i--)
	{
		cout<<array[i]<<" ";
	}
	cout<<" <- top"<<endl;
}

int main(int argc, char const *argv[])
{
	ImplementTwoStacksInArray list(50);
	for (int i = 0; i <= 15; i+=2)
	{
		list.push1(2*i);
		list.push2(2*i);
		// cout<<list.size1()<<" "<<list.size2()<<endl;
		cout<<"i "<<i<<endl; list.print();
		// list.print();
	}
	cout<<list.size1()<<" "<<list.top1()<<" "<<list.size2()<<" "<<list.top2()<<endl;
	list.pop1();
	list.pop2();
	cout<<list.size1()<<" "<<list.top1()<<" "<<list.size2()<<" "<<list.top2()<<endl;
	return 0;
}