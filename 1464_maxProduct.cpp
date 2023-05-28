/* #1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).
Eg:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), 
you will get the maximum value, that is, 
(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Eg2:
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), 
you will get the maximum value of (5-1)*(5-1) = 16.
*/

#include <iostream>
#include <vector>
using namespace std;

// int maxProduct(vector<int>& nums) {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     return (nums[n-1] - 1)*(nums[n-2] - 1);
// }

// O(n) time
int maxProduct(vector<int>& nums) {
    int first, second;
    first=second=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>first){
            second=first;
            first=nums[i];
        }
        else if(nums[i]<=first && nums[i]>second)
            second=nums[i];
    }
    return (first-1)*(second-1);
}

 
int main(){
    vector<int> v1 = {3, 4, 5, 2};
    cout << maxProduct(v1) << endl;  // 12

    vector<int> v2 = {1, 5, 4, 5};
    cout << maxProduct(v2) << endl;  // 16

    vector<int> v3 = {3, 7};
    cout << maxProduct(v3) << endl;  // 12
    return 0;
}