// #1979. Find Greatest Common Divisor of Array

#include <iostream>
#include <algorithm>  // min_element, max_element
#include <vector>
#include <utility>
using namespace std;

// pair<int, int> getMaxMin(vector<int> v){
//     int n = v.size();
//     int largest = INT_MIN;
//     int smallest = INT_MAX;
//     for(auto& e: v){
//         if(e > largest) largest = e;
//         if(e < smallest) smallest = e;
//     }
//     return pair<int, int>{largest, smallest};
// }

// int findGCD(vector<int>& nums) {
//     // find min & max
//     pair<int, int> p = getMaxMin(nums);
//     int a = p.first, b = p.second, gcd;
//     // Euclidean Algorithm: 
//     // gcd(a, b) = gcd(a-b, b) = gcd(a%b, b) = gcd(c, 0) = c; a>b, c=remainder after iterative evaluation of a%b.
//     while(a>0 && b>0){
//         (a>b)? a%=b: b%=a;
//     }
//     gcd = (a==0)? b: a;
//     return gcd;
// }

// Alternatively using recursion:
int gcd(int l, int s){
    if(l==0) return s;
    if(s==0) return l;
    if(l==s) return l;
    if(l>s) return gcd(l%s, s);
    return gcd(l, s%l);
}

int findGCD(vector<int>& nums) {
    // find min & max
    int n = nums.size();
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i=0; i<n; i++){
        if(nums[i] > largest) largest = nums[i];
        if(nums[i] < smallest) smallest = nums[i];
    }
    // recursive call
    return gcd(largest, smallest);
}

int main(){
    vector<vector<int>> testCases = {
        {2, 5, 6, 9, 10},
        {7, 5, 6, 8, 3},
        {3, 3}
    };
    for(auto& v: testCases){
        cout << "GCD(" << *max_element(v.begin(), v.end()) << ", " << *min_element(v.begin(), v.end()) << "): " << findGCD(v) << endl;
    }
}
/*
GCD(10, 2): 2
GCD(8, 3): 1
GCD(3, 3): 3
*/