#include <iostream>
#include <stack>
using namespace std;

int * max_area(int n, int * numbers){
    int * temp = new int[n];
    stack<int> stack_a;
    stack<int> stack_b;
    stack_a.push(numbers[n-1]);
    stack_b.push(0);
    temp[n-1] = 0;
    for(int i=1;i<n;i++){
        int l = 0;
        while(true){
            if(stack_a.empty()){
                stack_a.push(numbers[n-i-1]);
                stack_b.push(i);
                temp[n-i-1] = i;
                break;
            }
            else if(numbers[n-i-1]<=stack_a.top()){
                l += 1 + stack_b.top();
                stack_b.pop();
                stack_a.pop();
            }
            else{
                stack_a.push(numbers[n-i-1]);
                stack_b.push(l);
                temp[n-i-1] = l;
                break;
            }
        }
    }
    return temp;
}

int main() {
    int n;
    cin>>n;
    int * numbers = new int[n];
    int * numbers_reverse = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        numbers[i] = temp;
        numbers_reverse[n-i-1] = temp;
    }
    int * answer = max_area(n,numbers);
    // for(int i=0;i<n;i++){
    //     cout << answer[i] << " ";
    // }
    // cout << endl;
    int * temp_answer_reverse = max_area(n,numbers_reverse);
    int max = 0;
    int x;
    for(int i=0;i<n;i++){
       x = (answer[i] + temp_answer_reverse[n-i-1] + 1)*numbers[i];
       if(x>max){
        max = x;
       }
    }
    cout << max << endl;
    return 0;
}