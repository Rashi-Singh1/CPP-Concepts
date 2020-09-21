#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	unordered_map<char, node*> s;
	bool end;
	node(){end = false;}
	node(char c) {s[c] = NULL; end = false;}
};

struct trie{
	node* root;
	trie(){this->root = NULL;}
	void insert(string A);
	bool search(string A);
};

void trie::insert(string A){
	if(A.size() == 0) return;
	if(this->root == NULL) this->root = new node();
	node* cur = this->root;
	for(auto x : A){
		if(cur->s.count(x) == 0) cur->s[x] = new node();
		cur = cur->s[x];
	}
	cur->end = true;
}

bool trie::search(string A){
	if(this->root == NULL) return false;
	node* cur = this->root;
	for(auto x : A){
		if(cur == NULL || cur->s.count(x) == 0) return false;
		cur = cur->s[x];
	}
	return cur->end;
}

int main(int argc, char const *argv[])
{
	trie t;
	t.insert("Rashi Singh");
	cout<<t.search("Rashi")<<endl;
	cout<<t.search("Rashi Singh")<<endl;
	return 0;
}