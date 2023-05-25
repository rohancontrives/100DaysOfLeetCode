/* #268. Missing Number
- Given an array nums containing n distinct numbers in the range [0, n], 
  return the only number in the range that is missing from the array.
  Eg: nums = [3, 0, 1]; ans = 2.
      nums = [0, 1]; ans = 2.
      nums = [9,6,4,2,3,5,7,0,1]; ans = 8.

*/

#include <iostream>
#include <vector>
using namespace std;

// ============= Method 1: using ap formula ==============
// int getMissing(vector<int> v, int n){
//     int expectedSum = n*(n+1)/2;  // May cause overflow problem for large n. That's why XOR method is prefered
//     int actualSum = 0;
//     for(auto e: v) actualSum += e;
//     return expectedSum - actualSum;
// }

// ============= Method 2: using XOR ==============
/*
- 0 is the identity element for XOR. This means, any number XOR’ed with 0 remains unchanged.
  i.e., a^0 = a.
- XOR is self-inverse. This means, any number XOR'ed with itself evaluates to 0.
  i.e., a^a = 0.
*/
// Logic: a^b^d ^ a^b^c^d = (a^a)^(b^b)^(c)^(d^d) = 0^0^c^0 = c.
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    for(int i=0; i<n; i++) result = result^i^nums[i];
    return result^n;
}

int main(){
    vector<int> v1 = {3,0,1};
    cout<<missingNumber(v1)<<endl;  // 2

    vector<int> v2 = {0,1};
    cout<<missingNumber(v2)<<endl;  // 2

    vector<int> v3 = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(v3)<<endl;  // 8
}