/*
 * CSES Problem Set - Introductory Problems
 * Problem: Weird Algorithm
 * 
 * Problem Statement:
 * Consider an algorithm that takes as input a positive integer n. 
 * If n is even, the algorithm divides it by two, and if n is odd, 
 * the algorithm multiplies it by three and adds one. The algorithm 
 * repeats this, until n is one.
 * 
 * Your task is to simulate the execution of the algorithm for a given value of n.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print a line that contains all values of n during the algorithm.
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: Simple implementation following the algorithm description
 * Time Complexity: O(log n) - Each step roughly halves the number
 * Space Complexity: O(1) - Only storing the current value
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    // Print the initial value
    cout << n;
    
    // Continue until n becomes 1
    while (n != 1) {
        if (n % 2 == 0) {
            // If n is even, divide by 2
            n = n / 2;
        } else {
            // If n is odd, multiply by 3 and add 1
            n = 3 * n + 1;
        }
        cout << " " << n;
    }
    
    cout << "\n";
    return 0;
}

/*
 * Example:
 * Input: 3
 * Output: 3 10 5 16 8 4 2 1
 * 
 * Explanation:
 * 3 is odd → 3×3+1 = 10
 * 10 is even → 10÷2 = 5
 * 5 is odd → 5×3+1 = 16
 * 16 is even → 16÷2 = 8
 * 8 is even → 8÷2 = 4
 * 4 is even → 4÷2 = 2
 * 2 is even → 2÷2 = 1
 */
 