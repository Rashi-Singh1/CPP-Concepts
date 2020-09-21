#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person(string name = "noname", int age = 0){
        this->name = name;
        this->age = age;
    }

    //Using the virtual keyword basically allows the function whosThat to use the function based on what class the object belongs to
    //i.e. in case of a hierarchy of classes related by inheritance, if some subclass has overwritten a method
    //then using the virtual keyword with that function in the base class allows the whosThat function to use intro of subclass(if present), else it uses the intro of the base class
    virtual void intro(){
        cout<<"Hello this is Person "<<this->name<<endl;
    }
};

class Farmer:public Person{
protected:
protected:
public:
    Farmer(string name = "noname", int age = 0):Person(name, age){}
    void intro(){
        cout<<"Hello this is Farmer "<<this->name<<endl;
    }
};

class Teacher:public Person{
protected:
public:
    Teacher(string name = "noname", int age = 0):Person(name, age){}
    void intro(){
        cout<<"Hello this is Teacher "<<this->name<<endl;
    }
};

//****** polymorphism is the ability of a message to be displayed in more than one form.******
//       a) Compile time polymorphism :
//              - Function Overloading  : like having diff types of constructors
//              - Operator overloading  : single operator ‘+’ when placed between integer operands , adds them and when placed between string operands, concatenates them.       
//       b) Run time polymorphism :
//              - Virtual functions/Method overriding : depending on type of object, a func can take take diff forms

//Note that using virtual function intro avoids function overloading for whosThat
//i.e. whosThat(Teacher* teacher)
//     whosThat(Farmer* farmer)
void whosThat(Person* person){
    person->intro();
}

int main(int argc, char const *argv[])
{
    //in both cases, even tho I used the keyword virtual in Person ka intro
    //This is bcs, just like this, it just creating a copy to the stack, while we want it to point (pointer or ref) to the actual object
    //so that it can check the members and method of that class 
    // Farmer farmer("a");
    // whosThat(farmer);

    // Teacher teacher("b");
    // whosThat(teacher);

    Farmer farmer("a");
    whosThat(&farmer);

    Teacher teacher("b");
    whosThat(&teacher);

    // Or use     whosThat(Person &person){
    //              person.intro(); 
    //            }

    // Call as :  whosThat(farmer);

    return 0;
}
