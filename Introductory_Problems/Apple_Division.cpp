/*
 * CSES Problem Set - Introductory Problems
 * Problem: Apple Division
 * 
 * Problem Statement:
 * There are n apples with known weights. Your task is to divide the 
 * apples into two groups so that the difference between the weights 
 * of the groups is as small as possible.
 * 
 * Input: The first input line contains an integer n: the number of apples.
 * The next line contains n integers p1,p2,…,pn: the weight of each apple.
 * 
 * Output: Print one integer: the minimum possible difference between 
 * the group weights.
 * 
 * Constraints: 1 ≤ n ≤ 20, 1 ≤ pi ≤ 10^9
 * 
 * Solution: Use bitmask to try all possible subset combinations
 * Time Complexity: O(2^n) - Try all possible subsets
 * Space Complexity: O(n) - Store apple weights
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    ll total_sum = 0;
    for (ll weight : weights) {
        total_sum += weight;
    }
    
    ll min_diff = total_sum;  // Initialize with worst case
    
    // Try all possible subsets using bitmask
    // For n apples, we have 2^n possible ways to divide them
    for (int mask = 0; mask < (1 << n); mask++) {
        ll group1_sum = 0;
        
        // Calculate sum of group 1 based on bitmask
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1_sum += weights[i];
            }
        }
        
        // Calculate sum of group 2
        ll group2_sum = total_sum - group1_sum;
        
        // Update minimum difference
        min_diff = min(min_diff, abs(group1_sum - group2_sum));
    }
    
    cout << min_diff << "\n";
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * The problem asks us to divide n apples into two groups such that 
 * the difference between their total weights is minimized.
 * 
 * Key insight: We only need to consider one group's weight because:
 * - If group 1 has weight w, then group 2 has weight (total - w)
 * - Difference = |w - (total - w)| = |2w - total|
 * 
 * Approach:
 * 1. Calculate total weight of all apples
 * 2. Try all possible subsets of apples for group 1
 * 3. For each subset, calculate the difference
 * 4. Keep track of the minimum difference found
 * 
 * Why bitmask works:
 * - Each bit in the mask represents whether an apple goes to group 1
 * - For n apples, we have 2^n possible combinations
 * - Bit 0: apple 0 goes to group 1 if set
 * - Bit 1: apple 1 goes to group 1 if set
 * - And so on...
 * 
 * Example for n = 3, weights = [3, 2, 7]:
 * 
 * Total weight = 3 + 2 + 7 = 12
 * 
 * Bitmask analysis:
 * 000 (0): group1 = [], group2 = [3,2,7], diff = |0-12| = 12
 * 001 (1): group1 = [3], group2 = [2,7], diff = |3-9| = 6
 * 010 (2): group1 = [2], group2 = [3,7], diff = |2-10| = 8
 * 011 (3): group1 = [3,2], group2 = [7], diff = |5-7| = 2
 * 100 (4): group1 = [7], group2 = [3,2], diff = |7-5| = 2
 * 101 (5): group1 = [3,7], group2 = [2], diff = |10-2| = 8
 * 110 (6): group1 = [2,7], group2 = [3], diff = |9-3| = 6
 * 111 (7): group1 = [3,2,7], group2 = [], diff = |12-0| = 12
 * 
 * Minimum difference = 2 (achieved by masks 011 and 100)
 * 
 * Alternative Solution using recursive approach:
 * 
 * ll min_diff = LLONG_MAX;
 * 
 * void try_division(int index, ll group1_sum, ll group2_sum, 
 *                   const vector<ll>& weights) {
 *     if (index == weights.size()) {
 *         min_diff = min(min_diff, abs(group1_sum - group2_sum));
 *         return;
 *     }
 *     
 *     // Add current apple to group 1
 *     try_division(index + 1, group1_sum + weights[index], group2_sum, weights);
 *     
 *     // Add current apple to group 2
 *     try_division(index + 1, group1_sum, group2_sum + weights[index], weights);
 * }
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     vector<ll> weights(n);
 *     for (int i = 0; i < n; i++) {
 *         cin >> weights[i];
 *     }
 *     
 *     try_division(0, 0, 0, weights);
 *     cout << min_diff << "\n";
 *     
 *     return 0;
 * }
 * 
 * Optimization:
 * 
 * We can optimize by stopping early if we find a difference of 0:
 * 
 * for (int mask = 0; mask < (1 << n); mask++) {
 *     ll group1_sum = 0;
 *     
 *     for (int i = 0; i < n; i++) {
 *         if (mask & (1 << i)) {
 *             group1_sum += weights[i];
 *         }
 *     }
 *     
 *     ll group2_sum = total_sum - group1_sum;
 *     ll diff = abs(group1_sum - group2_sum);
 *     
 *     min_diff = min(min_diff, diff);
 *     
 *     // Early termination if perfect division found
 *     if (min_diff == 0) break;
 * }
 * 
 * Test Cases:
 * Input: 
 * 3
 * 3 2 7
 * Output: 2
 * 
 * Input: 
 * 4
 * 1 2 3 4
 * Output: 0
 * 
 * Input: 
 * 2
 * 10 20
 * Output: 10
 * 
 * Input: 
 * 1
 * 5
 * Output: 5
 * 
 * Verification:
 * 
 * Test 1: [3,2,7] → groups [3,2] and [7], diff = |5-7| = 2 ✓
 * Test 2: [1,2,3,4] → groups [1,4] and [2,3], diff = |5-5| = 0 ✓
 * Test 3: [10,20] → groups [10] and [20], diff = |10-20| = 10 ✓
 * Test 4: [5] → groups [] and [5], diff = |0-5| = 5 ✓
 * 
 * Time Complexity Analysis:
 * - Bitmask approach: O(2^n × n)
 *   * 2^n possible subsets
 *   * Each subset takes O(n) time to calculate sum
 * - Recursive approach: O(2^n)
 *   * 2^n recursive calls
 *   * Each call takes O(1) time
 * 
 * Space Complexity Analysis:
 * - Both approaches: O(n)
 * - Need to store apple weights
 * - Recursive approach uses O(n) stack space
 * 
 * When to use each approach:
 * - Bitmask: When you need to process all subsets systematically
 * - Recursive: When you want cleaner code and don't need subset details
 * - Both are equivalent for this problem
 * 
 * Applications:
 * - Partition problems
 * - Load balancing
 * - Resource allocation
 * - Knapsack variations
 */