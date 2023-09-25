#include <iostream>
#include <vector>
using namespace std;

std::vector<int> * merge(std::vector<int> * top_k_1, std::vector<int> * top_k_2){
    std::vector<int> * temp_vector = new std::vector<int>;
    int i = 0;
    int j = 0;
    while(i<top_k_1->size()&&j<top_k_2->size()){
        if(top_k_1->at(i)<top_k_2->at(j)){
            temp_vector->push_back(top_k_1->at(i));
            i++;
        }
        else{
            temp_vector->push_back(top_k_2->at(j));
            j++;
        }
    }
    if(i==top_k_1->size()){
        for(;j<top_k_2->size();j++){
            temp_vector->push_back(top_k_2->at(j));
        }
    }
    else{
        for(;i<top_k_1->size();i++){
            temp_vector->push_back(top_k_1->at(i));
        }        
    }
    return temp_vector;
}
std::vector<int> * mergesort(std::vector<int> * top_k){
    std::vector<int> * temp_vector = new std::vector<int>;
    if(top_k->size()==1){
        temp_vector->push_back(top_k->at(0));
        return temp_vector;
    }
    else{
        std::vector<int> * temp_vector_2 = new std::vector<int>;
        for(int i=0;i<top_k->size()/2;i++){
            temp_vector->push_back(top_k->at(i));
        }
        for(int i=top_k->size()/2;i<top_k->size();i++){
            temp_vector_2->push_back(top_k->at(i));
        }
        return merge(mergesort(temp_vector),mergesort(temp_vector_2));
    }
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int vector_size = citations.size();
        vector<int> * sorted_citations = mergesort(&citations);
        for(int i=0;i<vector_size;i++){
            if(sorted_citations->at(i)>=(vector_size-i)){
                return vector_size-i;
            }
        }return 0;
    }
};


// Better solution
// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         int vector_size = citations.size();
//         sort(citations.begin(),citations.end());
//         for(int i=0;i<vector_size;i++){
//             if(citations.at(i)>=(vector_size-i)){
//                 return vector_size-i;
//             }
//         }return 0;
//     }
// };
