// #gfg | Sum of all divisors from 1 to n.
/* Example
- Given a positive integer N., The task is to find the value of sum(F(i)) i=1 to i=N;
  where function F(i) for the number i be defined as the sum of all divisors of 'i'.
N = 4;
F(1) = 1
F(2) = 1+2 = 3
F(3) = 1+3 = 4
F(4) = 1+2+4 = 7
ans = F(1) + F(2) + F(3) + F(4) = 1+ 3 + 4+ 7 = 15.
*/
#include <iostream>
#include <cmath>
using namespace std;

// bool isDivisor(int n){
//     for(int i=1; i<=sqrt(n); i++){
//         if(n%i == 0) true;
//     }
//     return false;
// }

// long long sumOfDivisors(int N){
//     int sum = 0;
//     for(int i = 1; i <= N; ++i){
//         // Find all divisors of i and add them
//         for(int j = 1; j * j <= i; ++j){
//             if (i % j == 0){
//                 if (j*j == i)
//                     sum += j;  // at the middle when j*j == i, only factor will be j.
//                 else
//                     sum += (j + i / j);  // before reaching middle, factors are (j, i/j).
//             }
//         }
//     }
//     return sum;
// }

// Alternative
/*
Let n = 6,
=> F(1) + F(2) + F(3) + F(4) + F(5) + F(6)
=> 1 will occurs 6 times in F(1), F(2),
   F(3), F(4), F(5) and F(6)
=> 2 will occurs 3 times in F(2), F(4) and
   F(6)
=> 3 will occur 2 times in F(3) and F(6)
=> 4 will occur 1 times in F(4)
=> 5 will occur 1 times in F(5)
=> 6 will occur 1 times in F(6)
*/
long long sumOfDivisors(int N){
    long long  sum = 0;
    // think about how many times a number can be a divisor.
    for (int i = 1; i <= N; ++i) 
        sum += (N / i) * i; 
    return sum;
}

int main(){
    cout << sumOfDivisors(4) << endl;  // 15
    cout << sumOfDivisors(5) << endl;  // 21
}