class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> numbers;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                numbers.push_back(numbers[numbers.size()-1]+numbers[numbers.size()-2]);
            }
            else if(operations[i]=="D"){
                numbers.push_back(numbers[numbers.size()-1]*2);
            }
            else if(operations[i]=="C"){
                numbers.pop_back();
            }
            else{
                numbers.push_back(stoi(operations[i]));
            }
        }
        int ans = 0;
        for(int num:numbers){
            ans += num;
        }
        return ans;
    }
};