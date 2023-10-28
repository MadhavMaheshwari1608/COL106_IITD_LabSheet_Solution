class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        vector<int> v;
        vector<int> ans;
        for(int num:nums){
            if(umap.find(num)==umap.end()){
                v.push_back(num);
                umap[num] = 1;
            }
            else{
                umap[num] += 1;
            }
        }
        priority_queue<pair<int,int>> pq;
        for(int n:v){
            pq.push(make_pair(umap[n],n));
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};