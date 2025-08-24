/*
 * CSES Problem Set - Introductory Problems
 * Problem: Tower of Hanoi
 * 
 * Problem Statement:
 * The Tower of Hanoi is a mathematical puzzle. It consists of three rods 
 * and a number of disks of different sizes which can slide onto any rod.
 * 
 * The puzzle starts with the disks in a neat stack in ascending order of 
 * size on one rod, the smallest at the top, thus making a conical shape.
 * 
 * The objective of the puzzle is to move the entire stack to another rod, 
 * obeying the following simple rules:
 * 1. Only one disk can be moved at a time.
 * 2. Each move consists of taking the upper disk from one of the stacks 
 *    and placing it on top of another stack or on an empty rod.
 * 3. No disk may be placed on top of a smaller disk.
 * 
 * Your task is to find the minimum number of moves required to solve 
 * the puzzle for n disks.
 * 
 * Input: The only input line contains an integer n.
 * Output: Print the minimum number of moves.
 * 
 * Constraints: 1 ≤ n ≤ 16
 * 
 * Solution: Use mathematical formula 2^n - 1
 * Time Complexity: O(1) - Constant time calculation
 * Space Complexity: O(1) - Constant space
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // The minimum number of moves for n disks is 2^n - 1
    // This can be proven by mathematical induction
    ll moves = (1LL << n) - 1;
    
    cout << moves << "\n";
    return 0;
}

/*
 * Mathematical Proof:
 * 
 * Let T(n) be the minimum number of moves required for n disks.
 * 
 * Base case: n = 1
 * - T(1) = 1 (move disk from source to destination)
 * - 2¹ - 1 = 2 - 1 = 1 ✓
 * 
 * Inductive step: Assume T(k) = 2^k - 1 for all k < n
 * 
 * For n disks, the optimal solution requires:
 * 1. Move the top n-1 disks from source to auxiliary rod: T(n-1) moves
 * 2. Move the largest disk from source to destination: 1 move
 * 3. Move the n-1 disks from auxiliary to destination: T(n-1) moves
 * 
 * Total: T(n) = T(n-1) + 1 + T(n-1) = 2 × T(n-1) + 1
 * 
 * By induction hypothesis: T(n-1) = 2^(n-1) - 1
 * 
 * Therefore: T(n) = 2 × (2^(n-1) - 1) + 1
 *                   = 2^n - 2 + 1
 *                   = 2^n - 1
 * 
 * Alternative Solution using recursion:
 * 
 * ll hanoi_moves(int n) {
 *     if (n == 1) return 1;
 *     return 2 * hanoi_moves(n - 1) + 1;
 * }
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     cout << hanoi_moves(n) << "\n";
 *     return 0;
 * }
 * 
 * Recursive Solution with Move Sequence:
 * 
 * void hanoi(int n, char source, char auxiliary, char destination) {
 *     if (n == 1) {
 *         cout << source << " " << destination << "\n";
 *         return;
 *     }
 *     
 *     // Move n-1 disks from source to auxiliary
 *     hanoi(n-1, source, destination, auxiliary);
 *     
 *     // Move the largest disk from source to destination
 *     cout << source << " " << destination << "\n";
 *     
 *     // Move n-1 disks from auxiliary to destination
 *     hanoi(n-1, auxiliary, source, destination);
 * }
 * 
 * int main() {
 *     int n;
 *     cin >> n;
 *     
 *     // Print number of moves
 *     cout << (1LL << n) - 1 << "\n";
 *     
 *     // Print the sequence of moves
 *     hanoi(n, '1', '2', '3');
 *     
 *     return 0;
 * }
 * 
 * Example for n = 3:
 * 
 * Initial state:
 * Rod 1: [3, 2, 1] (largest at bottom)
 * Rod 2: []
 * Rod 3: []
 * 
 * Move sequence:
 * 1. Move disk 1 from rod 1 to rod 3
 * 2. Move disk 2 from rod 1 to rod 2
 * 3. Move disk 1 from rod 3 to rod 2
 * 4. Move disk 3 from rod 1 to rod 3
 * 5. Move disk 1 from rod 2 to rod 1
 * 6. Move disk 2 from rod 2 to rod 3
 * 7. Move disk 1 from rod 1 to rod 3
 * 
 * Total moves: 7 = 2³ - 1
 * 
 * Final state:
 * Rod 1: []
 * Rod 2: []
 * Rod 3: [3, 2, 1]
 * 
 * Test Cases:
 * Input: 1
 * Output: 1
 * 
 * Input: 2
 * Output: 3
 * 
 * Input: 3
 * Output: 7
 * 
 * Input: 4
 * Output: 15
 * 
 * Input: 5
 * Output: 31
 * 
 * Verification:
 * - 2¹ - 1 = 1 ✓
 * - 2² - 1 = 3 ✓
 * - 2³ - 1 = 7 ✓
 * - 2⁴ - 1 = 15 ✓
 * - 2⁵ - 1 = 31 ✓
 * 
 * Time Complexity Analysis:
 * - Mathematical formula: O(1)
 * - Recursive approach: O(n) due to recursion depth
 * - Iterative approach: O(n) due to loop
 * 
 * Space Complexity Analysis:
 * - Mathematical formula: O(1)
 * - Recursive approach: O(n) due to recursion stack
 * - Iterative approach: O(1)
 * 
 * Applications:
 * - Algorithm design and analysis
 * - Recursion teaching
 * - Mathematical induction
 * - Problem-solving strategies
 */