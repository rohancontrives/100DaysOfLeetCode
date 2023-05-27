/* #204. Count Primes
Given an integer n, return the number of prime numbers that are strictly less than n.
Eg1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Eg2:
Input: n = 0
Output: 0

Eg3:
Input: n = 1
Output: 0
*/


// Using Sieve of Atkin
#include <bits/stdc++.h>
using namespace std;

// Function to generate primes till limit using Sieve of Atkin 
int countPrime(int limit)
{
    // Initialise the sieve array with initial false values
    bool sieve[limit+1];
    for (int i = 0; i <= limit; i++)
        sieve[i] = false;

    // 2 and 3 are known to be prime
    if (limit > 2)
        sieve[2] = true;
    if (limit > 3)
        sieve[3] = true;
  
    /* Mark sieve[n] is true if one of the following is true:
    a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
       odd number of distinct pairs (x, y) that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
    b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
    c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */
    for (int x = 1; x * x <= limit; x++) {
        for (int y = 1; y * y <= limit; y++) {

            // Condition 1
            int n = (4 * x * x) + (y * y);
            if (n <= limit 
                && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            // Condition 2
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            // Condition 3
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit 
                && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    // Mark all multiples of squares as non-prime
    for (int r = 5; r * r <= limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i <= limit; i += r * r)
                sieve[i] = false;
        }
    }

    // Print/count primes using sieve[]
    int cnt = 0;
    for (int a = 1; a <= limit; a++)
        if (sieve[a])
            cnt++;
    //         cout << a << " ";
    // cout << "\n";
    return cnt;
}

// Driver program
int main(void)
{

    int n2 = 10;
    cout << countPrime(n2) << endl;  // 4

    int n3 = 1;
    cout << countPrime(n3) << endl;  // 0
    int n4 = 0;
    cout << countPrime(n4) << endl;  // 0

    int n5 = 5;
    cout << countPrime(n5) << endl;  // 2
    
    // int n1 = 999983;
    // cout << countPrime(n1) << endl;  // 78498
    return 0;
}