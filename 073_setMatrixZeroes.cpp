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


// // Brute force0 | O(n^2) time | O(m*n) space
// void setZeroes(vector<vector<int>>& matrix) {
//     vector<pair<int, int>> pos;  // {{1, 1}} or {{0, 0}, {0, 3}}
//     int r = matrix.size(), c = matrix[0].size();
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++)
//             if(matrix[i][j] == 0) pos.push_back(make_pair(i, j));
//     }
//     // for(auto& e: pos) cout << e.first << ", " << e.second << endl;
//     for(auto& p: pos){
//         for(int j=0; j<r; j++)
//             matrix[j][p.second] = 0;  // set colums to zero
//         for(int i=0; i<c; i++)
//             matrix[p.first][i] = 0;  // set rows to zero
//     }
// }



// // Brute force1: mark future 0 as -1 | (n*m)*(n+m)+(n*m) ~ O(n^3) time | O(1) space
// void setZeroes(vector<vector<int>>& matrix){
//     int mark = -101;  // or -1
//     int r = matrix.size();
//     int c = matrix[0].size();
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++)
//             if(matrix[i][j] == 0){
//                 // ----- mark row -----
//                 for(int k=0; k<c; k++)
//                     if(matrix[i][k] != 0)
//                         matrix[i][k] = mark;
//                 // ||| mark columns |||
//                 for(int k=0; k<r; k++)
//                     if(matrix[k][j] != 0)
//                         matrix[k][j] = mark;
//             }
//     }
//     // change mark -> 0
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++)
//             if(matrix[i][j] == mark) 
//                 matrix[i][j] = 0;
//     }
// }



// // Better Approach: mark rows and columns separately
// // O(2*m*n) time | O(m+n) space
// void setZeroes(vector<vector<int>>& matrix){
//     int mark = -101;  // or -1
//     int r = matrix.size();
//     int c = matrix[0].size();
//     vector<int> rows(r, 0), cols(c, 0);

//     // mark rows & cols
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(matrix[i][j] == 0){
//                 rows[i] = mark;
//                 cols[j] = mark;
//             }
//         }
//     }

//     // mark matrix
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(rows[i] == mark || cols[j] == mark){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }


// OptimisedAlgo: O(n^2) time | O(1) space
void setZeroes(vector<vector<int>>& matrix){
    int r = matrix.size();
    int c = matrix[0].size();
    int mark = 0;
    int col0 = 1;
    // check metrix and mark in-place rows & cols
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == 0){
                // mark the i-th row (inside in-place rows)
                matrix[i][0] = mark;
                // mark the j-th col (inside in-place cols)
                if(j != 0)
                    matrix[0][j] = mark;
                else
                    col0 = mark;
            }
        }
    }

    // iterate & mark the matrix using the hash array (leaving hash array untouched).
    // In-place hash array determines the matrix state so it's left untouched.
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(matrix[i][j] != 0){  // non-zero value -> 0.
                // check for hashes and mark the matrix as 0.
                // As i & j starts from 1, we won't be touching the hashes.
                if(matrix[0][j] == mark || matrix[i][0] == mark){
                    matrix[i][j] = 0;
                }

            }
        }
    }

    // Marking the in-place hashes (rows & cols).
    // In-place col: if matrix[0][0] == mark => whole first row = 0.
    if(matrix[0][0] == mark)
        for(int j=0; j<c; j++)
            matrix[0][j] = 0;
    // In-place row: if col0 == mark => whole first column = 0.
    if(col0 == mark)
        for(int i=0; i<r; i++)
            matrix[i][0] = 0;
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