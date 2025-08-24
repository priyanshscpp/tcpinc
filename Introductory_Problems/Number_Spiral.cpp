/*
 * CSES Problem Set - Introductory Problems
 * Problem: Number Spiral
 * 
 * Problem Statement:
 * A number spiral is an infinite grid whose upper-left square has number 1. 
 * Here are the first five layers of the spiral:
 * 
 * 1  2  9  10 25
 * 4  3  8  11 24
 * 5  6  7  12 23
 * 16 15 14 13 22
 * 17 18 19 20 21
 * 
 * Your task is to find out the number in row y and column x.
 * 
 * Input: The first input line contains an integer t: the number of tests.
 * After this, there are t lines, each containing integers y and x.
 * 
 * Output: For each test, print the number in row y and column x.
 * 
 * Constraints: 1 ≤ t ≤ 10^5, 1 ≤ y,x ≤ 10^9
 * 
 * Solution: Mathematical formula based on spiral pattern
 * Time Complexity: O(t) - Constant time per test case
 * Space Complexity: O(1) - No extra space needed
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll y, x;
        cin >> y >> x;
        
        // Find the layer (maximum of row and column)
        ll layer = max(y, x);
        
        // Calculate the number at the bottom-right corner of this layer
        ll corner = layer * layer;
        
        ll result;
        
        if (layer % 2 == 0) {
            // Even layer: numbers increase from bottom-right to top-left
            if (y <= x) {
                // In upper triangle of the layer
                result = corner - (layer - y);
            } else {
                // In lower triangle of the layer
                result = corner - (2 * layer - y - x);
            }
        } else {
            // Odd layer: numbers increase from top-left to bottom-right
            if (y <= x) {
                // In upper triangle of the layer
                result = corner - (2 * layer - y - x);
            } else {
                // In lower triangle of the layer
                result = corner - (layer - x);
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}

/*
 * Alternative Solution using mathematical analysis:
 * 
 * For any position (y, x), we can find the layer as max(y, x).
 * The number at position (y, x) can be calculated using the layer
 * and the relative position within that layer.
 * 
 * Example:
 * Input: 
 * 3
 * 2 3
 * 1 1
 * 4 2
 * 
 * Output:
 * 8
 * 1
 * 15
 * 
 * Explanation:
 * 
 * Test 1: (2, 3) - Layer 3 (odd)
 * Layer 3: 5 6 7
 *          4 3 8
 *          9 2 1
 * Position (2, 3) = 8
 * 
 * Test 2: (1, 1) - Layer 1 (odd)
 * Layer 1: 1
 * Position (1, 1) = 1
 * 
 * Test 3: (4, 2) - Layer 4 (even)
 * Layer 4: 16 15 14 13
 *          17 4  3  12
 *          18 5  6  11
 *          19 20 21 22
 * Position (4, 2) = 20
 * 
 * Pattern Analysis:
 * - Layer 1: 1×1 grid, starts at 1
 * - Layer 2: 2×2 grid, starts at 4
 * - Layer 3: 3×3 grid, starts at 9
 * - Layer 4: 4×4 grid, starts at 16
 * - Layer n: n×n grid, starts at n²
 */
