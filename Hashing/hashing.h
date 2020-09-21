#include <iostream>
using namespace std;

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

class HashMap
{
private:
	int size;
public:
	vector<node*> hash;
	HashMap(int size){
		this->size = size;
		for (int i = 0; i < size; ++i)
		{
			hash.push_back(NULL);
		}
	}
	int hashFunc(int val);
};