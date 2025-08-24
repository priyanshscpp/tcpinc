/*
 * CSES Problem Set - Introductory Problems
 * Problem: Creating Strings
 * 
 * Problem Statement:
 * Given a string, your task is to generate all possible strings that 
 * can be created using its characters.
 * 
 * Input: The only input line contains a string of n characters.
 * Output: First, print an integer k: the number of possible strings. 
 * Then print k lines: the strings in alphabetical order.
 * 
 * Constraints: 1 ≤ n ≤ 8
 * 
 * Solution: Use next_permutation to generate all unique permutations
 * Time Complexity: O(n! × n) - Generate all permutations
 * Space Complexity: O(n!) - Store all unique permutations
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    // Sort the string to get lexicographically smallest permutation
    sort(s.begin(), s.end());
    
    vector<string> permutations;
    
    // Generate all permutations using next_permutation
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    
    // Print the number of unique strings
    cout << permutations.size() << "\n";
    
    // Print all permutations
    for (string perm : permutations) {
        cout << perm << "\n";
    }
    
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * The problem asks us to generate all possible strings that can be 
 * created using the characters of the input string. This is equivalent 
 * to finding all unique permutations of the string.
 * 
 * Steps:
 * 1. Sort the input string to get lexicographically smallest permutation
 * 2. Use next_permutation to generate all subsequent permutations
 * 3. Store each permutation in a vector
 * 4. Print the count and all permutations
 * 
 * Why next_permutation works:
 * - It generates the next lexicographically greater permutation
 * - It automatically handles duplicates (generates unique permutations)
 * - It returns false when no more permutations are possible
 * 
 * Example for input "AAB":
 * 
 * Initial sort: "AAB"
 * 
 * Permutations generated:
 * 1. "AAB" (initial)
 * 2. "ABA" (next_permutation)
 * 3. "BAA" (next_permutation)
 * 4. false (no more permutations)
 * 
 * Result: 3 unique strings
 * 
 * Alternative Solution using recursive approach:
 * 
 * void generate_permutations(string s, int start, set<string>& result) {
 *     if (start == s.length()) {
 *         result.insert(s);
 *         return;
 *     }
 *     
 *     for (int i = start; i < s.length(); i++) {
 *         // Swap characters
 *         swap(s[start], s[i]);
 *         
 *         // Recursively generate permutations for remaining positions
 *         generate_permutations(s, start + 1, result);
 *         
 *         // Backtrack: restore original string
 *         swap(s[start], s[i]);
 *     }
 * }
 * 
 * int main() {
 *     string s;
 *     cin >> s;
 *     
 *     set<string> result;
 *     generate_permutations(s, 0, result);
 *     
 *     cout << result.size() << "\n";
 *     for (string perm : result) {
 *         cout << perm << "\n";
 *     }
 *     
 *     return 0;
 * }
 * 
 * Mathematical Analysis:
 * 
 * For a string with n characters where:
 * - Character c₁ appears f₁ times
 * - Character c₂ appears f₂ times
 * - ...
 * - Character cₖ appears fₖ times
 * 
 * Total unique permutations = n! / (f₁! × f₂! × ... × fₖ!)
 * 
 * Example: "AAB" has n=3, A appears 2 times, B appears 1 time
 * Total permutations = 3! / (2! × 1!) = 6 / 2 = 3
 * 
 * Verification:
 * - "AAB": 3! / (2! × 1!) = 6 / 2 = 3 ✓
 * - "ABC": 3! / (1! × 1! × 1!) = 6 / 1 = 6 ✓
 * - "AAAA": 4! / 4! = 24 / 24 = 1 ✓
 * 
 * Test Cases:
 * Input: AAB
 * Output:
 * 3
 * AAB
 * ABA
 * BAA
 * 
 * Input: ABC
 * Output:
 * 6
 * ABC
 * ACB
 * BAC
 * BCA
 * CAB
 * CBA
 * 
 * Input: AAAA
 * Output:
 * 1
 * AAAA
 * 
 * Input: AB
 * Output:
 * 2
 * AB
 * BA
 * 
 * Time Complexity Analysis:
 * - next_permutation approach: O(n! × n)
 *   * n! permutations
 *   * Each permutation takes O(n) time to generate
 * - Recursive approach: O(n! × n)
 *   * n! recursive calls
 *   * Each call takes O(n) time for swapping
 * 
 * Space Complexity Analysis:
 * - Both approaches: O(n!)
 * - Need to store all unique permutations
 * - Each permutation takes O(n) space
 * 
 * Optimization:
 * - For strings with many duplicate characters, the number of unique 
 *   permutations is much smaller than n!
 * - Using a set in recursive approach automatically handles duplicates
 * - next_permutation also handles duplicates efficiently
 * 
 * Applications:
 * - Anagram generation
 * - Password cracking
 * - Combinatorial problems
 * - String manipulation algorithms
 */