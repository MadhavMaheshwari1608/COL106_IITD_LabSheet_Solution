class Edge{
    public:
    pair<int,int> to;
    int weight;
    Edge(int i,int j,int w){
        to.first = i;
        to.second = j;
        weight = w;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = (grid.size());
        int c = grid[0].size();
        vector<vector<Edge>> e(r*c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0){
                    if(i+1<r){
                        e[i+j*r].push_back(Edge(i+1,j,max(grid[i][j],grid[i+1][j])));
                    }
                }
                else if(i==r-1){
                    e[i+j*r].push_back(Edge(i-1,j,max(grid[i][j],grid[i-1][j])));
                }
                else{
                    e[i+j*r].push_back(Edge(i-1,j,max(grid[i][j],grid[i-1][j])));  
                    e[i+j*r].push_back(Edge(i+1,j,max(grid[i][j],grid[i+1][j]))); 
                }
                if(j==0){
                    if(j+1<c){
                        e[i+j*r].push_back(Edge(i,j+1,max(grid[i][j],grid[i][j+1])));               
                    }
                    }
                else if(j==c-1){
                    e[i+j*r].push_back(Edge(i,j-1,max(grid[i][j],grid[i][j-1])));                    
                }
                else{
                    e[i+j*r].push_back(Edge(i,j+1,max(grid[i][j],grid[i][j+1])));   
                    e[i+j*r].push_back(Edge(i,j-1,max(grid[i][j],grid[i][j-1])));              
                }
            }
        } 
        vector<int> distance(r*c,INT_MAX);    
        vector<bool> visited(r*c,false);
        distance[0]=0;    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // cout << grid[0][0] << endl;
        pq.push(make_pair(grid[0][0],0));
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(visited[temp.second]){
                continue;
            }
            visited[temp.second]=true;
            for(Edge edge:e[temp.second]){
                int alt = max(distance[temp.second],edge.weight);
                if(alt<distance[edge.to.first+edge.to.second*r]){
                    distance[edge.to.first+edge.to.second*r] = alt;
                   // cout << "hello: " << edge.to.first<<","<<edge.to.second << " " << alt << endl;
                    pq.push(make_pair(alt,edge.to.first+edge.to.second*r));
                }
            }
        }
        return distance[r*c-1];        
    }
};