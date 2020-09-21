#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//unweighted
class graph{
    unordered_map<int, vector<int> > s;                     //for weighted make it unordered_map<int, pair<int, int> >s
    void dfs_util(int node, unordered_set<int>& done);
public:
    void addEdge(int ind1, int ind2);
    void batchAddEdge(vector<pair<int, int> >& A);
    void bfs();
    void dfs();
    void print();
};

void graph::addEdge(int ind1, int ind2) {
    s[ind1].push_back(ind2);                            //for undirected, also s[ind2].push_back(ind1);
}
void graph::batchAddEdge(vector<pair<int, int> >& A){
    for(auto x : A) this->addEdge(x.first, x.second);
}
void graph::bfs() {
    queue<int> q;
    unordered_set<int> done;
    for(auto x : s){
        if(done.count(x.first) == 0){
            q.push(x.first);
            done.insert(x.first);
            while(!q.empty()){
                auto y = q.front();
                q.pop();
                cout << y << " ";
                if(s.count(y) > 0){
                    for(auto z : s[y]){
                        if(done.count(z) == 0){
                            q.push(z);
                            done.insert(z);
                        }
                    }
                }
            }
        }
    }
    cout<<endl;
}
void graph::dfs(){
    
}
void graph::dfs_util(int node, unordered_set<int>& done){

}
void graph::print() {
    for(auto x : s){
        cout << x.first << ": ";
        for(auto y : x.second) cout << y << " "; cout<<endl;
    }
}


int main(int argc, char const *argv[]){
    graph g;
    vector<pair<int, int> > A;
    for(int i = 0 ; i < 10 ; i++) A.push_back({i, 2*i});
    for(int i = 0 ; i < 10 ; i++) A.push_back({i, i+1});
    g.batchAddEdge(A);
    g.print();
    g.bfs();
    g.dfs();
    return 0;
}
