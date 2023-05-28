/* #344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Eg:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& str) {
    int s = 0, e = str.size()-1;
    while(s<e){
        if(str[s] != str[e]) swap(str[s], str[e]);
        s++;
        e--;
    }
}
 
int main(){
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str);
    // print
    cout << "{";
    for(auto& e: str) {
        cout << e << ", ";
    }
    cout << "}";  // {o, l, l, e, h, }
    return 0;
}