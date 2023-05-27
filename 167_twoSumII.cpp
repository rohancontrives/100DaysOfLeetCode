/* #167. Two Sum II - Input Array Is Sorted
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

#include <iostream>
#include <vector>
// #include <algorithm>  // for sort()
using namespace std;

// T: O(n) | S: O(1)
vector<int> twoSum(vector<int>& arr, int target) {
    // sort(arr.begin(), arr.end());  // in case of unsorted array; T: O(nlog(n))
    int l = 0, r = arr.size()-1, sum;
    while(true){
        sum = arr[l] + arr[r];
        if (sum == target)
            return {++l, ++r};  // OR: vector<int>{++l,++r};
        else if(sum > target)
            r--;
        else
            l++;
    }
}

void printVector(const vector<int>& v){
    for(auto e: v) cout<<e<<" ";
    cout<<endl;
}

int main(){
    vector v1 = {2, 7, 11, 15};
    int t1 = 9;
    printVector(twoSum(v1, t1));  // 1 2

    vector v2 = {2, 3, 4};
    int t2 = 6;
    printVector(twoSum(v2, t2));  // 1 3

    vector v3 = {-1, 0};
    int t3 = -1;
    printVector(twoSum(v3, t3));  // 1 2
}