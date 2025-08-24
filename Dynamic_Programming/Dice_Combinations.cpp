/*
 * CSES Problem Set - Dynamic Programming
 * Problem: Dice Combinations
 * 
 * Problem Statement:
 * Your task is to count the number of ways to construct sum n by throwing 
 * a dice one or more times. Each throw produces an outcome in {1,2,3,4,5,6}.
 * 
 * For example, if n=3, there are 4 ways:
 * 1+1+1, 1+2, 2+1, 3
 * 
 * Input: The only input line contains an integer n: the target sum.
 * Output: Print the number of ways modulo 10^9+7.
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: Use dynamic programming with recurrence dp[n] = sum(dp[n-i]) for i=1 to 6
 * Time Complexity: O(n) - Linear time DP
 * Space Complexity: O(n) - DP array
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> dp(n + 1, 0);
    
    // Base case: sum 0 can be achieved in 1 way (empty sequence)
    dp[0] = 1;
    
    // Fill DP table
    for (int sum = 1; sum <= n; sum++) {
        // Try adding each dice outcome (1 to 6)
        for (int dice = 1; dice <= 6; dice++) {
            if (sum >= dice) {
                dp[sum] = (dp[sum] + dp[sum - dice]) % MOD;
            }
        }
    }
    
    cout << dp[n] << "\n";
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * This is a classic dynamic programming problem. We need to find the number
 * of ways to achieve sum n using dice throws.
 * 
 * Key insight: To achieve sum n, the last dice throw must be one of {1,2,3,4,5,6}.
 * 
 * Recurrence relation:
 * dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6]
 * 
 * Where:
 * - dp[n-1]: Last throw was 1
 * - dp[n-2]: Last throw was 2
 * - dp[n-3]: Last throw was 3
 * - dp[n-4]: Last throw was 4
 * - dp[n-5]: Last throw was 5
 * - dp[n-6]: Last throw was 6
 * 
 * Base case: dp[0] = 1 (empty sequence)
 * 
 * Example for n = 3:
 * 
 * dp[0] = 1 (base case)
 * dp[1] = dp[0] = 1 (only way: throw 1)
 * dp[2] = dp[1] + dp[0] = 1 + 1 = 2 (ways: 1+1, 2)
 * dp[3] = dp[2] + dp[1] + dp[0] = 2 + 1 + 1 = 4
 * 
 * Verification:
 * Ways to get sum 3:
 * 1. 1+1+1 (last throw: 1, need dp[2] = 2 ways)
 * 2. 1+2 (last throw: 2, need dp[1] = 1 way)
 * 3. 2+1 (last throw: 1, need dp[2] = 2 ways)
 * 4. 3 (last throw: 3, need dp[0] = 1 way)
 * 
 * Total: 2 + 1 + 2 + 1 = 6? Wait, this shows an issue.
 * 
 * Let me correct this:
 * 
 * For n = 3:
 * - Last throw 1: need sum 2, dp[2] = 2 ways
 * - Last throw 2: need sum 1, dp[1] = 1 way
 * - Last throw 3: need sum 0, dp[0] = 1 way
 * 
 * Total: 2 + 1 + 1 = 4 ways ✓
 * 
 * Alternative Solution using recursive approach:
 * 
 * vector<ll> memo;
 * 
 * ll solve(int sum) {
 *     if (sum == 0) return 1;
 *     if (sum < 0) return 0;
 *     
 *     if (memo[sum] != -1) return memo[sum];
 *     
 *     ll ways = 0;
 *     for (int dice = 1; dice <= 6; dice++) {
 *         ways = (ways + solve(sum - dice)) % MOD;
 *     }
 *     
 *     return memo[sum] = ways;
 * }
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     memo.assign(n + 1, -1);
 *     ll result = solve(n);
 *     
 *     cout << result << "\n";
 *     return 0;
 * }
 * 
 * Space Optimization:
 * 
 * We can optimize space by using only the last 6 values:
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     if (n == 0) {
 *         cout << "1\n";
 *         return 0;
 *     }
 *     
 *     vector<ll> dp(7, 0);
 *     dp[0] = 1;  // dp[0]
 *     
 *     for (int sum = 1; sum <= n; sum++) {
 *         ll current = 0;
 *         for (int dice = 1; dice <= 6; dice++) {
 *             if (sum >= dice) {
 *                 current = (current + dp[(sum - dice) % 7]) % MOD;
 *             }
 *         }
 *         dp[sum % 7] = current;
 *     }
 *     
 *     cout << dp[n % 7] << "\n";
 *     return 0;
 * }
 * 
 * Test Cases:
 * 
 * Input: 1
 * Output: 1
 * 
 * Input: 2
 * Output: 2
 * 
 * Input: 3
 * Output: 4
 * 
 * Input: 4
 * Output: 8
 * 
 * Input: 5
 * Output: 16
 * 
 * Input: 6
 * Output: 32
 * 
 * Verification:
 * - n=1: 1 way (throw 1) ✓
 * - n=2: 2 ways (1+1, 2) ✓
 * - n=3: 4 ways (1+1+1, 1+2, 2+1, 3) ✓
 * - n=4: 8 ways ✓
 * - n=5: 16 ways ✓
 * - n=6: 32 ways ✓
 * 
 * Pattern: 1, 2, 4, 8, 16, 32, ...
 * This suggests dp[n] = 2^(n-1) for n ≥ 1
 * 
 * Mathematical proof:
 * For n ≥ 1, we can prove by induction that dp[n] = 2^(n-1)
 * 
 * Base case: n=1, dp[1] = 1 = 2^0 ✓
 * 
 * Inductive step: Assume dp[k] = 2^(k-1) for all k < n
 * 
 * dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6]
 *        = 2^(n-2) + 2^(n-3) + 2^(n-4) + 2^(n-5) + 2^(n-6) + 2^(n-7)
 *        = 2^(n-7) × (2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0)
 *        = 2^(n-7) × (32 + 16 + 8 + 4 + 2 + 1)
 *        = 2^(n-7) × 63
 * 
 * Wait, this doesn't give 2^(n-1). Let me check the pattern again.
 * 
 * Actually, the pattern is more complex. Let me verify with actual calculation:
 * 
 * dp[7] = dp[6] + dp[5] + dp[4] + dp[3] + dp[2] + dp[1]
 *        = 32 + 16 + 8 + 4 + 2 + 1 = 63
 * 
 * This doesn't follow 2^(n-1). The pattern is more intricate.
 * 
 * Time Complexity Analysis:
 * - Filling DP table: O(n)
 * - For each sum, we try 6 dice values: O(6n) = O(n)
 * - Total: O(n)
 * 
 * Space Complexity Analysis:
 * - DP array: O(n)
 * - Can be optimized to O(1) using rolling array
 * 
 * Applications:
 * - Probability problems
 * - Combinatorial counting
 * - Game theory
 * - Algorithm design
 * - Dynamic programming fundamentals
 */
