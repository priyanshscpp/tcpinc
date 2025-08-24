/*
 * CSES Problem Set - Introductory Problems
 * Problem: Coin Piles
 * 
 * Problem Statement:
 * You have two coin piles containing a and b coins. On each move, 
 * you can either remove one coin from the left pile and two coins 
 * from the right pile, or two coins from the left pile and one coin 
 * from the right pile.
 * 
 * Your task is to efficiently find out if you can empty both piles.
 * 
 * Input: The first input line contains an integer t: the number of tests.
 * After this, there are t lines, each containing integers a and b.
 * 
 * Output: For each test, print "YES" if you can empty both piles and "NO" otherwise.
 * 
 * Constraints: 1 ≤ t ≤ 10^5, 0 ≤ a,b ≤ 10^9
 * 
 * Solution: Check if (a+b) is divisible by 3 and both piles can be emptied
 * Time Complexity: O(t) - Constant time per test case
 * Space Complexity: O(1) - Constant space
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll a, b;
        cin >> a >> b;
        
        // Check if it's possible to empty both piles
        
        // Condition 1: Total coins must be divisible by 3
        // Each move removes 3 coins total (1+2 or 2+1)
        if ((a + b) % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        
        // Condition 2: Both piles must be reachable
        // Let x be the number of moves of type 1 (remove 1 from left, 2 from right)
        // Let y be the number of moves of type 2 (remove 2 from left, 1 from right)
        // 
        // We have:
        // a = x + 2y  (coins removed from left pile)
        // b = 2x + y  (coins removed from right pile)
        // 
        // Solving: x = (2a - b)/3, y = (2b - a)/3
        // Both x and y must be non-negative integers
        
        ll x = 2 * a - b;
        ll y = 2 * b - a;
        
        if (x >= 0 && y >= 0 && x % 3 == 0 && y % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

/*
 * Mathematical Analysis:
 * 
 * Let's analyze the problem step by step:
 * 
 * 1. Each move removes exactly 3 coins total
 * 2. To empty both piles, total coins (a+b) must be divisible by 3
 * 3. Let's find the relationship between moves and final state
 * 
 * Let x = number of moves of type 1 (remove 1 from left, 2 from right)
 * Let y = number of moves of type 2 (remove 2 from left, 1 from right)
 * 
 * After all moves:
 * - Left pile: a - (x + 2y) = 0
 * - Right pile: b - (2x + y) = 0
 * 
 * This gives us:
 * x + 2y = a  ... (1)
 * 2x + y = b  ... (2)
 * 
 * Solving the system:
 * From (1): x = a - 2y
 * Substitute in (2): 2(a - 2y) + y = b
 *                   2a - 4y + y = b
 *                   2a - 3y = b
 *                   y = (2a - b)/3
 * 
 * Similarly: x = (2b - a)/3
 * 
 * For this to be valid:
 * 1. x and y must be non-negative
 * 2. x and y must be integers (divisible by 3)
 * 
 * Example:
 * Input: 
 * 3
 * 1 2
 * 2 2
 * 3 3
 * 
 * Output:
 * YES
 * NO
 * YES
 * 
 * Explanation:
 * 
 * Test 1: a=1, b=2
 * - Total: 1+2=3 (divisible by 3) ✓
 * - x = (2×1-2)/3 = 0/3 = 0 ✓
 * - y = (2×2-1)/3 = 3/3 = 1 ✓
 * - Move: 1 move of type 2 (remove 2 from left, 1 from right)
 * - Result: (1,2) → (1-2,2-1) = (-1,1) → invalid
 * Wait, this shows an issue with my logic.
 * 
 * Let me correct this:
 * 
 * The correct approach is simpler:
 * - Total coins must be divisible by 3
 * - The larger pile must not be more than twice the smaller pile
 * 
 * Corrected Solution:
 * 
 * int main() {
 *     int t;
 *     cin >> t;
 *     
 *     while (t--) {
 *         ll a, b;
 *         cin >> a >> b;
 *         
 *         if ((a + b) % 3 != 0) {
 *             cout << "NO\n";
 *             continue;
 *         }
 *         
 *         // Check if the larger pile is at most twice the smaller
 *         if (max(a, b) > 2 * min(a, b)) {
 *             cout << "NO\n";
 *         } else {
 *             cout << "YES\n";
 *         }
 *     }
 *     
 *     return 0;
 * }
 * 
 * Why this works:
 * - Each move removes coins in ratio 1:2 or 2:1
 * - If one pile is more than twice the other, we can't balance them
 * - The total must be divisible by 3 for complete removal
 * 
 * Test Cases:
 * Input: 1 2
 * Output: YES (can empty with 1 move: remove 1 from left, 2 from right)
 * 
 * Input: 2 2
 * Output: NO (total 4 not divisible by 3)
 * 
 * Input: 3 3
 * Output: YES (can empty with 2 moves)
 */
