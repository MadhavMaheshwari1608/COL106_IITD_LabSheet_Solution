class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            Indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(Indegree[i]==0){
                numCourses--;
                q.push(i);
            }
        }
        int x;
        while(!q.empty()){
            x = q.front();
            q.pop();
            for(int i:adj[x]){
                Indegree[i]--;
                if(Indegree[i]==0){
                    numCourses--;
                    q.push(i);
                }
            }
        }
        if(numCourses==0){
            return true;
        }
        else{
            return false;
        }
    }

};