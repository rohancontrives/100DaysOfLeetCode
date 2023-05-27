/* #136. Single Number
- Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
- Eg: nums = [2, 2, 1]; ans = 1;
      nums = [4, 1, 2, 1, 2]; ans = 4;
      nums = [1]; ans = 1;
*/

/*
- 0 is the identity element for XOR. This means, any number XOR’ed with 0 remains unchanged.
  i.e., a^0 = a.
- XOR is self-inverse. This means, any number XOR'ed with itself evaluates to 0.
  i.e., a^a = 0.
*/


#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(auto& e: nums) result ^= e;
    return result;
}

int main(){
    vector<int> v = {4, 1, 2, 1, 2};
    cout<<singleNumber(v)<<endl;  // 4
}