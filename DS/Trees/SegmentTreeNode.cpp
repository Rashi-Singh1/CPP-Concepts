#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int start, end;
    ll sum;
    node *left, *right;
    node(int start, int end){
        this->start = start;
        this->end = end;
        left = NULL; 
        right = NULL;
        sum = 0;
    }
};

struct tree{
private:
    node* root;
    node* insert_util(vector<int>& A, int start, int end);
    void print_util(node* root);
    ll sum_util(node* root, int start, int end);
public:
    tree(){this->root = NULL;}
    void insert(vector<int>& A);
    void print();
    ll sum(int start, int end);
};

void tree::insert(vector<int>& A){
    this->root = insert_util(A, 0, A.size()-1);
}

node* tree::insert_util(vector<int>& A, int start, int end){
    if(start > end) return NULL;
    node* root = new node(start, end);
    int mid = (start + end)/2;
    if(end > start) root->left = insert_util(A, start, mid);
    root->right = insert_util(A, mid+1, end);
    if(start == end) root->sum = (ll)A[start];
    else {
        if(root->left) root->sum = root->left->sum;
        if(root->right) root->sum += root->right->sum;
    }
    return root;
}

void tree::print(){
    print_util(this->root);
}

void tree::print_util(node* root){
    if(root == NULL) return;
    cout<<root->start<<" "<<root->end<<" "<<root->sum<<endl;
    print_util(root->left);
    print_util(root->right);
}

ll tree::sum(int start, int end){
    return sum_util(this->root, start, end);
}

ll tree::sum_util(node* root, int start, int end){
    if(root == NULL) return 0;
    ll ans = 0;
    if(start <= root->start && root->end <= end) return root->sum;
    else if((root->start <= end && end <= root->end) || (root->start <= start && start <= root->end)) {
        ans+=sum_util(root->left, start, end);
        ans+=sum_util(root->right, start, end);
    } 
    return ans; 
}

int main(int argc, char const *argv[]){
    tree t;
    vector<int> A = {1,2,3,4,5,6,7,8,9};
    t.insert(A);
    t.print();
    cout<<t.sum(1,6)<<endl;
    return 0;
}
