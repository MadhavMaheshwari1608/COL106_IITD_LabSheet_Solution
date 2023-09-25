void InorderTraversal(Node*root,vector<int>*reqd_stack){
    if(root==nullptr||root==NULL){
        return;
    }
    else{
        InorderTraversal(root->left,reqd_stack);
        reqd_stack->push_back(root->data);
        InorderTraversal(root->right,reqd_stack);
    }
}
	bool checkBST(Node* root) {
		vector<int> * reqd_stack = new vector<int>;
        InorderTraversal(root,reqd_stack);
        for(int i=0;i<reqd_stack->size()-1;i++){
            if(reqd_stack->at(i)>=reqd_stack->at(i+1)){
                return false;
            }
        }
        return true;
	}