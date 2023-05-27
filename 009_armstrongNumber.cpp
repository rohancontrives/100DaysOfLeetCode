// #1134. Armstrong Number
// Given an integer n, return true if and only if it is an Armstrong number.
// Def: The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.
// Eg: n = 153; 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3. => true
//     n = 123; 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36. => false

#include <iostream>
using namespace std;

// // b raiseed to the power p in log(n) time complexity.
int powerOptimised(int b, int p){
    int ans = 1;
    while(p){
        int lastBit = p&1;
        if(lastBit) ans *= b;  // check set bit
        b *= b;
        p = p>>1;
    }
    return ans;
}

bool isArmstrong(int n) {
    int n2 = n;
    // int digits = to_string(n).size();  // #include<string>
    int digits = 0;
    while(n2){
        digits++;
        n2 /= 10;
    }
    int n3 = n, sumPoweredDigit = 0;
    while(n3){
        sumPoweredDigit += powerOptimised(n3%10, digits);
        n3 /= 10;
    }
    return sumPoweredDigit == n;


}

int main(){
    int a[] = {153, 123, 370, 371, 407, 321};
    for(auto& e: a){
        cout << std::boolalpha;
        cout << isArmstrong(e) << endl;
    }
}
/*
true
false
true
true
true
false
*/