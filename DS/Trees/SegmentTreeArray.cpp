#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct tree{
    vector<ll> A;
    tree(){}
    void insert(vector<int>& num, int index, int start, int end);
    void update(vector<int>& num, int index, int value, int start, int end, int curIndex);
    ll query(vector<int>& num, int start, int end, int curStart, int curEnd, int curIndex);
};

void tree::insert(vector<int>& num, int index, int start, int end){
    if(start > end) return;
    while(A.size() <= index) A.push_back(0);
    if(end > start) this->insert(num, 2*index+1, start, (start+end)/2);
    this->insert(num, 2*index+2, (start+end)/2 + 1, end);
    if(start == end) A[index] = num[start];
    else A[index] = (ll)A[2*index+1] + (ll)A[2*index+2];
}

void tree::update(vector<int>& num, int index, int value, int start, int end, int curIndex){
    if(start > end) return;
    if(start == end && end == index) this->A[curIndex] = (ll)value;
    else if(start <= index && index <= end){
        update(num, index, value, start, (start+end)/2, 2*curIndex+1);
        update(num, index, value, (start+end)/2+1, end, 2*curIndex+2);
        this->A[curIndex] = (ll)A[2*curIndex+1] + (ll)A[2*curIndex+2];
    }
    else return;
}

ll tree::query(vector<int>& num, int start, int end, int curStart, int curEnd, int curIndex){
    if(start > end || curStart > curEnd) return 0;
    if(start <= curStart && curEnd <= end) return A[curIndex];
    else if((curStart <= start && start <= curEnd) || (curStart <= end && end <= curEnd)){
        ll ans = query(num, start, end, curStart, (curStart + curEnd)/2, 2*curIndex + 1);
        ans += query(num, start, end, (curStart + curEnd)/2+1, curEnd, 2*curIndex + 2);
        return ans;
    }
    else return 0;
}

int main(int argc, char const *argv[]){
    tree t;
    vector<int> A = {1,2,3,4,5,6,7,8,9};
    t.insert(A, 0, 0, A.size()-1);
    for(auto x : t.A) cout<<x<<" "; cout<<endl;
    t.update(A, 6, 10, 0, A.size()-1, 0);
    for(auto x : t.A) cout<<x<<" "; cout<<endl;
    cout<<t.query(A, 1, 5, 0, A.size()-1, 0);
    return 0;
}
