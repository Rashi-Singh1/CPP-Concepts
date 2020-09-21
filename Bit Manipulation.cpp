#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Some amazing tips on this one
// https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
// https://www.geeksforgeeks.org/bits-manipulation-important-tactics/

auto getBinary(int num){
    return bitset<8>(num);
}

//pos is like n n-1 ... 2 1 0
void setBit(int* a, int pos){
    (*a) = (*a)|(1<<pos);
}

//pos is like n n-1 ... 2 1 0
int readBit(int a, int pos){
    return (a>>pos)&1;
}

//pos is like n n-1 ... 2 1 0
void toggleBit(int* a, int pos){
    (*a) = (*a)^(1<<pos);
}

//pos is like n n-1 ... 2 1 0
void clearBit(int* a, int pos){
    (*a) = (*a)&(~(1<<pos));
}

//logic :
//x   :     .....100...00, on right of lowest 1, all would be zeroes
//x-1 :     .....011...11, the right zeroes become 1 and the lowest 1 becomes 0, rest is same
//x & x-1 : this will not change left of lowest 1 and baaki would be zero, making the lowest one 0 (right to lowest 1 was already 0)  
void stripLowestOne(int* a){
    (*a) = (*a)&((*a)-1);
}

//logic :
//x   :     .....011...11, on right of lowest 0, all would be 1s
//x+1 :     .....100...00, the right 1s become 0 and the lowest 0 becomes 1, rest is same
//x | x+1 : this will not change left of lowest 0 and baaki would be 1, making the lowest zero 1 (right to lowest 0 was already 1)  
void stripLowestZero(int* a){
    (*a) = (*a)|((*a)+1);
}

int getLowestOne(int a){
    return log2(a&(-1*a));
}

int getLowestZero(int a){
    return getLowestOne(~a);
}

void clear_LSB_to_Ith_Bit(int* a, int i){
    //way 1:
    //Logic: (long long int)INT_MAX<<(i+1) gives 11111000 for i = 2
    //(*a) = (*a) & ((long long int)INT_MAX<<(i+1));

    //way 2:
    //Logic: we want to get zeroes upto ith bit baaki 1
    //to get multiple 1 beyond a point, best bet is to use (1<<(something)) - 1 or its negation(depending on which side we want 1)
    //for i = 2, 1<<(2+1) gives 00001000
    //1000-1 = 00000111, whose negation gives 11111000
    (*a) = (*a) & ~((1<<i+1)-1);
}

void clear_MSB_to_Ith_Bit(int* a, int i){
    //way 1:
    //Logic: ~((long long int)INT_MAX<<(i)) gives 00000011 for i = 2
    //(*a) = (*a) & ~((long long int)INT_MAX<<(i));

    //way 2:
    //Logic: we want to get zeroes upto ith bit baaki 1
    //to get multiple 1 beyond a point, best bet is to use (1<<(something)) - 1 or its negation(depending on which side we want 1)
    //Now no negation needed, also, keep ith bit as 0, i.e. shift i times and minus 1, giving 1..11 from i-1 to 0 bits
    (*a) = (*a) & ((1<<i)-1);
}

//set 5th bit as 1
char toUpper(char a){
    return a | ' ';
}

// set 5th bit as 0
char toLower(char a){
    //way 1:
    // return a & ~(' ');

    return a & '_';
}

int getLog2(int a){
    int ans = 0;
    while(a > 1){
        ans++;
        a >>= 1;
    }
    return ans;
}

int countOnes(int a){
    int ans = 0;
    while(a > 0){
        ans++;
        a &= (a-1);
    }
    return ans;
}

bool isPowerOf2(int a){
    //way 1:, check after getting 1st 1, whether that is same as a
    // if(((a==(a&(-1*a))) && a)) return true;
    // return false;

    //way 2:
    //check after removing 1st 1, whether 0 is left
    return (a && !(a & (a-1)));
}

int main(int argc, char const *argv[])
{
    int a = 23, b = 78;
    cout<<bitset<8>(a)<<" "<<bitset<8>(b)<<endl;

    //simple bitwise operations
    cout<<"a|b    "<<(a|b)<<"  "<<getBinary((a|b))<<endl;
    cout<<"a&b    "<<(a&b)<<"   "<<getBinary((a&b))<<endl;
    cout<<"a^b    "<<(a^b)<<"  "<<getBinary((a^b))<<endl;
    cout<<"~(a^b) "<<(~(a^b))<<" "<<getBinary((~(a^b)))<<endl;
    cout<<"-(a^b) "<<(-1*(a^b))<<" "<<getBinary((-1*(a^b)))<<endl;

    //shift operations
    //basically multiply by 2^num, where a<<num
    cout<<"a<<2   "<<(a<<2)<<"  "<<getBinary(a<<2)<<endl;
    cout<<"a<<5   "<<(a<<5)<<"  "<<getBinary(a<<5)<<endl;

    //basically divide by 2^num, where a>>num
    cout<<"a>>2      "<<(a>>2)<<"  "<<getBinary(a>>2)<<endl;                //for 0 as msb, it adds 0 at start
    cout<<"(~a)>>2  "<<((~a)>>2)<<"  "<<getBinary((~a)>>2)<<endl;           //for 1 as msb, it adds 1 at start

    //bit manipulation tricks
    //set bit
    cout<<"set bit 3 "<<getBinary(a)<<" ";
    setBit(&a, 3);
    cout<<getBinary(a)<<endl;

    //clear bit
    cout<<"clear bit 3 "<<getBinary(a)<<" ";
    clearBit(&a, 3);
    cout<<getBinary(a)<<endl;

    //read bit
    cout<<"read bit 3 "<<getBinary(a)<<" "<<readBit(a, 3)<<endl;
    cout<<"read bit 7 "<<getBinary(a)<<" "<<readBit(a, 7)<<endl;

    //toggle bit
    cout<<"toggle bit 3 "<<getBinary(a)<<" ";
    toggleBit(&a, 3);
    cout<<getBinary(a)<<endl;

    cout<<"toggle bit 7 "<<getBinary(a)<<" ";
    toggleBit(&a, 7);
    cout<<getBinary(a)<<endl;

    cout<<"stripLowestOne  "<<a<<" "<<getBinary(a)<<" ";
    stripLowestOne(&a);
    cout<<getBinary(a)<<" "<<a<<endl;

    cout<<"stripLowestZero "<<a<<" "<<getBinary(a)<<" ";
    stripLowestZero(&a);
    cout<<getBinary(a)<<" "<<a<<endl;

    cout<<"stripLowestOne  "<<a<<" "<<getBinary(a)<<" "<<getLowestOne(a)<<endl;
    cout<<"stripLowestZero "<<a<<" "<<getBinary(a)<<" "<<getLowestZero(a)<<endl;

    //way 1:
    cout<<"clear everything LSB to 2nd bit "<<getBinary(b)<<" "<<getBinary((b&(long long int)INT_MAX<<(3)))<<" "<<endl;

    //way 2:
    cout<<"clear everything LSB to 2nd bit "<<getBinary(b)<<" ";
    clear_LSB_to_Ith_Bit(&b,2);
    cout<<getBinary(b)<<" "<<endl;

    cout<<"clear everything MSB to 2nd bit "<<getBinary(a)<<" ";
    clear_MSB_to_Ith_Bit(&a,2);
    cout<<getBinary(a)<<" "<<endl;

    cout<<toLower('a')<<" "<<toLower('A')<<endl;
    cout<<toUpper('a')<<" "<<toUpper('A')<<endl;

    cout<<45<<" "<<getLog2(45)<<endl;
    cout<<125<<" "<<getBinary(125)<<" "<<countOnes(125)<<endl;

    cout<<"isPowerOf2 "<<128<<" "<<isPowerOf2(128)<<endl;

    //convert binary to base 10 integer automatically
    auto number = 0b11;
    cout<<number<<endl;

    //convert hexadecimal to base 10 integer automatically
    auto number2 = 0xa20;
    cout<<number2<<endl;

    cout<<getBinary(7)<<" "<<getBinary(8)<<" "<<getBinary(15)<<endl;
    for(int i = 0 ; i <= 13; i++) cout<<getBinary(i)<<endl;
    return 0;
}
