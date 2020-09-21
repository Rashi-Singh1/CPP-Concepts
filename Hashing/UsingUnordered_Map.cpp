#include <iostream>
using namespace std;
#include <unordered_map>
//check out the diff between unordered_set and unordered_map

int main(int argc, char const *argv[])
{
	unordered_map<string,int> umap;

	umap.insert(make_pair("Rashi",1));
	umap.insert(make_pair("Singh",2));
	umap.insert(make_pair("Paul",1));
	umap.insert(make_pair("Priyanshu",4));

	if(umap.find("Paul") == umap.end()) cout<<"Paul Not found"<<endl;
	else cout<<umap.find("Paul")->first<<" "<<umap.find("Paul")->second<<endl;

	if(umap.find("Saiorse Ronan") == umap.end()) cout<<"Saiorse Ronan Not found"<<endl;
	else cout<<umap.find("Saiorse Ronan")->first<<" "<<umap.find("Saiorse Ronan")->second<<endl;

	for(auto x : umap)
			cout<<x.first<<" "<<x.second<<endl;
	cout<<endl;

	for(std::unordered_map<string,int>::iterator i = umap.begin();i!=umap.end();i++)
	{
		cout<<i->first<<" "<<i->second<<endl;		//iterator neeeds arrow
	}

	cout<<umap.count("Rashi")<<endl;		//tells no of things mappped to a key (can't be more than 1?)
	cout<<umap.count("Blongeee")<<endl;
	cout<<umap.at("Priyanshu")<<endl;		//works same as umap["Priyanshu"]
	cout<<umap.size()<<endl;
	return 0;
}

/*
	Some additional functions regarding buckets etc.
*/