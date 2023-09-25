class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* left;
        TreeNode* right;
        if(preorder.size()==0){
            return nullptr;
        }
        else if(preorder.size()==1){
            left = nullptr;
            right = nullptr;
        }
        else if(preorder.size()==2){
            if(inorder[0]==preorder[0]){
                left = nullptr;
                right = new TreeNode(inorder[1]);
            }
            else{
                right = nullptr;
                left = new TreeNode(inorder[0]);
            }
        }
        else{
            vector<int> inorder_left;
            vector<int> inorder_right;
            vector<int> preorder_left;
            vector<int> preorder_right;
            int index;
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==preorder[0]){
                    index = i;
                    break;
                }
            }
            for(int i=0;i<inorder.size();i++){
                if(i<index){
                    inorder_left.push_back(inorder[i]);
                    preorder_left.push_back(preorder[1+i]);
                }
                else if(i>index){
                    inorder_right.push_back(inorder[i]);
                    preorder_right.push_back(preorder[i]);
                }
            }
            left = buildTree(preorder_left,inorder_left);
            right = buildTree(preorder_right,inorder_right);
        }
        TreeNode* bst = new TreeNode(preorder[0],left,right);
        return bst;
    }
};