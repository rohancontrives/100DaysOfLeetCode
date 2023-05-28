/* #73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
Eg:
{ {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1} }
====>
{ {1, 0, 1},
  {0, 0, 0},
  {1, 0, 1} }
*/ 


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void printArray(vector<vector<int>> v){
    cout << "{ " << endl;
    for(auto& r: v){
        cout << "   { ";
        for(auto& e: r) cout << e << ", ";
        cout << "}," << endl;
    }
    cout << "}\n\n";
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>> pos;  // {{1, 1}} or {{0, 0}, {0, 3}}
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            if(matrix[i][j] == 0) pos.push_back(make_pair(i, j));
    }
    // for(auto& e: pos) cout << e.first << ", " << e.second << endl;
    for(auto& p: pos){
        for(int i=0; i<matrix[p.first].size(); i++){
            matrix[p.first][i] = 0;
        }
        for(int j=0; j<matrix.size(); j++){
            matrix[j][p.second] = 0;
        }
    }
}
 
int main(){
    vector<vector<int>> v1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(v1);
    printArray(v1);

    vector<vector<int>> v2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    setZeroes(v2);
    printArray(v2);
    return 0;
}