#include <iostream>
using namespace std;
#include <bits/stdc++.h>		//for unordere_set

int main(int argc, char const *argv[])
{
	//by the way there is also a set, just like there is map for unordered_map
	//set has everything O(LogN), whereas unordered_set has O(1) on avg, worst case is O(n)
	unordered_set<string> Set;
	Set.insert("Rashi");
	Set.insert("Rashi1");
	Set.insert("Rashi2");
	Set.insert("Rashi3");
	if(Set.find("Rashi") == Set.end()) cout<<"Rashi not found"<<endl;
	else cout<<"Rashi found"<<endl;
	if(Set.find("Rashi5") == Set.end()) cout<<"Rashi5 not found"<<endl;
	else cout<<"Rashi5 found"<<endl;
	for(auto x : Set)			//for auto, no * used
	{
		cout<<x<<endl;
	}
	for (std::unordered_set<string>::iterator i = Set.begin(); i != Set.end(); ++i)
	{
		cout<<(*i)<<endl;		//for iterator * is needed
	}

	//some extra methods
	cout<<Set.size()<<endl;		//no of elements in the set
	cout<<Set.count("Rashi")<<endl;	//no of occurences of an element in a set
	cout<<Set.count("Rashi5")<<endl;  //at max count can be 1
	unordered_set<string> copy = Set;		//how to copy one set to anothet using =
	for(auto x : copy) cout<<x<<" ";
		cout<<endl;
	copy.insert("Rashi23");
	copy.swap(Set);
	for (std::unordered_set<string>::iterator i = Set.begin(); i != Set.end(); ++i)
	{
		cout<<(*i)<<" ";
	}cout<<endl;
	Set.erase("Rashi23");	//would erase only that element
	Set.erase("Rashi5");	//no error if not present
	// Set.erase(Set.find("Rashi3"),Set.end());	//would erase everything from that element onwards
	Set.erase(Set.find("Rashi5"),Set.end());
	for (std::unordered_set<string>::iterator i = Set.begin(); i != Set.end(); ++i)
	{
		cout<<(*i)<<" ";
	}cout<<endl;
	cout<<copy.max_size()<<endl;		//max no of elements a set can store
}