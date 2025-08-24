/*
 * CSES Problem Set - Introductory Problems
 * Problem: Permutations
 * 
 * Problem Statement:
 * A permutation of integers 1,2,…,n is called beautiful if there are 
 * no adjacent elements whose difference is 1.
 * 
 * Given n, construct a beautiful permutation if such a permutation exists.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print a beautiful permutation of integers 1,2,…,n. 
 * If there are several solutions, you may print any of them. 
 * If there are no solutions, print "NO SOLUTION".
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: For n ≥ 4, separate even and odd numbers
 * Time Complexity: O(n) - Linear time to construct permutation
 * Space Complexity: O(n) - To store the permutation
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    // For n ≥ 4, we can construct a beautiful permutation
    // Strategy: Put all even numbers first, then all odd numbers
    // This ensures no adjacent elements have difference 1
    
    vector<int> permutation;
    
    // Add even numbers first (2, 4, 6, ...)
    for (int i = 2; i <= n; i += 2) {
        permutation.push_back(i);
    }
    
    // Add odd numbers (1, 3, 5, ...)
    for (int i = 1; i <= n; i += 2) {
        permutation.push_back(i);
    }
    
    // Print the permutation
    for (int i = 0; i < n; i++) {
        cout << permutation[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
 * Example:
 * Input: 5
 * Output: 2 4 1 3 5
 * 
 * Explanation:
 * Even numbers: 2, 4
 * Odd numbers: 1, 3, 5
 * Permutation: [2, 4, 1, 3, 5]
 * 
 * Check differences:
 * |2-4| = 2 ≠ 1 ✓
 * |4-1| = 3 ≠ 1 ✓
 * |1-3| = 2 ≠ 1 ✓
 * |3-5| = 2 ≠ 1 ✓
 * 
 * Why this works:
 * - Even numbers are at least 2 apart
 * - Odd numbers are at least 2 apart
 * - The transition from even to odd gives difference ≥ 1
 * - For n ≥ 4, we have both even and odd numbers
 * 
 * Test Cases:
 * Input: 1
 * Output: 1
 * 
 * Input: 2
 * Output: NO SOLUTION
 * 
 * Input: 3
 * Output: NO SOLUTION
 * 
 * Input: 4
 * Output: 2 4 1 3
 * 
 * Input: 6
 * Output: 2 4 6 1 3 5
 */
