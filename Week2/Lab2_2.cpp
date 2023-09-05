#include <iostream>
#include <stack>
using namespace std;

stack<int> answers(int n,int *numbers){
    stack<int> temp;
    stack<int> stack_a;
    stack_a.push(numbers[n-1]);
    temp.push(-1);
    for(int i=1;i<n;i++){
        while(true){
            if(stack_a.empty()){
                temp.push(-1);
                stack_a.push(numbers[n-i-1]);
                break;
            }
            else if(stack_a.top()>numbers[n-i-1]){
                temp.push(stack_a.top());
                stack_a.push(numbers[n-i-1]);
                break;
            }
            else{
                stack_a.pop();
            }
        }
    }
    return temp;
}

int main() {
    int n;
    cin>>n;
    int * numbers = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        numbers[i] = temp;
    }
    stack<int> temp = answers(n,numbers);
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    return 0;
}