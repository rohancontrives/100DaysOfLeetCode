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


// Brute force approach | O(n^2) time | O(m*n) space
// void setZeroes(vector<vector<int>>& matrix) {
//     vector<pair<int, int>> pos;  // {{1, 1}} or {{0, 0}, {0, 3}}
//     for(int i=0; i<matrix.size(); i++){
//         for(int j=0; j<matrix[i].size(); j++)
//             if(matrix[i][j] == 0) pos.push_back(make_pair(i, j));
//     }
//     // for(auto& e: pos) cout << e.first << ", " << e.second << endl;
//     for(auto& p: pos){
//         for(int i=0; i<matrix[p.first].size(); i++){
//             matrix[p.first][i] = 0;
//         }
//         for(int j=0; j<matrix.size(); j++){
//             matrix[j][p.second] = 0;
//         }
//     }
// }

// // Brute force2: mark future 0 as -1 | (n*m)*(n+m)+(n*m) ~ O(n^3) time | O(1) space
// void setZeroes(vector<vector<int>>& matrix){
//     int odd = 1111;  // or -1
//     for(int i=0; i<matrix.size(); i++){
//         int cols = matrix[i].size();
//         for(int j=0; j<cols; j++)
//             if(matrix[i][j] == 0){
//                 // --- mark row -1 ---
//                 for(int k=0; k<cols; k++)
//                     if(matrix[i][k] != 0)
//                         matrix[i][k] = odd;
//                 // ||||| mark columns -1 |||||
//                 for(int k=0; k<matrix.size(); k++)
//                     if(matrix[k][j] != 0)
//                         matrix[k][j] = odd;
//             }
//     }
//     // change -1 -> 0
//     for(int i=0; i<matrix.size(); i++){
//         int cols = matrix[i].size();
//         for(int j=0; j<cols; j++)
//             if(matrix[i][j] == odd) 
//                 matrix[i][j] = 0;
//     }
// }


// Brute Force3: mark rows and columns separately
// O(2*m*n) time | O(m+n) space
void setZeroes(vector<vector<int>>& matrix){
    int mark = 101;
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> rows(r, 0), cols(c, 0);

    // mark rows & cols
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == 0){
                rows[i] = mark;
                cols[j] = mark;
            }
        }
    }

    // mark matrix
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(rows[i] == mark || cols[j] == mark){
                matrix[i][j] = 0;
            }
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

    vector<vector<int>> v3 = {
        {-1},
        { 2},
        { 3}
    };
    setZeroes(v3);
    printArray(v3);  // no change
    return 0;
}