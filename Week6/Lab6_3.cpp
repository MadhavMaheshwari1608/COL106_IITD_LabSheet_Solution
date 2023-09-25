#include <stack>
void InorderTraversal(TreeNode*root,vector<int>*reqd_stack){
    stack<TreeNode*> s;
    TreeNode*temp = root;
    while(temp!=nullptr||!s.empty()){
        while(temp!=nullptr){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        reqd_stack->push_back(temp->val);
        temp = temp->right;
    }
}
bool checkBST(TreeNode* root,int &x) {
    vector<int> * reqd_stack = new vector<int>;
    InorderTraversal(root,reqd_stack);
    for(int i=0;i<reqd_stack->size()-1;i++){
        if(reqd_stack->at(i)>=reqd_stack->at(i+1)){
            return false;
        }
        else{
            x += reqd_stack->at(i);
        }
    }
    x += reqd_stack->at(reqd_stack->size()-1);
    return true;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return max(root->val,0);
        }
        stack<int> sum;
        stack<TreeNode*> s;
        TreeNode * temp = root;
        while(temp!=nullptr||!s.empty()){
            while(temp!=nullptr){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            int y = 0;
            bool check = checkBST(temp,y);
            if(!check){
                y=0;
            }
            sum.push(y);
            temp = temp->right;
        }
        int max_sum = 0;
        while(!sum.empty()){
            if(max_sum<sum.top()){
                max_sum = sum.top();
            }
            sum.pop();
        }
        return max_sum;
    }
};