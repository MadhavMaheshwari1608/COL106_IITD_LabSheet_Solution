#include <iostream>
#include <vector>
using namespace std;
class Graph{
    public:
    vector<vector<int>> edges;
    vector<int> *low;
    vector<int> *index;
    vector<bool> *self;
    vector<bool> *inStack;
    int V;
    int tme = 0;
    Graph(int V){
        this->V=V;
        edges.resize(V);
        low = new vector<int>(V,-1);
        self = new vector<bool>(V,false);
        index = new vector<int>(V,-1);
        inStack = new vector<bool>(V,false);
    }
    void addEdge(int from,int to){
        edges[from].push_back(to);
        if(from==to){
            self->at(from)=true;
        }
    }
    void TarjanDFS(int i,int &ans,vector<int> &Stack){
        index->at(i) = tme;
        low->at(i) = tme;
        tme++;
        inStack->at(i)=true;
        Stack.push_back(i);
        for(int num:edges.at(i)){
            if(index->at(num)==-1){
                TarjanDFS(num,ans,Stack);
                low->at(i) = min(low->at(i),low->at(num));
            }
            else if(inStack->at(num)){
                low->at(i) = min(low->at(i),index->at(num));
            }
        }
        int cntr = 0;
        if(index->at(i)==low->at(i)){
            while(Stack.size()!=0&&Stack.back()!=i){
                cntr++;
                ans++;
                Stack.pop_back();
            }
            Stack.pop_back();
            if(cntr!=0){
                ans++;
            }
            else{
                if(self->at(i)){
                    ans++;
                }
            }
        }
    }
    int Tarjan(){
        int ans=0;
        vector<int> Stack;
        for(int i=0;i<V;i++){
            if(index->at(i)==-1){
                TarjanDFS(i,ans,Stack);
            }
        }
        return ans;
    }
};


int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int V;
        cin>>V;
        Graph * graph = new Graph(V);
        for(int i=0;i<V;i++){
            int x;
            cin>>x;
            graph->addEdge(i,(i+x+1)%V);
        }
        cout << graph->Tarjan() << endl;
        delete graph;
    }
	return 0;
}