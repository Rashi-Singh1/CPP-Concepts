/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode* t; 
vector<int> Inorder_S(TreeNode* A) {
    stack<t> s;
    vector<int> ans;
    while(A){
        s.push(A);
        if(A->left) A = A->left;
        else{
            if(s.empty()) return ans;
            while(!s.empty()){
                ans.push_back(s.top()->val);
                A = s.top()->right;
                s.pop();
                if(A) break;
            }
        }
    }
    return ans;
}

vector<int> Preorder_S(TreeNode* A) {
    stack<t> s;
    vector<int> ans;
    while(A){
        s.push(A);
        ans.push_back(A->val);
        if(A->left) A = A->left;
        else{
            if(s.empty()) return ans;
            while(!s.empty()){
                A = s.top()->right;
                s.pop();
                if(A) break;
            }
        }
    }
    return ans;
}

//do CRL and reverse at the end
vector<int> Postorder_S(TreeNode* A) {
    vector<int> ans;
    stack<t> s;
    while(A){
        s.push(A);
        ans.push_back(A->val);
        if(A->right) A = A->right;
        else{
            if(s.empty()) return ans;
            while(!s.empty()){
                A = s.top()->left;
                s.pop();
                if(A) break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Logic:
/*
* if a node (cur) has left, then there are two possibilities:
* make pred as left of cur and go as right as possible to see whether back pointer is set or not
* 1) back pointer is set already means - left subtree of cur is covered, therefore, remove the back pointer and move cur to cur->right to cover right subtree
* 2) back pointer is set already means - left subtree is to be covered, therefore set the back pointer and move cur to left, to cover left subtree( not that our way back is set, cur can be moved)

* if cur does not have left, simply move to right subtree
*/
vector<int> Solution::Inorder_M(TreeNode* A) {
    vector<int> ans;
    t prev = NULL; t cur = A;
    while(cur){
        if(cur->left == NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }else{
            prev = cur->left;
            while(prev->right && prev->right!= cur) prev = prev->right;
            if(prev->right == NULL) {                   //this part occurs before covering left subtree
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;                     //this part occurs after left subtree, therefore for inorder, root value pushed after left subtree
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return ans;
}

vector<int> Preorder_M(TreeNode* A) {
    vector<int> ans;
    t cur = A;
    while(cur){
        if(cur->left == NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }else{
            t prev = cur->left;
            while(prev->right && prev->right!=cur) prev = prev->right;
            if(prev->right == NULL) {                //this part occurs before covering left subtree, therefore for preorder, root value pushed before left subtree
                prev->right = cur;
                ans.push_back(cur->val);
                cur = cur->left;
            }
            else{                                   //this part occurs after left subtree      
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}

//do morris for CRL and reverse ans at the end
vector<int> Postorder_M(TreeNode* A) {
    vector<int> ans;
    t cur = A;
    while(cur){
        if(cur->right == NULL){
            ans.push_back(cur->val);
            cur = cur->left;
        }else{
            t prev = cur->right;
            while(prev->left && prev->left!=cur) prev = prev->left;
            if(prev->left == NULL) {
                prev->left = cur;
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                prev->left = NULL;
                cur = cur->left;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}