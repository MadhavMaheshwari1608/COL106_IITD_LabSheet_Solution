void tree_modifier(node*root,vector<node*> &path_from_root_to_val){
    node*temp4;
    node*temp2;
    for(int i=0;i<path_from_root_to_val.size();i++){
        temp2 = path_from_root_to_val[path_from_root_to_val.size()-1-i];
        if(abs((temp2->left->ht)-(temp2->right->ht))>=2){
            temp4 = path_from_root_to_val[path_from_root_to_val.size()-i];
            break;
        }
    }
    if(temp2->left->ht>temp2->right->ht){   //left
        if(temp2->left==temp4){ //left-left
            temp2->left = temp2->left->right;
            temp4->right = temp2;
        }
        else{   //left-right
            temp2->left = temp2->left->right->right;
            node*temp3 = temp4->right;
            temp4->right = temp4->right->left;
            temp3->left = temp4;
        }
    }
    else{   //right
        if(temp2->left==temp4){ //right-left
            temp2->right = temp2->right->left->left;
            node*temp3 = temp4->left;
            temp4->left = temp4->left->right;
            temp3->right = temp4;
        }
        else{   //rigth-right
            temp2->right = temp2->right->left;
            temp4->left = temp2;
        }
    }
}
    

node * insert(node * root,int val)
{
    if((root->left==NULL||root->left==nullptr)&&(root->right==NULL||root->right==nullptr)){
        root->ht=0;
    }
    node*temp;
    vector<node*> path_from_root_to_val;
    node * newNode = new node();
    newNode->val = val;
    newNode->ht = 0;
    while(true){
        path_from_root_to_val.push_back(temp);
        if(val<temp->val){
            if(temp->left==NULL||temp->left==nullptr){
                if(temp->right==NULL||temp->right==nullptr){
                    temp->ht=1;
                }
                temp->left = newNode;
                break;
            }
            else{
                if(temp->right==NULL||temp->right==nullptr){
                    temp->ht++;
                }
                else if(temp->right->ht<=temp->left->ht){
                    temp->ht++;
                }
                temp = temp->left;
            }
        }
        else{
            if(temp->right==NULL||temp->right==nullptr){
                if(temp->left==NULL||temp->left==nullptr){
                    temp->ht=1;
                }
                temp->right = newNode;
                break;
            }
            else{
                if(temp->left==NULL||temp->left==nullptr){
                    temp->ht++;
                }
                else if(temp->left->ht<=temp->right->ht){
                    temp->ht++;
                }
                temp = temp->right;
            }
        }
    }
    tree_modifier(root,path_from_root_to_val);  
    return root;
}