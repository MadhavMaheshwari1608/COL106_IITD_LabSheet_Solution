class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> v(score.size());
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push(make_pair(score[i],i));
        }
        for(int i=0;i<score.size();i++){
            if(i==0){
                v[pq.top().second] = "Gold Medal";
            }
            else if(i==1){
                v[pq.top().second] = "Silver Medal";
            }
            else if(i==2){
                v[pq.top().second] = "Bronze Medal";
            }
            else{
                v[pq.top().second] = to_string(i+1);
            }
            pq.pop();
        }        
        return v;
    }
};