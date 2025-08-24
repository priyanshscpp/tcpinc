/*
 * CSES Problem Set - Introductory Problems
 * Problem: Gray Code
 * 
 * Problem Statement:
 * A Gray code is a list of all 2^n bit strings of length n, where 
 * any two successive strings differ in exactly one bit (i.e., their 
 * Hamming distance is one).
 * 
 * Your task is to create a Gray code for a given length n.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print 2^n lines: the Gray code. You can print any valid solution.
 * 
 * Constraints: 1 ≤ n ≤ 16
 * 
 * Solution: Use recursive construction of Gray code
 * Time Complexity: O(2^n) - Must generate all 2^n strings
 * Space Complexity: O(2^n) - To store all generated strings
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> generate_gray_code(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    
    // Recursively generate Gray code for n-1
    vector<string> prev = generate_gray_code(n - 1);
    vector<string> result;
    
    // Add "0" prefix to all previous strings
    for (string s : prev) {
        result.push_back("0" + s);
    }
    
    // Add "1" prefix to all previous strings in reverse order
    for (int i = prev.size() - 1; i >= 0; i--) {
        result.push_back("1" + prev[i]);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> gray_code = generate_gray_code(n);
    
    // Print all Gray code strings
    for (string s : gray_code) {
        cout << s << "\n";
    }
    
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * Gray code can be constructed recursively using the following method:
 * 
 * 1. For n = 1: Gray code is ["0", "1"]
 * 2. For n > 1: 
 *    - Generate Gray code for n-1
 *    - Add "0" prefix to all strings
 *    - Add "1" prefix to all strings in reverse order
 * 
 * Why this works:
 * - The first half (with "0" prefix) maintains the property
 * - The second half (with "1" prefix) in reverse order ensures
 *   that the transition between halves differs in only one bit
 * 
 * Example for n = 2:
 * - n = 1: ["0", "1"]
 * - Add "0" prefix: ["00", "01"]
 * - Add "1" prefix in reverse: ["11", "10"]
 * - Result: ["00", "01", "11", "10"]
 * 
 * Verification:
 * - 00 → 01: differs in 1 bit ✓
 * - 01 → 11: differs in 1 bit ✓
 * - 11 → 10: differs in 1 bit ✓
 * - 10 → 00: differs in 1 bit ✓ (cyclic)
 * 
 * Example for n = 3:
 * - n = 2: ["00", "01", "11", "10"]
 * - Add "0" prefix: ["000", "001", "011", "010"]
 * - Add "1" prefix in reverse: ["110", "111", "101", "100"]
 * - Result: ["000", "001", "011", "010", "110", "111", "101", "100"]
 * 
 * Alternative Solution using iterative approach:
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     vector<string> gray_code;
 *     gray_code.push_back("0");
 *     gray_code.push_back("1");
 *     
 *     for (int i = 1; i < n; i++) {
 *         int size = gray_code.size();
 *         
 *         // Add "0" prefix to existing strings
 *         for (int j = 0; j < size; j++) {
 *             gray_code[j] = "0" + gray_code[j];
 *         }
 *         
 *         // Add "1" prefix to existing strings in reverse order
 *         for (int j = size - 1; j >= 0; j--) {
 *             gray_code.push_back("1" + gray_code[j].substr(1));
 *         }
 *     }
 *     
 *     for (string s : gray_code) {
 *         cout << s << "\n";
 *     }
 *     
 *     return 0;
 * }
 * 
 * Mathematical Properties:
 * 
 * 1. Hamming Distance: Any two consecutive strings differ in exactly one bit
 * 2. Cyclic: The first and last strings also differ in exactly one bit
 * 3. Reflection: The second half is a reflection of the first half with "1" prefix
 * 4. Uniqueness: Each bit string appears exactly once
 * 
 * Applications:
 * - Digital electronics (minimizes switching errors)
 * - Error detection and correction
 * - Analog-to-digital conversion
 * - Position encoders
 * 
 * Test Cases:
 * Input: 1
 * Output:
 * 0
 * 1
 * 
 * Input: 2
 * Output:
 * 00
 * 01
 * 11
 * 10
 * 
 * Input: 3
 * Output:
 * 000
 * 001
 * 011
 * 010
 * 110
 * 111
 * 101
 * 100
 * 
 * Verification for n = 2:
 * - 00 → 01: bit 1 changes ✓
 * - 01 → 11: bit 0 changes ✓
 * - 11 → 10: bit 1 changes ✓
 * - 10 → 00: bit 0 changes ✓
 */