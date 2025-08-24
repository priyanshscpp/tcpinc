/*
 * CSES Problem Set - Introductory Problems
 * Problem: Missing Number
 * 
 * Problem Statement:
 * You are given all numbers between 1,2,…,n except one. 
 * Your task is to find the missing number.
 * 
 * Input: The first input line contains an integer n.
 * The second line contains n−1 numbers. Each number is distinct and 
 * between 1 and n (inclusive).
 * 
 * Output: Print the missing number.
 * 
 * Constraints: 2 ≤ n ≤ 2⋅10^5
 * 
 * Solution: Use mathematical formula to find missing number
 * Time Complexity: O(n) - Linear scan to read input
 * Space Complexity: O(1) - Only storing sum
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    // Calculate expected sum of numbers from 1 to n
    ll expected_sum = (n * (n + 1)) / 2;
    
    // Read n-1 numbers and subtract from expected sum
    ll actual_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        ll num;
        cin >> num;
        actual_sum += num;
    }
    
    // The missing number is the difference
    ll missing_number = expected_sum - actual_sum;
    
    cout << missing_number << "\n";
    return 0;
}

/*
 * Alternative Solution using XOR:
 * 
 * int main() {
 *     ios_base::sync_with_stdio(false);
 *     cin.tie(NULL);
 *     
 *     int n;
 *     cin >> n;
 *     
 *     int xor_sum = 0;
 *     // XOR all numbers from 1 to n
 *     for (int i = 1; i <= n; i++) {
 *         xor_sum ^= i;
 *     }
 *     
 *     // XOR with all given numbers
 *     for (int i = 0; i < n - 1; i++) {
 *         int num;
 *         cin >> num;
 *         xor_sum ^= num;
 *     }
 *     
 *     cout << xor_sum << "\n";
 *     return 0;
 * }
 * 
 * Example:
 * Input: 
 * 5
 * 2 3 1 5
 * 
 * Output: 4
 * 
 * Explanation:
 * Numbers from 1 to 5: 1, 2, 3, 4, 5
 * Given numbers: 2, 3, 1, 5
 * Missing number: 4
 */
