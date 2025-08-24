/*
 * CSES Problem Set - Introductory Problems
 * Problem: Bit Strings
 * 
 * Problem Statement:
 * Your task is to calculate the number of bit strings of length n.
 * For example, if n=3, the correct answer is 8, because the possible 
 * bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print the result modulo 10^9+7.
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: Use fast exponentiation to calculate 2^n mod 10^9+7
 * Time Complexity: O(log n) - Fast exponentiation
 * Space Complexity: O(1) - Constant space
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

// Fast exponentiation: calculate (base^exp) % mod
ll fast_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    
    while (exp > 0) {
        // If current bit is set, multiply result with base
        if (exp & 1) {
            result = (result * base) % mod;
        }
        
        // Square the base and reduce modulo
        base = (base * base) % mod;
        
        // Right shift exponent
        exp >>= 1;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // For each position, we have 2 choices (0 or 1)
    // Total number of bit strings = 2^n
    ll result = fast_pow(2, n, MOD);
    
    cout << result << "\n";
    return 0;
}

/*
 * Mathematical Explanation:
 * 
 * For a bit string of length n:
 * - Position 1: 2 choices (0 or 1)
 * - Position 2: 2 choices (0 or 1)
 * - Position 3: 2 choices (0 or 1)
 * - ...
 * - Position n: 2 choices (0 or 1)
 * 
 * By the multiplication principle:
 * Total combinations = 2 × 2 × 2 × ... × 2 (n times) = 2^n
 * 
 * Example for n = 3:
 * 2³ = 8 possible bit strings:
 * 000, 001, 010, 011, 100, 101, 110, 111
 * 
 * Why use fast exponentiation?
 * - Direct calculation of 2^n for large n can overflow
 * - Fast exponentiation reduces time complexity from O(n) to O(log n)
 * - Modular arithmetic prevents overflow
 * 
 * Alternative Solution using built-in pow:
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     // Use built-in pow function with modulo
 *     ll result = 1;
 *     for (int i = 0; i < n; i++) {
 *         result = (result * 2) % MOD;
 *     }
 *     
 *     cout << result << "\n";
 *     return 0;
 * }
 * 
 * Test Cases:
 * Input: 1
 * Output: 2
 * 
 * Input: 2
 * Output: 4
 * 
 * Input: 3
 * Output: 8
 * 
 * Input: 10
 * Output: 1024
 * 
 * Input: 20
 * Output: 1048576
 * 
 * Verification:
 * - 2¹ = 2 ✓
 * - 2² = 4 ✓
 * - 2³ = 8 ✓
 * - 2¹⁰ = 1024 ✓
 * - 2²⁰ = 1048576 ✓
 * 
 * Note: All results are taken modulo 10^9+7
 */
