class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> a;
        vector<int> b;
        for(int i=heights.size()-1;i>=0;i--){
            if(a.empty()){
                a.push_back(heights[i]);
                b.push_back(0);
            }
            else if(heights[i]<=a.back()){
                a.push_back(heights[i]);
                b.push_back(1);
            }
            else{
                int ans = 1;
                while(!a.empty()&&heights[i]>a.back()){
                    ans++;
                    a.pop_back();
                }
                if(a.empty()){
                    ans--;
                }
                a.push_back(heights[i]);
                b.push_back(ans);
            }
        }
        reverse(b.begin(),b.end());
        return b;
    }
};