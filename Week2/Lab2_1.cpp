#include <iostream>
#include <vector>
using namespace std;

class Node{
private:
int value;
public:
    Node * next;
    Node(Node*nxt=nullptr,int v=0){
        value = v;
        next = nxt;
    }
};
class SinglyLinkedList{
public:
    Node * head;
    SinglyLinkedList(Node*h){
        head = h;
    }
    Node * recent;
    void insert(Node*nxt){
        if(size==0){
            head->next = nxt;
        }
        else{
            recent->next = nxt;
        }
        recent = nxt;
        size++;
    }
private:
    int size = 0;
};

bool isCycle(Node*h){
    Node * tortoise = h;
    Node * hare = h;
    int count_when_same = 0;
    while((tortoise!=hare)||(count_when_same==0)){
        if(hare->next==nullptr){
            return false;
        }
        else if(hare->next->next==nullptr){
            return false;
        }
        hare = hare->next->next;
        tortoise = tortoise->next;
        if(tortoise==hare){
            count_when_same++;
        }
    }
    return true;
}


int main(){
    Node * n1 = new Node(nullptr,1);
    SinglyLinkedList * l = new SinglyLinkedList(n1);
    Node * n2 = new Node(nullptr,2);
    l->insert(n2);
    Node * n3 = new Node(nullptr,3);
    l->insert(n3);
// Comment and Uncomment the next line to see the desired results
    l->insert(n1);

    cout << isCycle(n1) << endl;

    return 0;
}