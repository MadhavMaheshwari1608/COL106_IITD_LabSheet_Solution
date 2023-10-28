class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size = 0;
    int index;
    KthLargest(int k, vector<int>& nums) {
        index = k;
        if(nums.size()>k){
            priority_queue<int> pq1;
            for(int num:nums){
                pq1.push(num);
            }
            for(int i=0;i<k;i++){
                pq.push(pq1.top());
                size++;
                pq1.pop();
            }
        }
        else{
            for(int num:nums){
                size++;
                pq.push(num);
            }            
        }
    }

    int add(int val) {
        if(size<index){
            pq.push(val);
            size++;
            return pq.top();
        }
        else{
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
    }
};
