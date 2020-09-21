#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

string longestPalindrome(string A) {
    if(A.size() < 2) return A;
    string B = "#";
    for(ll i = 0 ; i < A.size(); i++){
        B.push_back(A[i]);
        B.push_back('#');
    }
    ll P[(ll)B.size()] = {0};
    ll center = 0, right = 0;
    for(ll i = 1; i < B.size(); i++){
        ll mirror = 2*center - i;
        if(i < right) P[i] = min(P[mirror], right-i);
        while(i-(P[i] + 1) >= 0 && B[i+P[i]+1] == B[i-(1+P[i])]) P[i]++;
        // for(ll j = 0 ; j < B.size(); j++) cout<<P[j]<<" "; cout<<endl;
        if(i + P[i] > right){
            center = i;
            right = center + P[i];
        }
        // cout<<center<<" "<<i<<" "<<right<<endl;
    }
    // for(ll j = 0 ; j < B.size(); j++) cout<<j<<" "; cout<<endl;
    for(ll j = 0 ; j < B.size(); j++) cout<<B[j]<<" "; cout<<endl;
    for(ll j = 0 ; j < B.size(); j++) cout<<P[j]<<" "; cout<<endl;

    return B;
}


int main(int argc, char const *argv[])
{
    cout<<longestPalindrome("aaaaabaaabababa")<<endl;
    return 0;
}
