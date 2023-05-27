#include <iostream>
#include <vector>
#include <utility>
using namespace std;


vector<long long> lcmAndGcd(long long A , long long B) {
    long long A_cpy = A, B_cpy = B;
    // LCM: Lowest Common Multiple.
    // Eg: lcm(4, 6): 12 | 4: 4, 8, 12...; 6: 6, 12, 18...; => 12
    // Logic: iterates multiples of L = max(A, B) till A*B.
    //        LCM obtained when L is divisible by both A & B.
    long long L;
    // for(L = (A>B)? A : B; L<=A*B; L+=L){
    //     if(L%A==0 && L%B==0) break;
    // }

    // GCD/HCF: Greatest Common Divisor/ Highest Common Factor.
    // Eg: gcd(4, 6): 2 | 4: 2*2; 6: 2*3; => gcd: 2;
    // Logic: iterates H=min(A, B) till 1. Because any number greater then min(A, B) can't divide both.
    //        GCD is obtained when H(greatest common divisor iterating from the top) divides both A & B.
    long long H;
    // for(H=((A<B)? A: B); H>=1; H--){
    //     if(A%H==0 && B%H==0) break;
    // }
    // Alternate: Euclidean algorithm: gcd(a, b) = gcd(a-b, b) = gcd(a%b, b); a>b.
    // Time complexity: log of min(a,b) to the base φ.
    while(A>0 && B>0){
        (A>B)? A %= B: B %= A;
    }
    H = (A==0)? B: A;

    // Alternatively: lcm(a, b) = ab/gcd(a,b)
    return {(A_cpy*B_cpy)/H, H};
}

int main(){
    vector<pair<long long, long long>> v = {{4, 6}, {5, 10}, {6, 9}, {52, 10}, {113094, 9449384}};
    // vector<long long> hcm = {2, 5, 3, 2, 2};
    int cnt = 0;
    for(auto& e: v){
        auto vect = lcmAndGcd(e.first, e.second);
        cout << "LCM: " << vect[0] << ", GCD: " << vect[1] << endl;
    }
    /*
    LCM: 12, GCD: 2
    LCM: 10, GCD: 5
    LCM: 18, GCD: 3
    LCM: 832, GCD: 2
    LCM: 534334317048, GCD: 2
    */

}

/*
A: 4, B: 6, A*B: 24, H: 2, L: 12
A: 5, B: 10, A*B: 50, H: 5, L: 10
A: 6, B: 9, A*B: 54, H: 3, L: 18
A: 52, B: 10, A*B: 520, H: 2, L: 260
A: 113094, B: 9449384, A*B: 1068668634096, H: 2, L: 534334317048
*/