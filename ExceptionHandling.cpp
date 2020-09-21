#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Base {}; 
class Derived: public Base {};

int main(int argc, char const *argv[])
{
    int x = -1;
    cout<<"Before try : \n";
    try{
        if(x < 0){
            throw string("x less than 0");
            cout<<"After throw (Never executed)\n";
        }
    }catch(int a){
        cout<<"Exception caught : "<<a<<"\n";
        // std::cerr<<e.what()<<endl;
    }
    
    //can have different catches according to what is thrown
    catch(string a){
        cout<<"Exception caught : "<<a<<"\n";
    }

    //for std exceptions
    catch(const exception& e){
        std::cerr << e.what() <<"\n";
    }

    //catches all kinds of exceptions
    catch(...){
        cout<<"Default exception\n";
    }

    cout<<"After catching \n";

    // try catch can be nested too

    //in case of inherited classes : object d is thrown
    //d is of Base as well as Derived type
    //Therefore, if catch of Base is written, catch of Derived is not accessible
    //However, if catch of Derived is written first, then both the catches are accessible
    Derived d; 
    // some other stuff 
    try { 
        // Some monitored code 
        throw d; 
    } 
    catch(Derived d) {  
            cout<<"Caught Derived Exception\n"; 
    } 
    catch(Base b) {  
            cout<<"Caught Base Exception\n"; 
    } 
    return 0;
}
