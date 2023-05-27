/* #2427. Number of Common Factor
Given two positive integers a and b, return the number of common factors of a and b.
An integer x is a common factor of a and b if x divides both a and b.
Eg1:
Input: a = 12, b = 6
Output: 4
Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.

Eg2:
Input: a = 25, b = 30
Output: 2
Explanation: The common factors of 25 and 30 are 1, 5.
*/

#include <iostream>
using namespace std;

int commonFactors(int a, int b){
    int cnt = 0;
    for(int i=1; i<=((a<b)?a:b); i++){
        if((a%i == 0) && (b%i == 0)) cnt++;
    }
    return cnt;
}
 
int main(){
    int m1 = 12, n1 = 6;
    cout << commonFactors(m1, n1) << endl;  // 4

    int m2 = 25, n2 = 30;
    cout << commonFactors(m2, n2) << endl;  // 2
    return 0;
}