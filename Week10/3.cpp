
class Solution{   
    class Node{
        public:
        int index;
        int dist;
        Node(int i,int d){
            index = i;
            dist = d;
        }
    };
    class Compare{
        public:
        bool operator()(Node a,Node b){
            return a.dist>b.dist;
        }
    };
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        vector<bool> visited(V,false);
        vector<int> distance(V,INT_MAX);
        priority_queue<Node,vector<Node>,Compare> pq;
        pq.push(Node(S,0));
        distance[S]=0;
        while(!pq.empty()){
            Node temp = pq.top();
            pq.pop();
            if(visited[temp.index]){
                continue;
            }
            visited[temp.index]=true;
            for(int i=0;i<adj[temp.index].size();i++){
                int alt = adj[temp.index][i][1]+distance[temp.index];
                if(alt<distance[adj[temp.index][i][0]]){
                    distance[adj[temp.index][i][0]] = alt;
                }
                pq.push(Node(adj[temp.index][i][0],distance[adj[temp.index][i][0]]));
            }
        }
        return distance;
    }
};
