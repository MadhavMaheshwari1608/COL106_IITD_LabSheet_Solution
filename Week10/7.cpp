class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        vector<array<int, 4>> rects(61, {INT_MAX, INT_MAX, INT_MIN, INT_MIN});
        vector<vector<int>> v(61);
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                int col = grid[i][j];
                rects[col][0] = min(rects[col][0], i);
                rects[col][1] = min(rects[col][1], j);
                rects[col][2] = max(rects[col][2], i);
                rects[col][3] = max(rects[col][3], j);
            }
        vector<int> Indegree(61,0);
        for (auto col = 0; col <= 60; ++col)
            for (int i = rects[col][0]; i <= rects[col][2]; ++i)
                for (int j = rects[col][1]; j <= rects[col][3]; ++j)
                    if (grid[i][j] != col){
                        v[col].push_back(grid[i][j]);
                        Indegree[grid[i][j]]++;
                    }
        queue<int> q;
        int numCourses = 61;
        for(int i=0;i<v.size();i++){
            if(Indegree[i]==0){
                numCourses--;
                q.push(i);
            }
        }
        int x;
        while(!q.empty()){
            x = q.front();
            q.pop();
            for(int i:v[x]){
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