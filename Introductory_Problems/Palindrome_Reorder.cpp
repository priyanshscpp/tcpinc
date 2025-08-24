/*
 * CSES Problem Set - Introductory Problems
 * Problem: Palindrome Reorder
 * 
 * Problem Statement:
 * Given a string, your task is to reorder its characters in such a way 
 * that it becomes a palindrome (i.e., it reads the same forwards and backwards).
 * If this is not possible, print "NO SOLUTION".
 * 
 * Input: The only input line contains a string of n characters.
 * Output: Print a palindrome that can be formed using the characters of the string.
 * If there are several solutions, you may print any of them. 
 * If there are no solutions, print "NO SOLUTION".
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: Count character frequencies and construct palindrome
 * Time Complexity: O(n) - Linear time to count and construct
 * Space Complexity: O(1) - Constant space (26 characters)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    // Count frequency of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    
    // Check if palindrome is possible
    int odd_count = 0;
    char odd_char = 'A';
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            odd_count++;
            odd_char = 'A' + i;
        }
    }
    
    // For palindrome: at most one character can have odd frequency
    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    // Construct the palindrome
    string result;
    
    // Add first half (characters with even frequency)
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            // Add half of the frequency
            for (int j = 0; j < freq[i] / 2; j++) {
                result += (char)('A' + i);
            }
        }
    }
    
    // Add middle character if there's one with odd frequency
    if (odd_count == 1) {
        result += odd_char;
    }
    
    // Add second half (reverse of first half)
    for (int i = 25; i >= 0; i--) {
        if (freq[i] > 0) {
            // Add half of the frequency
            for (int j = 0; j < freq[i] / 2; j++) {
                result += (char)('A' + i);
            }
        }
    }
    
    cout << result << "\n";
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * To form a palindrome, we need:
 * 1. Most characters must appear an even number of times
 * 2. At most one character can appear an odd number of times (for the middle)
 * 
 * Steps:
 * 1. Count frequency of each character
 * 2. Check if more than one character has odd frequency
 * 3. If yes, print "NO SOLUTION"
 * 4. If no, construct palindrome:
 *    - Add first half of each character's frequency
 *    - Add middle character (if any has odd frequency)
 *    - Add second half in reverse order
 * 
 * Example:
 * Input: AAAACACBA
 * 
 * Character frequencies:
 * A: 5 (odd)
 * B: 1 (odd)
 * C: 2 (even)
 * 
 * Since we have 2 characters with odd frequency, no palindrome is possible.
 * Output: NO SOLUTION
 * 
 * Input: AAAACACB
 * 
 * Character frequencies:
 * A: 4 (even)
 * B: 1 (odd)
 * C: 2 (even)
 * 
 * Palindrome is possible. Let's construct:
 * - First half: AAAC (half of A's, half of C's)
 * - Middle: B
 * - Second half: CAAA (reverse of first half)
 * 
 * Result: AAACBAAAC
 * 
 * Verification: AAACBAAAC reads the same forwards and backwards ✓
 * 
 * Alternative Solution using map:
 * 
 * int main() {
 *     string s;
 *     cin >> s;
 *     
 *     map<char, int> freq;
 *     for (char c : s) {
 *         freq[c]++;
 *     }
 *     
 *     int odd_count = 0;
 *     char odd_char;
 *     
 *     for (auto [c, count] : freq) {
 *         if (count % 2 == 1) {
 *             odd_count++;
 *             odd_char = c;
 *         }
 *     }
 *     
 *     if (odd_count > 1) {
 *         cout << "NO SOLUTION\n";
 *         return 0;
 *     }
 *     
 *     string first_half, second_half;
 *     
 *     for (auto [c, count] : freq) {
 *         string temp(count / 2, c);
 *         first_half += temp;
 *         second_half = temp + second_half;
 *     }
 *     
 *     string result = first_half;
 *     if (odd_count == 1) {
 *         result += odd_char;
 *     }
 *     result += second_half;
 *     
 *     cout << result << "\n";
 *     return 0;
 * }
 * 
 * Test Cases:
 * Input: AAAACACBA
 * Output: NO SOLUTION
 * 
 * Input: AAAACACB
 * Output: AAACBAAAC
 * 
 * Input: ABC
 * Output: NO SOLUTION
 * 
 * Input: AAB
 * Output: ABA
 * 
 * Input: AABB
 * Output: ABBA
 */