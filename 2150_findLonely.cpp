/* #2150. Find all lonely numbers in the Array
Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/
Problem:
You are given an integer array nums. A number x is lonely when it appears only once, 
and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.
Return all lonely numbers in nums. You may return the answer in any order.
Eg1:
Input: nums = [10,6,5,8]
Output: [10,8]
Explanation: 
- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
- 5 is not a lonely number since 6 appears in nums and vice versa.
Hence, the lonely numbers in nums are [10, 8].
Note that [8, 10] may also be returned.
*/

#include <iostream>
#include <vector>
using namespace std;


template<typename T>
void printArray(T arr, int n){
    cout << "{";
    for(int i=0; i<n; i++) cout << arr[i] << ", ";
    cout << "}";
}

vector<int> findLonely(vector<int>& nums) {
    vector<int> lonely;
    int M = INT_MIN;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] > M){
            M = nums[i];
        }
    }
    
    int h = M+2;
    int hash[h];
    for(int i=0; i<h; i++) hash[i] = 0;

    for(int i=0; i<n; i++)
        hash[nums[i]]++;

    for(int i=0; i<n; i++){
        if(hash[nums[i]] == 1 && hash[nums[i]+1] == 0){
            if(nums[i] == 0)
                lonely.push_back(nums[i]);
            else{
                if(hash[nums[i]-1] == 0)
                    lonely.push_back(nums[i]);
            }
        }
    }
    return lonely;
}

int main(){
    vector<int> v = {0,2, 2, 3, 4, 5, 9};
    vector<int> vnew = findLonely(v);
    printArray(vnew, vnew.size());  // {0, 9, }
    return 0;
}



