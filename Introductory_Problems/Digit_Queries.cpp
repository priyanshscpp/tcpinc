/*
 * CSES Problem Set - Introductory Problems
 * Problem: Digit Queries
 * 
 * Problem Statement:
 * Consider an infinite string that consists of all positive integers 
 * in increasing order: 12345678910111213141516171819202122232425...
 * 
 * Your task is to answer q queries of the form: "What is the digit 
 * at position k in this string?"
 * 
 * Input: The first input line contains an integer q: the number of queries.
 * After this, there are q lines, each containing an integer k.
 * 
 * Output: For each query, print the digit at position k.
 * 
 * Constraints: 1 ≤ q ≤ 1000, 1 ≤ k ≤ 10^18
 * 
 * Solution: Use mathematical analysis to find the digit at position k
 * Time Complexity: O(q × log k) - Binary search for each query
 * Space Complexity: O(1) - Constant space
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Find the digit at position k in the infinite string
int find_digit(ll k) {
    // Find which number contains the k-th digit
    ll current_pos = 0;
    ll digits = 1;  // Number of digits in current numbers
    ll start_num = 1;  // First number with 'digits' digits
    
    // Find the range where position k falls
    while (true) {
        // Calculate how many numbers have 'digits' digits
        ll numbers_in_range = 9 * start_num;
        
        // Calculate total digits contributed by this range
        ll total_digits = numbers_in_range * digits;
        
        if (current_pos + total_digits >= k) {
            // Position k is in this range
            break;
        }
        
        current_pos += total_digits;
        digits++;
        start_num *= 10;
    }
    
    // Find the specific number containing position k
    ll remaining_pos = k - current_pos - 1;
    ll number_index = remaining_pos / digits;
    ll digit_in_number = remaining_pos % digits;
    
    ll target_number = start_num + number_index;
    
    // Extract the specific digit
    string num_str = to_string(target_number);
    return num_str[digit_in_number] - '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    
    while (q--) {
        ll k;
        cin >> k;
        
        int digit = find_digit(k);
        cout << digit << "\n";
    }
    
    return 0;
}

/*
 * Mathematical Analysis:
 * 
 * The infinite string is constructed by concatenating all positive integers:
 * 12345678910111213141516171819202122232425...
 * 
 * To find the digit at position k, we need to:
 * 1. Determine which number contains the k-th digit
 * 2. Find the specific digit within that number
 * 
 * Let's analyze the structure:
 * 
 * Numbers with 1 digit (1-9): 9 numbers × 1 digit = 9 digits
 * Numbers with 2 digits (10-99): 90 numbers × 2 digits = 180 digits
 * Numbers with 3 digits (100-999): 900 numbers × 3 digits = 2700 digits
 * Numbers with 4 digits (1000-9999): 9000 numbers × 4 digits = 36000 digits
 * And so on...
 * 
 * General formula:
 * - Numbers with d digits: 9 × 10^(d-1)
 * - Total digits contributed: 9 × 10^(d-1) × d
 * 
 * Example for k = 15:
 * 
 * 1. Check 1-digit numbers: 9 digits < 15, continue
 * 2. Check 2-digit numbers: 9 + 180 = 189 digits > 15, found range
 * 3. Position 15 is in 2-digit numbers
 * 4. Remaining position: 15 - 9 - 1 = 5
 * 5. Number index: 5 / 2 = 2 (0-indexed)
 * 6. Target number: 10 + 2 = 12
 * 7. Digit position: 5 % 2 = 1
 * 8. Result: digit at position 1 in "12" = 2
 * 
 * Verification:
 * String: 12345678910111213141516171819202122232425...
 * Position: 123456789012345678901234567890123456789...
 * At position 15: digit = 2 ✓
 * 
 * Alternative Solution using binary search:
 * 
 * ll find_number_with_digits(ll target_digits) {
 *     ll left = 1, right = 1e18;
 *     ll result = 0;
 *     
 *     while (left <= right) {
 *         ll mid = left + (right - left) / 2;
 *         
 *         ll total_digits = 0;
 *         ll temp = mid;
 *         ll digits = 0;
 *         
 *         while (temp > 0) {
 *             digits++;
 *             temp /= 10;
 *         }
 *         
 *         // Calculate digits up to mid
 *         ll current = 1;
 *         ll power = 1;
 *         
 *         for (int d = 1; d < digits; d++) {
 *             total_digits += 9 * power * d;
 *             power *= 10;
 *         }
 *         
 *         total_digits += (mid - power + 1) * digits;
 *         
 *         if (total_digits >= target_digits) {
 *             result = mid;
 *             right = mid - 1;
 *         } else {
 *             left = mid + 1;
 *         }
 *     }
 *     
 *     return result;
 * }
 * 
 * Test Cases:
 * 
 * Input:
 * 3
 * 7
 * 19
 * 12
 * 
 * Output:
 * 7
 * 4
 * 1
 * 
 * Explanation:
 * 
 * Query 1: k = 7
 * String: 12345678910111213141516171819202122232425...
 * Position 7: digit = 7 ✓
 * 
 * Query 2: k = 19
 * String: 12345678910111213141516171819202122232425...
 * Position 19: digit = 4 ✓
 * 
 * Query 3: k = 12
 * String: 12345678910111213141516171819202122232425...
 * Position 12: digit = 1 ✓
 * 
 * Edge Cases:
 * 
 * 1. k = 1: First digit = 1
 * 2. k = 9: Last digit of 1-digit numbers = 9
 * 3. k = 10: First digit of 2-digit numbers = 1
 * 4. k = 11: Second digit of 2-digit numbers = 0
 * 5. k = 189: Last digit of 2-digit numbers = 9
 * 6. k = 190: First digit of 3-digit numbers = 1
 * 
 * Time Complexity Analysis:
 * 
 * For each query:
 * - Finding the digit range: O(log k)
 * - Extracting the digit: O(log k) (string conversion)
 * - Total per query: O(log k)
 * - Overall: O(q × log k)
 * 
 * Space Complexity Analysis:
 * - O(1) additional space
 * - Only storing intermediate calculations
 * - String conversion uses temporary space
 * 
 * Optimization:
 * 
 * We can optimize by precomputing ranges:
 * 
 * vector<ll> digit_ranges;
 * void precompute_ranges() {
 *     ll current = 0;
 *     ll digits = 1;
 *     ll start_num = 1;
 *     
 *     while (current < 1e18) {
 *         digit_ranges.push_back(current);
 *         current += 9 * start_num * digits;
 *         digits++;
 *         start_num *= 10;
 *     }
 * }
 * 
 * Applications:
 * - Number theory problems
 * - Pattern recognition
 * - Mathematical sequences
 * - Educational problems
 * - Algorithm design
 */
