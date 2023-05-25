/* #392. Is Subsequence
- Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
- A subsequence of a string is a new string that is formed from the original string by deleting some 
  (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., 
- E.g: "ace" is a subsequence of "abcde" while "aec" is not.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// bool isSubsequence(string s, string t){
//     int i = 0;  // i -> s
//     int j = 0;  // j -> t
//     while( (i < s.size()) && (j < t.size()) ){
//         if(s[i] == t[j])
//             i++;
//         j++;
//     }
//     cout<<std::boolalpha;
//     return i == s.size();
// }

// O(n) time | O(1) space
bool isSubsequence(string s, string t) {
    cout<<std::boolalpha;
    int k = 0;  // k -> s
    for(int i=0;i<t.size();i++)  // i -> t
        if(t[i] == s[k])
            k++;
    return k==s.size();
}

bool isSubsequenceArr(vector<int> sub, vector<int> v){
    int k = 0;  // k -> sub
    for(int i=0; i<v.size(); i++){  // i -> v
        if(sub[k] == v[i])
            k++;
    }
    return k == sub.size();
}


int main(){
    // Case I: strings
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout<<isSubsequence(s1, t1)<<endl;  // true

    string s2 = "axc";
    string t2 = "ahbgdc";
    cout<<isSubsequence(s2, t2)<<endl;  // false


    // Case II: array of numbers
    vector<int> u1 = {1, 6, -1, 10};
    vector<int> v1 = {5, 1, 22, 25, 6, -1, 8, 10};
    cout<<isSubsequenceArr(u1, v1)<<endl;  // true

    vector<int> u2 = {1, 6, -1, 10};
    vector<int> v2 = {5, 1, 22, 25, 6, 8, 10};
    cout<<isSubsequenceArr(u2, v2)<<endl;  // false
}
