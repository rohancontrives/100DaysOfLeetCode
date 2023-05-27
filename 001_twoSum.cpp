// #1 Two Sum

#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Method 1: Two for loops | T: O(n^2) | S: O(1)
vector<int> twoSum_1(vector<int>& nums, int target) {
    for(int i=0; i<nums.size()-1; i++){
        for(int j=i+1; j<nums.size(); j++){
            if( (nums[i] + nums[j]) == target ) {
                return {i, j};
            }
        }
    }
    return {};
}


// Method 2: Using hashmap or map std | T: O(n) | S: O(n)
vector<int> twoSum_2(vector<int>& nums, int target) {
    map<int, int> m;   // endResult -> { {3, 0}, {2, 1}, {4, 3} }
    int comp;  // complementary number
    for(int i=0; i<nums.size(); i++){
        comp = target-nums[i];
        // map.find() returns An iterator to the element, if an element with specified key is found, or map::end otherwise.
        if(m.find(comp) != m.end())
            return {m[comp], i};
        else
            m[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> v = {3, 2, 4}; 
    int target = 6;
    for(auto e: twoSum_1(v, target)){
        cout<<e<<" ";  // 1 2 
    }
    cout<<endl;

    for(auto e: twoSum_2(v, target)){
        cout<<e<<" ";  // 1 2 
    }
}


// // Method 2: Using hashmap and map.contains method or map std | T: O(n) | S: O(n)
// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> v;
//     map<int, int> map;   // endResult -> { {3: 0}, {2: 1}, {4: 3} }
//     for(int i=0; i<nums.size(); i++){
//         if( map.contains(target - nums[i]) ) {
//             v.push_back(map[target-nums[i]]);
//             v.push_back(i);
//         } else{
//             map[nums[i]] = i;
//         }
//     }
//     return v;
// }