#include<iostream>
using namespace std;

// O(sqrt(n)) time
bool isPrime(int n){
    int cnt = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cnt++;
            if((n/i) != i) cnt++;
        }
    }
    if(cnt == 2) return true;
    return false;
}
 
int main(){
    int a[] = {1, 2, 3, 5, 7, 11, 12, 15, 19, 20};
    for(int& e: a){
        cout << std::boolalpha;
        cout << e << ": " << isPrime(e) << endl;
    }
    return 0;
}