/*
 * CSES Problem Set - Introductory Problems
 * Problem: Trailing Zeros
 * 
 * Problem Statement:
 * Your task is to calculate the number of trailing zeros in n! (n factorial).
 * 
 * Input: The only input line contains an integer n.
 * Output: Print the number of trailing zeros.
 * 
 * Constraints: 1 ≤ n ≤ 10^9
 * 
 * Solution: Count factors of 5 in factorial (since 2s are more abundant)
 * Time Complexity: O(log n) - Count factors of 5
 * Space Complexity: O(1) - Constant space
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    // Count trailing zeros in n!
    // A trailing zero is created by a factor of 10
    // 10 = 2 × 5, so we need both 2 and 5 as factors
    // In factorial, there are always more factors of 2 than 5
    // So we only need to count factors of 5
    
    ll count = 0;
    
    // Count factors of 5, 25, 125, 625, etc.
    // Each power of 5 contributes additional factors
    for (ll i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    
    cout << count << "\n";
    return 0;
}

/*
 * Mathematical Explanation:
 * 
 * To find trailing zeros in n!, we need to count factors of 10.
 * Since 10 = 2 × 5, we need both 2 and 5 as factors.
 * 
 * In n!, there are always more factors of 2 than 5 because:
 * - Every even number contributes at least one factor of 2
 * - Only multiples of 5 contribute factors of 5
 * - So we only need to count factors of 5
 * 
 * How to count factors of 5 in n!:
 * 
 * 1. Count numbers divisible by 5: ⌊n/5⌋
 * 2. Count numbers divisible by 25: ⌊n/25⌋ (each contributes an extra 5)
 * 3. Count numbers divisible by 125: ⌊n/125⌋ (each contributes another 5)
 * 4. Continue for higher powers of 5
 * 
 * Total factors of 5 = ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + ...
 * 
 * Example for n = 25:
 * - Numbers divisible by 5: 5, 10, 15, 20, 25 → ⌊25/5⌋ = 5
 * - Numbers divisible by 25: 25 → ⌊25/25⌋ = 1
 * - Total factors of 5: 5 + 1 = 6
 * 
 * Verification:
 * 25! = 15511210043330985984000000
 * Number of trailing zeros: 6 ✓
 * 
 * Alternative Solution using a more explicit approach:
 * 
 * int main() {
 *     ll n;
 *     cin >> n;
 *     
 *     ll count = 0;
 *     ll power = 5;
 *     
 *     while (power <= n) {
 *         count += n / power;
 *         power *= 5;
 *     }
 *     
 *     cout << count << "\n";
 *     return 0;
 * }
 * 
 * Test Cases:
 * Input: 1
 * Output: 0
 * 
 * Input: 5
 * Output: 1
 * 
 * Input: 10
 * Output: 2
 * 
 * Input: 25
 * Output: 6
 * 
 * Input: 100
 * Output: 24
 * 
 * Verification:
 * - 1! = 1 → 0 trailing zeros ✓
 * - 5! = 120 → 1 trailing zero ✓
 * - 10! = 3628800 → 2 trailing zeros ✓
 * - 25! = ...000000 → 6 trailing zeros ✓
 * - 100! = ...000000000000000000000000 → 24 trailing zeros ✓
 * 
 * Time Complexity Analysis:
 * - We iterate through powers of 5: 5, 25, 125, 625, ...
 * - Number of iterations = log₅(n)
 * - Each iteration takes O(1) time
 * - Total time: O(log n)
 */
