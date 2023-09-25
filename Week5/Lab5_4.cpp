#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node*parent;
    Node(int v=1,Node*p=nullptr){
        val = v;
        parent = p;
    }
};
class BST{
public:
    Node*root;
    vector<Node*> all_nodes;
    BST(){
        root = new Node();
        all_nodes.push_back(root);
    }
    void insert_node(int x,int parent){
        Node * newNode = new Node(x);
        newNode->parent = all_nodes.at(parent-1);
        all_nodes.push_back(newNode);
    }
};
int lca(BST*bst,int x,int y){
    vector<int> path_x_to_root;
    vector<int> path_y_to_root;
    if(x==1){
        return 1;
    }
    else if(y==1){
        return 1;
    }
    else if(x==y){
        return x;
    }
    else{
        Node * temp_x = bst->all_nodes[x-1]->parent;
        path_x_to_root.push_back(x);
        while(true){
            if(temp_x->val==y){
                return y;
            }
            path_x_to_root.push_back(temp_x->val);
            if(temp_x==bst->root){
                break;
            }
            temp_x = bst->all_nodes[temp_x->val-1]->parent;
        }
        Node * temp_y = bst->all_nodes[y-1]->parent;
        path_y_to_root.push_back(y);
        while(true){
            if(temp_y->val==x){
                return x;
            }
            path_y_to_root.push_back(temp_y->val);
            if(temp_y==bst->root){
                break;
            }
            temp_y = bst->all_nodes[temp_y->val-1]->parent;
        }
        int x_itr = path_x_to_root.size()-1;
        int y_itr = path_y_to_root.size()-1;
        while(true){
            if(path_x_to_root[x_itr]!=path_y_to_root[y_itr]){
                break;
            }
            else{
                x_itr--;
                y_itr--;                
            }
        }
        return path_x_to_root[x_itr+1];
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    BST * bst = new BST();
    for(int i=2;i<n+1;i++){
        int temp;
        cin >> temp;
        bst->insert_node(i,temp);
    }
    for(int i=0;i<q;i++){
        int i1,i2;
        cin >> i1 >> i2;
        cout << lca(bst,i1,i2) << endl;
    }
    return 0;
}