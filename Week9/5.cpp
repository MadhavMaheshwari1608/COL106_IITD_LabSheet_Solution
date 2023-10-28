using namespace std;
#include<vector>
#include<cmath>
class TrieNode{
    public:
    bool present = false;
    TrieNode*left_child;
    TrieNode*right_child;
    int b;
    TrieNode(int b,bool p=false){
        this->b = b;
        present = p;
        right_child=nullptr;
        left_child=nullptr;
    }
    void insert(int x){
        TrieNode*t=this;
        for(int i=0;i<b;i++){
            if(x/int(pow(2,b-i-1))==1){
                if(t->right_child==nullptr){
                    t->right_child = new TrieNode(b-i-1,true);
                }
                t = t->right_child;
            }
            else{
                if(t->left_child==nullptr){
                    t->left_child = new TrieNode(b-i-1,true);
                }
                t = t->left_child;
            }
            x = x%int(pow(2,b-1-i));
        }
    }
    };

int maxXOR(TrieNode*root,int b,int x){
    int ans = 0;
    TrieNode*t=root;
    for(int i=0;i<b;i++){
        if(x/int(pow(2,b-i-1))==0){
            if(t->right_child){
                ans += pow(2,b-i-1);
                t=t->right_child;
            }
            else if(t->left_child){
                t=t->left_child;
            }
            else{
                break;
            }
        }
        else{
            if(t->left_child){
                ans += pow(2,b-i-1);
                t=t->left_child;
            }
            else if(t->right_child){
                t=t->right_child;
            }
            else{
                break;
            }
        }
        x = x%int(pow(2,b-i-1));
    }   
    return ans;     
}
class Solution {
public:
    int max_bit(int a){
        return log2(a);
    }
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int maxi = 0;
        int ans = 0;
        for(int num:nums){
            maxi = max(maxi,num);
        }
        int b = max_bit(maxi)+1;
        TrieNode * root = new TrieNode(b);
        for(int num:nums){
            root->insert(num);
        }
        for(int num:nums){
            ans = max(ans,maxXOR(root,b,num));
        }
        return ans;
    }
};