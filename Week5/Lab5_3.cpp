#include <stack>

void InorderTraversal(TreeNode* root,stack<int> * reqd_stack){
    if(root==nullptr){
        return;
    }
    else{
        InorderTraversal(root->right,reqd_stack);
        reqd_stack->push(root->val);
        InorderTraversal(root->left,reqd_stack);        
    }
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<int> * reqd_stack = new stack<int>;
        InorderTraversal(root,reqd_stack);
        for(int i=0;i<k-1;i++){
            reqd_stack->pop();
        }
        return reqd_stack->top();
    }
};