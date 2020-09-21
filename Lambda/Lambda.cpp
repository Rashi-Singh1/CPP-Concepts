#include <iostream>
using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vec;

void print(vec &A){
    for_each(A.begin(), A.end(), [](int a){
        cout<<a<<" ";
    });
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    vec A = {4,1,3,5,2,3,1,7};
    print(A);
    sort(A.begin(), A.end(), [](int a, int b){
        return a <= b;
    });

    print(A);

    auto p = find_if(A.begin(), A.end(), [](int a){
        return a >=4;
    });
    p == A.end() ? cout<<"not found\n" : cout<<*p<<"\n";

    int count = count_if(A.begin(),A.end(), [](int a){
        return a >=4;
    });
    cout<<"count of no  >= 4 : "<<count<<endl;

    // p = unique(A.begin(), A.end(), [](int a, int b){
    //     return a == b;
    // });
    p = unique(A.begin(), A.end());
    A.resize(distance(A.begin(),p));
    print(A);

    //specifying the return value
    sort(A.begin(), A.end(), [](int a, int b) -> bool{
        return a >= b;
    });

    print(A);

    int out = accumulate(A.begin(), A.end(), 0, [](int a, int b){
        return a + b;
    });

    cout<<"sum : "<<out<<endl;

    //inline function
    auto square = [](int i){
        return i*i;
    };

    cout<<"square of 15 : "<<square(15)<<endl;
    int N = 6;
    print(A);
    //capturing variables of enclosing scope in inline functions

    //capturing all by reference
    auto output_ref = [&](int a){
        A[0] = a;
        return (float)a/(float)(N);
    };

    //capturing all by value
    auto output_value = [=](int a){
        // A[0] = a;                    //causes error of assignment of read only address
        return (float)a/(float)(N);
    };

    auto output_value2 = [&A, N](int a){
        A[0] = a;                    //causes error of assignment of read only address
        return (float)a/(float)(N);
    };

    cout<<output_ref(24)<<endl;
    print(A);
    cout<<output_value(24)<<endl;
    print(A);
    cout<<output_value2(100)<<endl;
    print(A);

    cout<<count_if(A.begin(), A.end(), [=](int a){
        return a >= N;
    })<<endl;
    return 0;
}
