#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    for(int i=0; i<nums.size()-1; i++){
        for(int j=i+1; j<nums.size(); j++){
            if( (nums[i] + nums[j]) == target ) {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    return v;
}

int main(){
    vector<int> v = {3, 2, 4};
    int target = 6;
    for(auto e: twoSum(v, target)){
        cout<<e<<" ";
    }
}