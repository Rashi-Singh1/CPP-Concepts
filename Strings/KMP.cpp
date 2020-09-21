#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void suf(vector<int>& A, string sub){
    int i = 0;
    for(int j = 1 ; j < sub.size(); j++){
        if(sub[i] == sub[j]) A[j] = ++i;
        else{
            if(i == 0) A[j] = 0;
            else {
                i = A[i-1];
                j--;
            }
        }
    }
    for(int i = 0 ; i < A.size(); i++) cout<<i<<" "; cout<<endl;
    for(auto x : A) cout<<x<<" "; cout<<endl;
}

int KMP(string sup, string sub){
    vector<int> A(sub.size(),0);
    suf(A,sub);
    int i = 0, j = 0;      //for sub index
    for(j = 0; j < sup.size(); j++){
        if(i == sub.size()) return j-i;
        if(sup[j] == sub[i]) i++;
        else{
            if(i == 0) continue;
            else {
                i = A[i-1];
                j--;
            }
        }
    }
    if(i == sub.size()) return j-i;
    return -1;
}

int main(int argc, char const *argv[])
{
    string sup = "akjhabcabcakhg", sub = "abcab";
    // string sup = "akjhabcabcakhg", sub = "AAACAAAA";
    // string sup = "akjhabcabcakhg", sub = "aabaacaabaa";
    cout<<KMP(sup,sub)<<endl;
    return 0;
}
