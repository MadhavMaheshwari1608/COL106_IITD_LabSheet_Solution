class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> w(n,0);
        for(int i=0;i<trust.size();i++){
            w[trust[i][1]-1]++;
            w[trust[i][0]-1]--;
        }
        for(int i=0;i<n;i++){
            if(w[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};