#include <bits/stdc++.h> 

int par(int x){
    return (x-1)/2;
}
int left_child(int x){
    return 2*x+1;
}
int right_child(int x){
    return 2*x+2;
}

class Heap{
public:
    vector<int> vec;
    int size = 0;
    void insert(int v){
        if(size==0){
            vec.push_back(v);
        }
        else{
            vec.push_back(v);
            int x = size;
            while(vec[par(x)]>vec[x]&&x!=0){
                int t=vec[par(x)];
                vec[par(x)] = vec[x];
                vec[x] = t;
                x = par(x);
            }
        }
        size++;
    }
    int remove(){
        if(size==1){
            size--;
            int x = vec[0];
            vec.pop_back();
            return x;
        }
        else{
            int ans  = vec[0];
            vec[0] = vec[size-1];
            vec.pop_back();
            size--;
            int x = 0;
            if(right_child(x)>=size){
                // cout << x << " " << size << endl;
                if(left_child(x)<size&&vec[left_child(x)]<vec[x]){
                    int t=vec[left_child(x)];
                    vec[left_child(x)] = vec[x];
                    vec[x] = t;
                    x = left_child(x);                
                }
                // cout << ans << endl;
                return ans;                
            }
            while(vec[left_child(x)]<vec[x]||vec[right_child(x)]<vec[x]){
                if(vec[left_child(x)]<vec[right_child(x)]){
                    int t=vec[left_child(x)];
                    vec[left_child(x)] = vec[x];
                    vec[x] = t;
                    x = left_child(x);
                }
                else{
                    int t=vec[right_child(x)];
                    vec[right_child(x)] = vec[x];
                    vec[x] = t;
                    x = right_child(x);
                }
                if(right_child(x)>=size){
                    break;
                }
            }
            if(left_child(x)<size&&vec[left_child(x)]<vec[x]){
                int t=vec[left_child(x)];
                vec[left_child(x)] = vec[x];
                vec[x] = t;
                x = left_child(x);                
            }
            return ans;
        }
    }
};



vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> v;
    Heap hp;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            hp.insert(q[i][1]);
        }
        else{
            v.push_back(hp.remove());
        }
    }
    return v;
}