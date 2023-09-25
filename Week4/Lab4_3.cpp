#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string key;
    int word_count;
    Node * left;
    Node * right;
    Node(string k="",int count=0,Node * l=nullptr,Node* r=nullptr){
        key = k;
        word_count = count;
        left = l;
        right = r;
    }
};

class BST{
public:
    Node * root;
    BST(){
        root = new Node();
    }
    Node * search(string k){
        Node * temp = root;
        Node * result = new Node(k,-1,nullptr,nullptr);
        while(true){
            if(temp->key<k){
                if(temp->right==nullptr){
                    break;
                }
                else if(temp->right->key==k){
                    result = temp->right;
                    break;
                }
                temp=temp->right;
            }
            else{
                if(temp->left==nullptr){
                    break;
                }
                else if(temp->left->key==k){
                    result = temp->left;
                    break;
                }
                temp=temp->left;
            }
        }
        return result;
    }
    void insert_new(string k,int count){
        Node * temp_0 = search(k);
        if(temp_0->word_count!=-1){
            temp_0->word_count += count;
        }
        else{
            Node * temp = root;
            Node * result = new Node(k,count,nullptr,nullptr);
            while(true){
                if(temp->key<k){
                    if(temp->right==nullptr){
                        temp->right = result;
                        break;
                    }
                    temp=temp->right;
                }
                else{
                    if(temp->left==nullptr){
                        temp->left = result;
                        break;
                    }
                    temp=temp->left;
                }            
            }
        }
    }
};

int word_counter(string s){
    int x = 1;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            x++;
        }
    }
    return x;
}

void InorderTraversal(vector<string> &senders,vector<int> &count,Node * root){
    if(root==nullptr){
        return;
    }
    InorderTraversal(senders,count,root->left);
    senders.push_back(root->key);
    count.push_back(root->word_count);
    InorderTraversal(senders,count,root->right);
}

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        BST * bst = new BST();
        bst->root = new Node(senders[0],word_counter(messages[0]),nullptr,nullptr);
        for(int i=0;i<messages.size();i++){
            bst->insert_new(senders[i],word_counter(messages[i]));
        }
        vector<string> senders_distinct;
        vector<int> corresponding_wordcount;
        InorderTraversal(senders_distinct,corresponding_wordcount,bst->root);
        int max_wc = 0;
        int max_i = senders_distinct.size();
        for(int i=senders_distinct.size()-1;i>=0;i--){
            if(corresponding_wordcount[i]>max_wc){
                max_wc = corresponding_wordcount[i];
                max_i = i;
            }
        }
        return senders_distinct[max_i];
    }
};
