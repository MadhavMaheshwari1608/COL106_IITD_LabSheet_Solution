#include <iostream>
#include <vector>
using namespace std;

class Answer{
public:
    int maxPoints;
    vector<vector<double>> * lines;
    Answer(){
        maxPoints = 1;
        lines = new vector<vector<double>>;
    }
};

Answer * maxPoints_recursive(vector<vector<int>>& points){
    Answer * result = new Answer();
    if(points.size()==1){
        return result;
    }
    else if(points.size()==2){
        result->maxPoints = 2;
        int y0 = points[0][1]-points[1][1];
        int x0 = points[0][0] - points[1][0];
        double m0 = (double)1010101;
        double c0 = (double)points[1][0];
        if(x0!=0){
            m0 = (double)y0/(double)x0;
            c0 = ((double)points[0][1] - (m0*(double)points[0][0]));
        }
        vector<double> line0;
        line0.push_back(m0);
        line0.push_back(c0);
        result->lines->push_back(line0);
        return result;
    }
    else if(points.size()==3){
        vector<vector<int>> less_points;
        for(int i=0;i<points.size()-1;i++){
            less_points.push_back(points[i]);
        }
        Answer * temp = maxPoints_recursive(less_points);
        int y0 = points[2][1]-points[1][1];
        int x0 = points[2][0] - points[1][0];
        double m0 = (double)1010101;
        double c0 = (double)points[1][0];
        if(x0!=0){
            m0 = (double)y0/(double)x0;
            c0 = ((double)points[2][1] - (m0*(double)points[2][0]));
        }
        if(m0==temp->lines->at(0)[0]&&c0==temp->lines->at(0)[1]){
            temp->maxPoints += 1;
            return temp;
        }
        else{
            vector<double> line0;
            line0.push_back(m0);
            line0.push_back(c0);
            temp->lines->push_back(line0);
            int y1 = points[2][1]-points[0][1];
            int x1 = points[2][0] - points[0][0];
            double m1 = (double)1010101;
            double c1 = (double)points[1][0];
            if(x1!=0){
                double m1 = (double)y1/(double)x1;
                double c1 = ((double)points[2][1] - (m1*(double)points[2][0]));
            }
            vector<double> line1;
            line1.push_back(m1);
            line1.push_back(c1);
            temp->lines->push_back(line1);   
            return temp;                     
        }
    }
    else{
        vector<vector<int>> less_points;
        for(int i=0;i<points.size()-1;i++){
            less_points.push_back(points[i]);
        }
        vector<vector<int>> very_less_points;
        for(int i=0;i<points.size()-2;i++){
            very_less_points.push_back(points[i]);
        }
        Answer * temp = maxPoints_recursive(less_points);
        Answer * temp2 = maxPoints_recursive(very_less_points);
        vector<vector<double>> * lines_found = new vector<vector<double>>;
        vector<vector<double>> * final_line = new vector<vector<double>>;
        for(int i=0;i<points.size()-1;i++){
            int y0 = points[points.size()-1][1]-points[i][1];
            int x0 = points[points.size()-1][0] - points[i][0];
            double m0 = (double)1010101;
            double c0 = (double)points[i][0];
            if(x0!=0){
                m0 = (double)y0/(double)x0;
                c0 = ((double)points[points.size()-1][1] - (m0*(double)points[points.size()-1][0]));
            }
            for(int j=0;j<temp->lines->size();j++){
                if(m0==temp->lines->at(j)[0]&&c0==temp->lines->at(j)[1]){
                    temp->maxPoints += 1;
                    final_line->push_back(temp->lines->at(j));
                    temp->lines = final_line;
                    return temp;
                }
                else{
                    for(int k=0;k<temp2->lines->size();k++){
                        if(m0==temp2->lines->at(k)[0]&&c0==temp2->lines->at(k)[1]){
                            lines_found->push_back(temp2->lines->at(k));
                        }
                    }
                }
            }
        }
        for(int i=0;i<lines_found->size();i++){
            temp->lines->push_back(lines_found->at(i));
        }
        return temp;
    }
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        else if(points.size()==2){
            return 2;
        }
        else{
            Answer * t = maxPoints_recursive(points);
            return t->maxPoints;
        }
    }
};