#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person
{
private:                        //can be accessed only in this class
    static int count;
protected:                      //can be accessed only in this class and its subclasses
    string name;                
    int age;
public:                         //can be accessed in this class, its subclasses and outer functions as well
    Person(string name = "noname", int age = 0){
        cout<<"Constructor of Person called\n";
        (Person::count)++;
        this->name = name;
        this->age = age;
    }
    void setName(string name){ this->name = name;}
    void setAge(int age){ this->age = age;}
    auto getCount(){return this->count;}
    auto getName(){return this->name;}
    auto getAge(){return this->age;}
};

int Person::count = 0;

class Student:public Person{
private:
    int roll;
public:
        //*****To use the constructor of the base class******
        Student(int roll, string name = "noname", int age = 0):Person(name,age){

            //Note that constructor of base class is called first
            //In case class Duck : public class Animal, class Bird
            //first Animal constructor then Bird constructor will be called and ultimately duck constructor
            cout<<"Constructor of Student called\n";
            this->roll = roll;
        }
        ~Student(){}
        void intro(){
            //here directly using this->name and not calling getName
            //this is bcs name is a protected member of its base class
            //however to get count, need to call getCount
            cout<<"Hello, my name is "<<this->name<<" and roll no. is "<<this->roll<<" and my age is : "<<this->age<<endl;
        }
};

//This way all the public and protected members and functions of the base class are protected in this class
//Now outer functions can't call its inherited data
class Officer:protected Person{
private:
protected:
    int id;
    string job;
public:
    Officer(int id, string job, string name = "noname", int age = 0):Person(name,age){
        this->id = id;
        this->job = job;
    }
    void report(){
        cout<<"Hello, my name is "<<this->name<<" and my id is "<<this->id<<" and my job is "<<this->job<<" and my age is : "<<this->age<<endl;
    }
};

class Banker:protected Officer{
    Banker(int id, string name = "noname", int age = 0):Officer(id,"Banker",name,age){}
};

//By default, there is private inheritance
//This way all the public and protected members and functions of the base class are private in this class
//now noone except this class itself can call its inherited data
class President:private Person{
private:
protected:
    using Person::name;           //way to make certain member have a diff access modifier
public:
    using Person::getName;        //way to make certain method have a diff access modifier
    President(string name, int age = 0):Person(name,age){}
};

class USA_Pres:protected President{
private:
protected:
public:
    USA_Pres(string name, int age = 0):President(name,age){}
    void change_Pres(string name){
        this->name = name;                  //since name has been made protected in the base class, I can directly change it like this
    }
    void print(){
        cout<<"USA president is "<<this->name<<endl;
    }
};

class Mother{
protected:
    string Mother_name;
public:
    Mother(string name){
        cout<<"Mother constructor called\n";
        this->Mother_name = name;
    }

    void Mother_advice(){
        cout<<"This is the advice of Mother\n";
    }
};

class Father{
protected:
    string Father_name;
public:
    Father(string name){
        cout<<"Father constructor called\n";
        this->Father_name = name;
    }

    void Father_advice(){
        cout<<"This is the advice of Father\n";
    }
};

class Child:public Mother, public Father{
protected:
    string name;
public:

    //to call constructors of multiple inherited classes
    Child(string name = "no_child_name", string mother_name = "no_mother_name", string father_name = "no_father_name"):Mother(mother_name), Father(father_name){
        cout<<"Child constructor called\n";
        this->name = name;
    }

    void print(){
        cout<<"My name is "<<this->name<<" and my mother's name is "<<this->Mother_name<<" and my father's name is "<<this->Father_name<<endl;
    }
};

class Base{
private:
protected:
    string name;                    //Note that even tho Sublass has public type inheritance, name is not made public for Subclass (i.e. public type inheritance keeps the same security level as Base class)
public:
    void introduction(){
        cout<<"This is Base\n";
    }

    void Bye(){
        cout<<"Base bye\n";
    }
};

class Subclass:public Base{
private:
protected:
public:
    void introduction(){
        cout<<"This is Subclass\n";     //simply overrides introduction of Base class
        Base::introduction();           //to access (overridden method) introduction of Base class
        Base::Bye();
    }
};

void intro(Base base){
    base.introduction();
}

int main(int argc, char const *argv[])
{
    //In case of Student rashi;
    //Automatically name is noname, age = 0(even when i had not use constructor of base class) 
    //This is bcs constructor of base is called first automatically
    Student rashi(1,"Rashi");
    rashi.intro();

    /*********************************************************************************************************/
    
    Officer Rashi(1,"coder", "Rashi");
    // Rashi.setName("Rashi");         //this would give error, as setName(public function of Person class is now protected in Officer class)
    Rashi.report();

    USA_Pres trump("Trump",68);
    trump.print();

    /*********************************************************************************************************/

    Child child("child", "mom", "dad");
    child.print();

    Subclass tree;
    tree.introduction();      
    intro(tree);                      //Since tree is of type base and subclass, can simply pass tree to intro and since in intro, it is being treated as base, it called base ka intro

    /*********************************************************************************************************/

    return 0;
}
