#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> &v1,vector<int> &v2,int &ans){
        if(v1.size()==0){
            return v2;
        }
        else if(v2.size()==0){
            return v1;
        }
        else{
            vector<int> v3;
            int i=0;
            int j=0;
            int x=0;
            int y=0;
            while(x<v1.size()){
                while(y<v2.size()){
                    if(v1[x]/2>v2[y]){
                        ans += (v1.size()-x);
                        y++;
                    }
                    else if(v1[x]/2==v2[y]&&v1[x]%2==1){
                        ans += (v1.size()-x);
                        y++;
                    }
                    else{
                        break;
                    }
                }
                x++;
            }
            while(i<v1.size()&&j<v2.size()){
                if(v1[i]>v2[j]){
                    v3.push_back(v2[j]);
                    j++;
                }
                else{
                    v3.push_back(v1[i]);
                    i++;
                }
            }
            if(i==v1.size()){
                for(;j<v2.size();j++){
                    v3.push_back(v2[j]);
                }
            }
            else{
                for(;i<v1.size();i++){
                    v3.push_back(v1[i]);
                }                
            }
            return v3;
        }
    }

    vector<int> merge_sort(vector<int> &nums,int &ans){
        if(nums.size()<2){
            return nums;
        }
        else if(nums.size()==2){
            if(nums[0]/2>nums[1]){
                ans++;
            }
            else if(nums[0]/2==nums[1]&&nums[0]%2==1){
                ans++;
            }
            if(nums[0]>nums[1]){
                int t = nums[0];
                nums[0] = nums[1];
                nums[1] = t;
            }
            return nums;
        }
        else{
            vector<int> a,b;
            for(int i=0;i<nums.size()/2;i++){
                a.push_back(nums[i]);
            }
            for(int i=nums.size()/2;i<nums.size();i++){
                b.push_back(nums[i]);
            }
            vector<int> a1,a2;
            a1 = merge_sort(a,ans);
            a2 = merge_sort(b,ans);
            return merge(a1,a2,ans);
        }
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        vector<int> v = merge_sort(nums,ans);
        return ans;
    }
};
int main(){
    Solution solution;
    vector<int> v = {16,7,3,1};
    int ans = solution.reversePairs(v);
    cout << ans << endl;
    return 0;
}