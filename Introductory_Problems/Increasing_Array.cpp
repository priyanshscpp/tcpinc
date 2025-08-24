/*
 * CSES Problem Set - Introductory Problems
 * Problem: Increasing Array
 * 
 * Problem Statement:
 * You are given an array of n integers. You want to modify the array 
 * so that it is increasing, i.e., every element is at least as large 
 * as the previous element.
 * 
 * On each turn, you may increase the value of any element by one. 
 * What is the minimum number of turns required?
 * 
 * Input: The first input line contains an integer n: the size of the array.
 * The next line contains n integers x1,x2,…,xn: the contents of the array.
 * 
 * Output: Print the minimum number of turns.
 * 
 * Constraints: 1 ≤ n ≤ 2⋅10^5, 1 ≤ xi ≤ 10^9
 * 
 * Solution: Greedy approach - make each element at least as large as previous
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - Only storing the result
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll turns = 0;
    
    // Make each element at least as large as the previous one
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            // Need to increase current element
            ll needed = a[i-1] - a[i];
            turns += needed;
            a[i] = a[i-1];  // Update current element
        }
    }
    
    cout << turns << "\n";
    return 0;
}

/*
 * Example:
 * Input: 
 * 5
 * 3 2 5 1 7
 * 
 * Output: 5
 * 
 * Explanation:
 * Initial array: [3, 2, 5, 1, 7]
 * 
 * Step 1: 2 < 3, need to increase 2 by 1 → [3, 3, 5, 1, 7] (1 turn)
 * Step 2: 5 ≥ 3, no change needed → [3, 3, 5, 1, 7] (0 turns)
 * Step 3: 1 < 5, need to increase 1 by 4 → [3, 3, 5, 5, 7] (4 turns)
 * Step 4: 7 ≥ 5, no change needed → [3, 3, 5, 5, 7] (0 turns)
 * 
 * Total turns: 1 + 0 + 4 + 0 = 5
 * Final array: [3, 3, 5, 5, 7] (increasing)
 * 
 * Test Cases:
 * Input: 3
 *        1 1 1
 * Output: 0
 * 
 * Input: 4
 *        1 2 3 4
 * Output: 0
 * 
 * Input: 3
 *        3 2 1
 * Output: 3
 */
