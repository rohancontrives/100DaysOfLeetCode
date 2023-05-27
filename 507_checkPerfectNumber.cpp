/* #507. Perfect Number
A perfect number is a positive integer that is equal to 
the sum of its positive divisors, excluding the number itself.
Eg1:
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Eg2:
Input: num = 7
Output: false
*/
#include <iostream>
using namespace std;

bool checkPerfectNumber(int num){
    if(num == 1) return false;
    int ans = 0;
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            if(num/i != i) ans += (i + num/i);
        }
    }
    return num == (ans+1);
}

// bool checkPerfectNumber(int num){
//     int ans = 0;
//     for(int i=1; i<num; i++){
//         if(num%i == 0){
//             ans += i;
//         }
//     }
//     return num == ans;
// }
 
int main(){
    cout << std::boolalpha;
    int n1 = 28;
    cout << checkPerfectNumber(n1) << endl;  // true

    int n2 = 7;
    cout << checkPerfectNumber(n2) << endl;  // false

    int n3 = 9;
    cout << checkPerfectNumber(n3) << endl;  // false
    return 0;
}