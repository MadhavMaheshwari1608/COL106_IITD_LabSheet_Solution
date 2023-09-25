Node * find(Node*root,int v1){
    if(root == NULL){
        return nullptr;
    }
    else if(root->data==v1){
        return root;
    }
    else{
        Node * temp = root;
        while(true){
            if(v1<=temp->data){
                temp = temp->left;
                if(temp==NULL){
                    return NULL;
                }
                else if(temp->data==v1){
                    return temp;
                }
            }
            else{
                temp = temp->right;
                if(temp==NULL){
                    return NULL;
                }
                else if(temp->data==v1){
                    return temp;
                }                
            }
        }
    }
}
Node * find_parent(Node*root,int v1){
    if(root->data==v1){
        return root;
    }
    else{
        Node * temp = root;
        while(true){
            if(v1<=temp->data){
                if(temp->left->data==v1){
                    return temp;
                }
                temp = temp->left;
            }
            else{
                if(temp->right->data==v1){
                    return temp;
                }    
                temp = temp->right;            
            }
        }
    }
}  
 
    Node *lca(Node *root, int v1,int v2) {
        Node * n1 = find(root,v1);
        Node * n2 = find(root,v2);
        if(root->data==v1){
            return root;
        }
        if(root->data==v2){
            return root;
        }
		if(v1==v2){
            return n1;
        }
        if(find(n2,v1)!=NULL){
            return n2;
        }
        if(find(n1,v2)!=NULL){
            return n1;
        }
        else{
            Node * parent_v1 = find_parent(root, v1);
            if(parent_v1==root){
                return root;
            }
            return lca(root,parent_v1->data,v2);
        }
    }