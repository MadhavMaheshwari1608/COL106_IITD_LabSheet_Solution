#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class CQ{
public:
    int size = 0;
    int recent = -1;
    int * arr = new int[5];    
    void insert(int x){
        if(size==5){
            cout << "Queue Overflow" << endl;
            return;
        }
        int t = (recent+1)%5;
        arr[t] = x;
        recent++;
        size++;
    }
    void del(){
        if(size==0){
            cout << "Queue Underflow" << endl;
            return;            
        }
        size--;
    }
    void display(){
        if(size==0){
            cout << NULL << endl;
            return;
        }
        for(int i=recent+1-size;i<recent;i++){
            cout << arr[i%5] << " ";
        }
        cout << arr[recent%5] << endl;
    }
};



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    CQ cq;
    while(true){
        int c;
        cin >> c;
        if(c==1){
            int x;
            cin >> x;
            cq.insert(x);
        }
        else if(c==2){
            cq.del();
        }
        else if(c==3){
            cq.display();
        }
        else{
            break;
        }
    }   
    return 0;
}
