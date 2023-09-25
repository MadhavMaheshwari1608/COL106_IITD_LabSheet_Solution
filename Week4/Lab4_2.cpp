#include <vector>
#include<iostream>
using namespace std;


long countInversions(vector<int> *arr) {
    long x;
    if(arr->size()==1){
        x = 0;
    }
    else if(arr->size()==2){
        if(arr->at(0)>arr->at(1)){
            x = 1;
            int temp = arr->at(0);
            arr->at(0) = arr->at(1);
            arr->at(1) = temp;
        }
        else{
            x = 0;
        }
    }
    else{
        vector<int> *left = new vector<int>;
        vector<int> *right = new vector<int>;
        for(int i=0;i<arr->size()/2;i++){
            left->push_back(arr->at(i));
        }
        for(int i=arr->size()/2;i<arr->size();i++){
            right->push_back(arr->at(i));
        }
        x = countInversions(left) + countInversions(right);
        long l = 0;
        long r = 0;
        int i = 0;
        bool left_break = true;
        while(l<left->size()&&r<right->size()){
            if(left->at(l)<=right->at(r)){
                arr->at(i) = left->at(l);
                l++;
                left_break = true;
            }
            else{
                x += (left->size()-l);
                arr->at(i) = right->at(r);
                r++;
                left_break = false;
            }
            i++;
        }
        if(left_break){
            for(int j=r;j<right->size();j++){
                arr->at(i) = right->at(j);
                i++;
            }
        }
        else{
            for(int j=l;j<left->size();j++){
                arr->at(i) = left->at(j);
                i++;
            }
        }
    }
    return x;
}

int main(){
    // vector<int> arr1 = {1,1,1,2,2};
    vector<int> arr2 = {7,5,3,1}; 
    // countInversions(arr2);
    cout << countInversions(&arr2) << endl;
    // cout << countInversions(arr2) << endl;
    return 0;
}