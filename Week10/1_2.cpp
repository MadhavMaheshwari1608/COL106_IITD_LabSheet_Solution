class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(inDegree[i]==0){
                q.push(i);
                numCourses--;
                ans.push_back(i);
            }
        }
        int x;
        int y;
        while(!q.empty()){
            x = q.front();
            // ans.push_back(x);
            q.pop();
            for(int i=0;i<v[x].size();i++){
                y = v[x][i];
                inDegree[y]--;
                if(inDegree[y]==0){
                    q.push(y);
                    ans.push_back(y);
                    numCourses--;
                }
            }
        }
        if(numCourses==0){
            return ans;
        }
        vector<int> k;
        return k;
    }
};