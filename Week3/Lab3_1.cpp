#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> * stack_main;
    stack<int> * stack_2;
    MyQueue() {
        stack<int> * stack_main = new stack<int>;
        stack<int> * stack_2 = new stack<int>; 
    }
    void push(int x) {
        if(stack_main->empty()){
            stack_main->push(x);
        }
        else{
            while(!(stack_main->empty())){
                stack_2->push(stack_main->top());
                stack_main->pop();
            }
            stack_2->push(x);
            while(!(stack_2->empty())){
                stack_main->push(stack_2->top());
                stack_2->pop();
            }
        }
    }
    
    int pop() {
        int x = stack_main->top();
        stack_main->pop();
        return x;
    }
    
    int peek() {
        return stack_main->top();
    }
    
    bool empty() {
        return stack_main->empty();
    }
};

int main(){   
    return 0;
}