/*
 * CSES Problem Set - Introductory Problems
 * Problem: Repetitions
 * 
 * Problem Statement:
 * You are given a DNA sequence consisting of characters A, C, G, and T.
 * Your task is to find the longest repetition in the sequence. 
 * This is a maximum-length substring containing only one type of character.
 * 
 * Input: The only input line contains a string of n characters.
 * Output: Print one integer: the length of the longest repetition.
 * 
 * Constraints: 1 ≤ n ≤ 10^6
 * 
 * Solution: Linear scan to find longest consecutive sequence
 * Time Complexity: O(n) - Single pass through the string
 * Space Complexity: O(1) - Only storing current and max lengths
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int n = s.length();
    int max_repetition = 1;  // At least 1 character
    int current_repetition = 1;
    
    // Check consecutive characters
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // Same character, increment current repetition
            current_repetition++;
        } else {
            // Different character, update max and reset current
            max_repetition = max(max_repetition, current_repetition);
            current_repetition = 1;
        }
    }
    
    // Don't forget to check the last repetition
    max_repetition = max(max_repetition, current_repetition);
    
    cout << max_repetition << "\n";
    return 0;
}

/*
 * Example:
 * Input: ATTCGGGA
 * Output: 3
 * 
 * Explanation:
 * A: 1 repetition
 * TT: 2 repetitions
 * C: 1 repetition
 * GGG: 3 repetitions (longest)
 * A: 1 repetition
 * 
 * The longest repetition is "GGG" with length 3.
 * 
 * Test Cases:
 * Input: AAAA
 * Output: 4
 * 
 * Input: ACGT
 * Output: 1
 * 
 * Input: AATTCCGG
 * Output: 2
 */
