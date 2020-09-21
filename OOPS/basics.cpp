#include <iostream>
using namespace std;

class Basics
{
private:
    int name;
    int age;
    int data;
    int id;
public:
    //constructor called when mem is allocated
        Basics(int id = 0, int name = 10, int age = 20, int data = 30){
        this->name = name;
        this->age = age;
        this->data = data;
        this->id = id;
    } 

    //Destructor called when mem is freed
    ~Basics(){
        cout<<"destructor called for id : "<<id<<"\n";
    }
    
    void print(){
        cout<<"name : "<<this->name<<" age : "<<this->age<<" data : "<<data<<endl;
    }
};

class Destructor_Example
{
//Example with members as pointers which are dynamically allocated mem when constructor is called
//and then dealloacted mem when destructor is called
private:
    string* name;
    int* age;
public:
    Destructor_Example(string name = "noone", int age = 0){
        this->name = new string;
        *(this->name) = name;
        this->age = new int;
        *(this->age) = age;
    }
    ~Destructor_Example(){
        delete this->name;
        delete this->age;
        cout<<"All mem is now freed\n";
    }

    void print(){
        cout<<"name : "<<*(this->name)<<" age : "<<*(this->age)<<endl;
    }
};

class Static_Mem_Var
{
private:
    //static members are shared by all instances of a class and are initialized only once 
    static int count;
public:
    Static_Mem_Var();
    void print();

    //static functions are also shared, just like static members, and they can only use static variables(members)
    static void status();
};

Static_Mem_Var::Static_Mem_Var(){
    (this->count)++;
}

//initialize the static member
int Static_Mem_Var::count = 0;

void Static_Mem_Var::print(){
    cout<<"There are "<<this->count<<" humans in this program\n";
}

void Static_Mem_Var::status(){
    cout<<"There are "<<Static_Mem_Var::count<<" humans in this program\n";
}

int main(int argc, char const *argv[])
{
    //object instance in the below form is added to stack and is freed at the end automatically
    //for optional parameters, values are assigned from the left
    Basics rashi(1,1,2,3);
    Basics rashi2(2,1,2);
    Basics rashi3(3,1);
    Basics rashi4;
    rashi.print();
    rashi2.print();
    rashi3.print();
    rashi4.print();

    //this type of object is added to the heap
    Basics *rashi5 = new Basics(5,1,2);
    rashi5->print();
    delete rashi5;                      //without this the destructor won't be called
    

    /********************************************************************************************************/
  
    Destructor_Example* example = new Destructor_Example("Rashi");
    example->print();
    delete example;

    Destructor_Example example2("Rashi");
    example2.print();


    /********************************************************************************************************/
    Static_Mem_Var human1;
    human1.print();
    
    Static_Mem_Var human2;
    human2.print();
    
    Static_Mem_Var human3;
    human3.print();
    
    Static_Mem_Var human4;
    human4.print();
    
    Static_Mem_Var human5;
    human5.print();

    //to invoke static functions
    Static_Mem_Var::status();
    return 0;
}
