/* #125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    string str;

    // filter or sieve the string
    for(char ch: s){
        // check for alphanumeric
        // ASCII: 0-9 -> 48-57 | A-Z -> 65-90 | a-z -> 97-122;
        if( (ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
            if( (ch>='A') && (ch<='Z')) str += (ch+32);  // convert to lower | 32 = 'a' - 'A'
            else str += ch;
        }
    }

    // check for palindrom => str[start] == str[end] for every character.
    int start=0, end=str.size()-1;
    while(start<end){
        if(str[start] != str[end]) return false;
        start++; end--;
    }
    return true;
}
 
int main(){
    cout << std::boolalpha;

    string s1 = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s1) << endl;  // true
    
    string s2 = "race a car";
    cout << isPalindrome(s2) << endl;  // false

    string s3 = " ";
    cout << isPalindrome(s3) << endl;  // true

    return 0;
}