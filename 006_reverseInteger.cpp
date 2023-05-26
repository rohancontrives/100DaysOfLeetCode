/*
- Given a signed 32-bit integer x, return x with its digits reversed. 
- If reversing x causes the value to go outside the signed 
  32-bit integer range [-231, 231 - 1], then return 0.
- Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
- Eg: x = 123; O/P: 321; 
      x = -123; O/P: -321;
      x = 120; O/P: 21
*/

#include <iostream>
using namespace std;

int reverse(int x) {
    int r=0, rev=0;
    while(x){
        r = x%10;
        if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
        rev = rev*10 + r;
        x /= 10;
    }
    return rev;
}

int main(){
    int n1 = 123;
    int n2 = -123;
    int n3 = 120;
    cout << reverse(n1) << endl;  // 321
    cout << reverse(n2) << endl;  // -321
    cout << reverse(n3) << endl;  // 21
}
// git commit --date='2023-05-26 20:39:56' -m "complete 006_reverseInteger.cpp"