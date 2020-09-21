// ","map<int, string, greater <int> > mymap; //

#include <iostream>
using namespace std;
#include <map>

int main(int argc, char const *argv[])
{
	map<string,int> Map= {{"Rashi",1},{"Kirti",10}};
	Map.insert(pair<string,int>("Soumik",100));
	for(auto x : Map)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<Map.size()<<endl;
	//similar functions as of others of empty, max_size, erase, clear, swap, at
	//many other features in interviewbit heap section

	cout<<"Max element : "<<Map.rbegin()->first<<endl;
	cout<<"Min element : "<<Map.begin()->first<<endl;
	map<int,int> map2 = {{1,3},{2,6},{9,0}};

	// lower bound returns ceilSearch
	int key = 0;
	cout<<map2.lower_bound(key)->first<<" "<<map2.lower_bound(key)->second<<endl;
	key = 8;
	cout<<map2.lower_bound(key)->first<<" "<<map2.lower_bound(key)->second<<endl;
	//take note that here key is greater than the largest element, so it does not return the largest element, but number of elements as key and 0 as value
	
	// upper_cound returns ceilSearch but, is the element is present it will still return the next greater element
	return 0;
}

