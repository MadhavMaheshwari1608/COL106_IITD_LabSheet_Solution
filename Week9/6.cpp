#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class TrieNode{
    public:
    TrieNode*left;
    TrieNode*right;
    int count = 0;
    TrieNode(){
        left = nullptr;
        right = nullptr;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int x){
        TrieNode*t=root;
        for(int i=0;i<17;i++){
            t->count++;
            if(x/int(pow(2,16-i))==1){
                if(t->right==nullptr){
                    t->right = new TrieNode();
                }
                t = t->right;
            }
            else{
                if(t->left==nullptr){
                    t->left = new TrieNode();
                }
                t = t->left;
            }
            x = x%int(pow(2,16-i));
        }
        t->count++;
    }
    int XOR_greater_than_num(int x,int num){
        int c = 0;
        int value = 0;
        TrieNode*t=root;
        for(int i=0;i<17;i++){
            if(x/int(pow(2,16-i))==1){
                if(t->left){
                    if(value+int(pow(2,16-i))>num){
                        c += t->left->count;
                        if(t->right){
                            t=t->right;
                        }
                        else{
                            return c;
                        }
                    }
                    else{
                        value+=int(pow(2,16-i));
                        t=t->left;
                    }
                }
                else{
                    t = t->right;
                }
            }
            else{
                if(t->right){
                    if(value+int(pow(2,16-i))>num){
                        c += t->right->count;
                        if(t->left){
                            t=t->left;
                        }
                        else{
                            return c;
                        }
                    }
                    else{
                        value+=int(pow(2,16-i));
                        t=t->right;
                    }
                }
                else{
                    t = t->left;
                }
            }
            x = x%int(pow(2,16-i));
        }
        return c;        
    }
};



class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int g_than_high = 0;
        int g_than_equal_low = 0;
        Trie*T=new Trie();
        for(int num:nums){
            T->insert(num);
        }
        for(int num:nums){
            g_than_high+=T->XOR_greater_than_num(num,high);
        }
        for(int num:nums){
            g_than_equal_low+=T->XOR_greater_than_num(num,low-1);
        }
        return (g_than_equal_low-g_than_high)/2;        
    }
};

int main(){

    return 0;
}