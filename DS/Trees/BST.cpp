#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct node
{
	int val;
	node* left;
	node* right;
	node* parent;
	node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}	
};

class BST
{
private:
	node* root;
public:
	BST(){
		this->root = NULL;
	}
	void add(int val);
	node* search(int val);
	void InOrder_R();
	void PreOrder_R();
	void PostOrder_R();
	void Inorder_I();
	void Preorder_I();
	void Postorder_I();
	vector<int> Inorder_S();
	vector<int> Preorder_S();
	vector<int> Postorder_S();
	void Inorder_Morris();
	void Preorder_Morris();
	void Postorder_Morris();
};

void BST::add(int val)
{
	if(this->root == NULL) this->root = new node(val);
	else{
		node* temp = this->root;
		node* trash = new node(val);
		while(temp)
		{
			if(val > temp->val) {
				if(temp->right == NULL)
				{
					temp->right = trash;
					trash->parent = temp;
					return;
				}
				temp = temp->right;
			}else{
				if(temp->left == NULL)
				{
					temp->left = trash;
					trash->parent = temp;
					return;
				}
				temp = temp->left;
			}
		}
		temp = new node(val);
	}
}

node* BST::search(int val)
{
	if(this->root == NULL) return NULL;
	node* temp = this->root;
	while(temp)
	{
		if(temp->val == val) return temp;
		else if(temp->val < val) temp = temp->right;
		else temp = temp->left;
	}
	return NULL;
}

void InorderR_Util(node* temp)
{
	if(temp == NULL) return;
	InorderR_Util(temp->left);
	cout<<temp->val<<" ";
	InorderR_Util(temp->right);
}

void BST::InOrder_R()
{
	cout<<"Inorder Recursive"<<endl;
	if(this->root) InorderR_Util(this->root);
	cout<<endl;
}

void PreorderR_Util(node* temp)
{
	if(temp == NULL) return;
	cout<<temp->val<<" ";
	PreorderR_Util(temp->left);
	PreorderR_Util(temp->right);
}

void BST::PreOrder_R()
{
	cout<<"Preorder Recursive"<<endl;
	if(this->root) PreorderR_Util(this->root);
	cout<<endl;
}


void PostorderR_Util(node* temp)
{
	if(temp == NULL) return;
	PostorderR_Util(temp->left);
	PostorderR_Util(temp->right);
	cout<<temp->val<<" ";
}

void BST::PostOrder_R()
{
	cout<<"Postorder Recursive"<<endl;
	if(this->root) PostorderR_Util(this->root);
	cout<<endl;
}


void BST::Inorder_I()
{

}

void print(stack<node* > sta)
{
	while(!sta.empty()) {
		cout<<sta.top()->val<<" ";
		sta.pop();
	}
	cout<<endl;
}
//using the parent link, otherwise use a stack
//do this later, ery very tired rn
void BST::Preorder_I()
{
	if(this->root == NULL) return;
	stack<node* > sta;
	cout<<"iterative"<<endl;
	node* temp = this->root;
	do
	{
		if(temp)
		{
			cout<<temp->val<<" ";// sta : "; print(sta); "
			sta.push(temp);
			if(temp->left) temp = temp->left;
			else 
			{
				if(!sta.empty())
					while(!sta.empty())
					{
						temp = sta.top();
						sta.pop();
						if(temp->right) {
							temp = temp->right;
							break;
						}
						else temp = NULL;
					}
				else return;
			}
		}
	}
	while(temp);
}

void BST::Postorder_I()
{
	
}

vector<int> BST::Inorder_S(){
	stack<node*> s;
	node* copy = this->root;
	vector<int> ans;
	while(copy){
		if(copy->left) copy = copy->left;
		else{
			while(!s.empty() && s.top()->right == NULL){
				ans.push_back(s.top()->val);
				s.pop();
			}
			if(!s.empty()) {
				ans.push_back(s.top()->val);
				copy = s.top()->right;
				s.pop();
			}
			else break;
		}
	}
	return ans;
}

vector<int> BST::Preorder_S(){
	
}

vector<int> BST::Postorder_S(){}

void BST::Inorder_Morris()
{
	node* cur = this->root;
	if(cur == NULL) return;
	while(cur)
	{
		if(cur->left == NULL)
		{
			cout<<cur->val<<" ";
			cur = cur->right;
		}
		else
		{
			node* pred = cur->left;
			while(pred->right && pred->right!=cur)
			{
				pred = pred->right;
			}
			if(pred->right == NULL){
				pred->right = cur;
				cur = cur->left;
			}
			else{
				pred->right = NULL;
				cout<<cur->val<<" ";		//print when coming back after resetting, mtlb left part ho chuka uske baad
				cur = cur->right;
			}
		}
	}
	cout<<endl;
}

void BST::Preorder_Morris()
{
	node* cur = this->root;
	if(cur == NULL) return;
	while(cur)
	{
		if(cur->left == NULL)
		{
			cout<<cur->val<<" ";
			cur = cur->right;
		}
		else
		{
			node* pred = cur->left;
			while(pred->right && pred->right!=cur)
			{
				pred = pred->right;
			}
			if(pred->right == NULL){
				pred->right = cur;
				cout<<cur->val<<" ";		//print when checking for the first time before going to the left side
				cur = cur->left;
			}
			else{
				pred->right = NULL;
				// cout<<cur->val<<" ";
				cur = cur->right;
			}
		}
	}
	cout<<endl;
}

void BST::Postorder_Morris()
{

}

int main(int argc, char const *argv[])
{
	BST tre;
	vector<int> v = {12,9,10,8,3,2,1,5,4,7,6,20,15,13,14,30,35,40};
	// vector<int> v = {56,23,78,1,0,-8,98,-5,23,45,72,1,2,5,46,20};
	// vector<int> v = {10,2,-8,0,1,9,7,5,8,15,14,13,12,11,18,25,19,20,21,22,23};

	for (int i = 0; i < v.size(); ++i)
	{
		tre.add(v[i]);
		// tre.print2D();
	}
	// tre.InOrder_R();
	tre.PreOrder_R();
	// tre.PostOrder_R();
	// tre.Preorder_I();
	// tre.Inorder_Morris();
	tre.Preorder_Morris();
	return 0;
}