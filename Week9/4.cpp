class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> b(rooms.size(),false);
        stack<int> s;
        s.push(0);
        int temp;
        while(!s.empty()){
            temp = s.top();
            s.pop();
            if(b[temp]==false){
                b[temp] = true;
                for(int i=0;i<rooms[temp].size();i++){
                    s.push(rooms[temp][i]);
                }
            }
        }
        for(bool w:b){
            if(w==false){
                return false;
            }
        }
        return true;
    }
};