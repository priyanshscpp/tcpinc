/*
 * CSES Problem Set - Introductory Problems
 * Problem: Two Knights
 * 
 * Problem Statement:
 * Your task is to count for k=1,2,…,n the number of ways two knights 
 * can be placed on a k×k chessboard so that they do not attack each other.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print n integers: the results for k=1,2,…,n.
 * 
 * Constraints: 1 ≤ n ≤ 10000
 * 
 * Solution: Mathematical formula for non-attacking knight positions
 * Time Complexity: O(n) - Linear time to calculate for each k
 * Space Complexity: O(1) - No extra space needed
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int k = 1; k <= n; k++) {
        // For a k×k chessboard:
        // Total ways to place 2 knights: C(k², 2) = k²(k²-1)/2
        // Ways where knights attack each other: 4(k-1)(k-2)
        // 
        // Explanation of attacking positions:
        // A knight can attack in 8 directions, but on a k×k board,
        // some positions are invalid. The formula 4(k-1)(k-2) counts
        // all valid attacking positions for two knights.
        
        ll total_positions = (ll)k * k;
        ll ways_to_place_two = total_positions * (total_positions - 1) / 2;
        ll attacking_positions = 4LL * (k - 1) * (k - 2);
        
        ll non_attacking_positions = ways_to_place_two - attacking_positions;
        
        cout << non_attacking_positions;
        if (k < n) cout << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
 * Mathematical Derivation:
 * 
 * For a k×k chessboard:
 * 
 * 1. Total ways to place 2 knights:
 *    - First knight: k² positions
 *    - Second knight: k²-1 positions
 *    - Order doesn't matter: divide by 2
 *    - Total: k²(k²-1)/2
 * 
 * 2. Ways where knights attack each other:
 *    - Each knight can attack in 8 directions
 *    - On a k×k board, some positions are invalid
 *    - Valid attacking positions: 4(k-1)(k-2)
 * 
 * 3. Final answer: Total - Attacking
 * 
 * Example:
 * Input: 8
 * Output: 0 6 28 96 252 550 1056 1848
 * 
 * Explanation for k = 3:
 * - Total positions: 3² = 9
 * - Ways to place 2 knights: C(9,2) = 36
 * - Attacking positions: 4(3-1)(3-2) = 4×2×1 = 8
 * - Non-attacking positions: 36 - 8 = 28
 * 
 * For k = 1: 0 (can't place 2 knights on 1×1 board)
 * For k = 2: 6 (all positions are non-attacking)
 * 
 * Test Cases:
 * Input: 1
 * Output: 0
 * 
 * Input: 2
 * Output: 0 6
 * 
 * Input: 3
 * Output: 0 6 28
 * 
 * Input: 4
 * Output: 0 6 28 96
 * 
 * Verification for k = 4:
 * - Total: C(16,2) = 120
 * - Attacking: 4×3×2 = 24
 * - Non-attacking: 120 - 24 = 96 ✓
 */
