#include <iostream>
#include <bitset>
using namespace std;
#define M 5
int main(int argc, char const *argv[])
{
    bitset<M> bset1;                    //initializes bitset with 00000
    bitset<M> bset2(3);                 //initializes bitset with 00011
    bitset<M> bset3(string("10101"));   //initializes bitset with 10101
    
    cout<<"bitset1 : "<<bset1<<endl;
    cout<<"bitset2 : "<<bset2<<endl;
    cout<<"bitset3 : "<<bset3<<endl;
    
    bset1[1] = 1;                       //sets bitset to 00010
    cout<<"No of set bits in bset1 : "<<bset1.count()<<endl;                    //.count : no of set bits
    cout<<"No of unset bits in bset1 : "<<bset1.size() - bset1.count()<<endl;   //.size : total no of bits 
    
    //******test function is very imp*******
    for (int i = 0; i < bset1.size(); i++)
    {
        cout<<i<<"_th bit in bset1 : "<<bset1.test(i)<<endl;
    }
    cout<<"Is any bit set : "<<bset1.any()<<endl;
    cout<<"Are all bits zero : "<<bset1.none()<<endl;

    bset1.set();    cout<<bset1<<endl;  //set all bits
    bset1.set(4);   cout<<bset1<<endl;  //default : set 4th bit to 1
    
    bset1.set(4,1); cout<<bset1<<endl;  //make 4th bit 1
    bset1.set(4,0); cout<<bset1<<endl;  //make 4th bit 0
    
    bset1.reset();  cout<<bset1<<endl;  //reset all bits
    bset1.reset(1); cout<<bset1<<endl;  //reset 2nd bit

    bset1.flip();   cout<<bset1<<endl;  //flip all bits
    bset1.flip(1);  cout<<bset1<<endl;  //flip 2nd bit

    // cout<<"Input any number less than 256"<<endl;
    // int num;
    // cin>>num;

    // //******Very good observation*******
    // cout<<"binary equivalent of "<<num<<" is : "<<bitset<8>(num)<<endl;
    
    bitset<4> bset4(9);
    bitset<4> bset5(3);
    
    //comparison
    cout<<(bset4 == bset5)<<endl;   
    cout<<(bset4 != bset5)<<endl;   
    
    //bitwise operators
    //remember ~ is the bitwise not operator (can use flip too...but it changes the bitset)
    //use bset4 ^= bset5 to assign the value of bitwise operation to bset4
    cout<<"xor : "<<(bset4 ^ bset5)<<endl;          //bitwise xor
    cout<<"xnor : "<<~(bset4 ^ bset5)<<endl;        //bitwise xnor  
    cout<<"and : "<<(bset4 & bset5)<<endl;          //bitwise and
    cout<<"or : "<<(bset4 | bset5)<<endl;           //bitwise or

    bitset<4> bset6(1);
    cout<<"bset6 : "<<bset6<<endl;

    //left and right shifting
    cout<<"left shift : "<<(bset6 << 2)<<endl;      //left shifting  : equivalent to multiplying with 4 (2 ki power 2)
    cout<<"right shift : "<<(bset6 >> 2)<<endl;     //right shifting : equivalent to dividing with 4 (2 ki power 2)
    return 0;
}
