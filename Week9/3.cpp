class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        if(node->val==0){
            Node*ans=new Node(0);
            return ans;
        }
        else if(node->neighbors.size()==0){
           Node*ans=new Node(node->val);
           return ans;
        }
        else{
            vector<vector<int>>v(101);
            vector<bool>b(101,false);
            Node*temp;
            stack<Node*> Stack;
            Stack.push(node);
            while(!Stack.empty()){
                temp = Stack.top();
                Stack.pop();
                if(!b[temp->val]){
                    b[temp->val] = true;
                    for(int i=0;i<temp->neighbors.size();i++){
                        v[temp->val].push_back(temp->neighbors[i]->val);
                        Stack.push(temp->neighbors[i]);
                    }
                }
            }
            Node*m = new Node();
            Node**g=new Node*[101];
            for(int i=1;i<101;i++){
                g[i]=new Node();
            }
            for(int i=1;i<101;i++){
                g[i]->val = i;
                for(int j=0;j<v[i].size();j++){
                    g[i]->neighbors.push_back(g[v[i][j]]);
                }
            }
            return g[node->val];
        }
    }
};