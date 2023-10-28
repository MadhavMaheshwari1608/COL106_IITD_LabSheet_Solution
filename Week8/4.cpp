#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    // Write your code here. 
    if(k==1){
        return kArrays[0];
    }
    else{
        vector<int> v;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            if(kArrays[i].size()!=0){
                pq.push(make_pair(kArrays[i].back(),i));
                kArrays[i].pop_back();
            }
        }
        while(!pq.empty()){
            v.push_back(pq.top().first);
            if(kArrays[pq.top().second].size()!=0){
                pq.push(make_pair(kArrays[pq.top().second].back(),pq.top().second));
                kArrays[pq.top().second].pop_back();
            }
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
}