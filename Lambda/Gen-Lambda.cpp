#include <iostream>
using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vec;

int main(int argc, char const *argv[])
{
    //way 1
    //idk how to write template inline
    // template<typename T>
    // T sum1 = [](T a, T b) -> T {return a + b};

    //way 2
    auto sum2 = [](auto a, auto b){
        return a + b;
    };
    cout<<sum2(1,2)<<endl;
    cout<<sum2(1.43,65.3)<<endl;

    //cant just pass "Rashi", "Singh" --gives error
    cout<<sum2(string("Rashi"), string("Singh"))<<endl;

    auto greater = [](auto a, auto b){
        return a <= b;
    };

    // Initialize a vector of integers 
    vector<int> vi = { 1, 4, 2, 1, 6, 62, 636 }; 
  
    // Initialize a vector of doubles 
    vector<double> vd = { 4.62, 161.3, 62.26, 13.4, 235.5 }; 
  
    // Initialize a vector of strings 
    vector<string> vs = { "Tom", "Harry", "Ram", "Shyam" }; 


    auto print = [](auto& a){
        for(auto x : a) cout<<x<<" ";
        cout<<endl;
    };

    print(vi);
    print(vd);
    print(vs);

    //Generalized sort function
    // Sort integers 
    sort(vi.begin(), vi.end(), greater); 
  
    // Sort doubles 
    sort(vd.begin(), vd.end(), greater); 
  
    // Sort strings 
    sort(vs.begin(), vs.end(), greater); 

    print(vi);
    print(vd);
    print(vs);

    return 0;
}
