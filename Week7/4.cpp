/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
TreeNode * Successor(TreeNode* root){
    TreeNode*temp = root->right;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            if(root->left==nullptr){
                return root->right;
            }
            else if(root->right==nullptr){
                return root->left;
            }
            else{
                TreeNode* s = Successor(root);
                if(root->right->val==s->val){
                    s->left = root->left; 
                    return s;
                }
                root->val = s->val;
                deleteNode(root->right,s->val);
                return root;
            }
        }
        TreeNode*parent = root;
        bool left_break = true;
        while(true){
            if(key<parent->val){
                if(parent->left==nullptr){
                    return root;
                }
                else if(parent->left->val==key){
                    break;
                }
                parent = parent->left;
            }
            else{
                if(parent->right==nullptr){
                    return root;
                }
                else if(parent->right->val==key){
                    left_break=false;
                    break;
                }
                parent = parent->right;
            }
        }
        if(left_break){
            if(parent->left->right==nullptr){
                parent->left = parent->left->left;
                return root;
            }
            else if(parent->left->left==nullptr){
                parent->left = parent->left->right;
                return root;
            }
            else{
                TreeNode* s = Successor(parent->left);
                if(parent->left->right->val==s->val){
                    s->left = parent->left->left; 
                    parent->left = s;
                }
                parent->left->val = s->val;
                deleteNode(parent->left->right,s->val);
                return root;
            }
        }
        else{
            if(parent->right->left==nullptr){
                parent->right = parent->right->right;
                return root;
            }
            else if(parent->right->right==nullptr){
                parent->right = parent->right->left;
                return root;
            }
            else{
                TreeNode* s = Successor(parent->right);
                if(parent->right->right->val==s->val){
                    s->left = parent->right->left; 
                    parent->right = s;
                }
                parent->right->val = s->val;
                deleteNode(parent->right->right,s->val);
                return root;
            }
        }
    }
};