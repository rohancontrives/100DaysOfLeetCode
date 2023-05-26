// #9. Palindrome Number
// Given an integer x, return true if x is a palindrome, and false otherwise.
// An integer is a palindrome when it reads the same forward and backward.

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    long long xCpy = x;
    long long r=0, rev=0;
    while(x){
        r = x%10;
        // if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
        rev = rev*10 + r;
        x /= 10;
    }
    return rev==xCpy;
}

int main(){
    int arr[] = {121, -121, 10};
    cout<<std::boolalpha;
    for(int& e: arr){
        cout << isPalindrome(e) << endl;
    }
    /*
    true
    false  // -121 != 121-
    false     // 10 != 01
    */
}