#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void suf(vector<int>& A, string sub){
    int start = 0;
    for(int i = 1 ; i < sub.size(); i++){
        if(sub[start] == sub[i]) A[i] = A[start++] + 1;
        
    }
}

bool KMP(string sup, string sub){
    vector<int> A(sub.size(),0);
    suf(A,sub);
}

int main(int argc, char const *argv[])
{
    string sup = "akjhabcabcakhg", sub = "abcab";
    cout<<KMP(sup,sub)<<endl;
    return 0;
}
