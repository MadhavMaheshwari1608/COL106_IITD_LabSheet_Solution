#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node*next;
    Node*prev;
    Node(Node*nxt=nullptr,Node*prv=nullptr,int k=-1,int v=-1){
        next = nxt;
        prev = prv;
        key = k;
        value = v;
    }
};

class DoublyLinkedList{
public:
    Node * head = new Node();
    Node * tail = new Node();
    vector<Node *> * lru_hashtable = new vector<Node *>;
    DoublyLinkedList(){
        head->next = tail;
        tail->prev = head;
        for(int i=0;i<10001;i++){
            Node * temp = new Node(nullptr,nullptr,i,-1);
            lru_hashtable->push_back(temp);
        }
    }
    void insert_after_head(Node*n1){
        n1->next = head->next;
        head->next->prev = n1;
        head->next = n1;
        n1->prev = head;
    }
    void delete_node(Node*n1){
        Node * temp = n1;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        lru_hashtable->at(temp->key)->value = -1;
    }
    void insert_After(Node*n1,Node*pivot){
        n1->next = pivot->next;
        pivot->next->prev = n1;
        n1->prev = pivot;
        pivot->next = n1;
    }
    void delete_from_tail(){
        Node * temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        lru_hashtable->at(temp->key)->value = -1;
    }
};

// The functions get and put must each run in O(1) average time complexity.
class LRUCache {
public:
    int size=0;
    int count=0;
    Node*last;
    DoublyLinkedList * dl = new DoublyLinkedList();
//Initialize the LRU cache with positive size capacity.
    LRUCache(int capacity) {
        size = capacity;
    }
// Return the value of the key if the key exists, otherwise return -1.
    int get(int key) {       
        if(dl->lru_hashtable->at(key)->value==-1){
            return -1;
        }
        else{
            int x = dl->lru_hashtable->at(key)->value;
            dl->delete_node(dl->lru_hashtable->at(key));
            dl->lru_hashtable->at(key)->value = x;
            dl->insert_after_head(dl->lru_hashtable->at(key));
            return x;
        }
    }
// Update the value of the key if the key exists. 
// Otherwise, add the key-value pair to the cache. 
// If the number of keys exceeds the capacity from this operation, 
// evict the least recently used key.
    void put(int key, int value) {
        if(dl->lru_hashtable->at(key)->value==-1){
            dl->lru_hashtable->at(key)->value = value;
            if(count>=size){
                dl->delete_from_tail();
            }
            dl->insert_after_head(dl->lru_hashtable->at(key));
            count++;  
        }
        else{
            dl->lru_hashtable->at(key)->value = value;
            int x = get(key);
        }       
    }
};