#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Encapsulation{
private:
    int x;  //hidden members
public : 
    void set_x(int a){
        this->x = a;
    }

    int get_x(){
        return this->x;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
