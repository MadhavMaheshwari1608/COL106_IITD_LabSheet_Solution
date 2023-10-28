class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    double median=100001;
    bool m = true;
    MedianFinder() {
    }
    void addNum(int num) {
        if(median==100001){
            median = num;
        }
        else if(left.size()==0&&right.size()==0){
            if(num>median){
                right.push(num);
                left.push(median);
            }
            else{
                right.push(median);
                left.push(num);                
            }
            m = false;
            median = double(left.top()+right.top())/double(2);
        }
        else {
            if(num>right.top()){
                if(m){
                    left.push(median);
                    right.push(num);
                    median = double(left.top()+right.top())/double(2);
                    m = false;
                }
                else{
                    median = right.top();
                    m = true;
                    right.pop();
                    right.push(num);
                }
            }
            else if(num>median){
                if(m){
                    left.push(median);
                    right.push(num);
                    median = double(left.top()+right.top())/double(2);
                    m = false;
                }
                else{
                    median = num;
                    m= true;
                }
            }
            else if(num<left.top()){
                // cout << "hello: " << num << endl;
                if(m){
                    right.push(median);
                    left.push(num);
                    median = double(left.top()+right.top())/double(2);
                    m = false;
                }
                else{
                    if(num==3){
                        // cout << "m" << endl;
                    }
                    median = left.top();
                    m = true;
                    left.pop();
                    left.push(num);
                }                
            }
            else{
                if(m){
                    right.push(median);
                    left.push(num);
                    median = double(left.top()+right.top())/double(2);
                    m = false;
                }
                else{
                    median = num;
                    m = true;
                }                
            }
        }


    }
    
    double findMedian() {
        return median;
    }
};
