#include <iostream>
#include <utility>		//for pair
using namespace std;
// typedef pair<string,int> pair;

#define forLoop(i,start,end) for(int i = start;i<end;i++);

int main(int argc, char const *argv[])
{
	pair<int,int> Pair = {1,2};	//does it work this way?
	pair<int,int> Pair3 (45,99);	//does it work this way?
	pair<int,int> Pair2;
	pair<int,int> Pair4;
	Pair2.first = 4;
	Pair2.second = 15;
	Pair4 = make_pair(16,23);
	cout<<"1 "<<Pair.first<<" "<<Pair.second<<endl;
	cout<<"2 "<<Pair2.first<<" "<<Pair2.second<<endl;
	cout<<"3 "<<Pair3.first<<" "<<Pair3.second<<endl;
	cout<<"4 "<<Pair4.first<<" "<<Pair4.second<<endl;		//four ways of making pair

	//Some Utilities : 
	Pair.swap(Pair2);		//to swap both
	cout<<"1 "<<Pair.first<<" "<<Pair.second<<endl;
	cout<<"2 "<<Pair2.first<<" "<<Pair2.second<<endl;
	cout<<"3 "<<Pair3.first<<" "<<Pair3.second<<endl;
	cout<<"4 "<<Pair4.first<<" "<<Pair4.second<<endl;	


	//operators : 
	pair<int, int>pair1 = make_pair(1, 12); 
    pair<int, int>pair2 = make_pair(9, 12); 

  	forLoop(i,0,5) 
  	{
  		cout<<"haha ";
  	}
  	cout<<endl;
  
    cout << (pair1 == pair2) << endl; 
    cout << (pair1 != pair2) << endl; 
    cout << (pair1 >= pair2) << endl; 
    cout << (pair1 <= pair2) << endl; 
    cout << (pair1 > pair2) << endl; 
    cout << (pair1 < pair2) << endl;		//pretty obvious, just take, comparisons are wrt to first value only
	pair<int,int> Pair5 = Pair;		//simple equals to operator works
	cout<<"4 "<<Pair5.first<<" "<<Pair5.second<<endl;	


	//Some extra points :
	//pair<int,float> would be initialized as 0
	//pair<char,string> would be initialized as NULL
	return 0;
}