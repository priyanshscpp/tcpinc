/*
 * CSES Problem Set - Introductory Problems
 * Problem: Chessboard and Queens
 * 
 * Problem Statement:
 * Your task is to place eight queens on a chessboard so that no two 
 * queens threaten each other. This means that no two queens can share 
 * the same row, column, or diagonal.
 * 
 * Input: The input consists of eight lines, and each line contains 
 * eight characters. Each character is either '.' (empty square) or 
 * '*' (blocked square). You cannot place queens on blocked squares.
 * 
 * Output: Print one integer: the number of valid queen configurations.
 * 
 * Constraints: The chessboard is 8×8
 * 
 * Solution: Use backtracking to find all valid queen placements
 * Time Complexity: O(8!) - Generate all valid permutations
 * Space Complexity: O(8) - Store queen positions
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<string> board(N);
int count = 0;

// Check if placing a queen at (row, col) is valid
bool is_valid(int row, int col, vector<int>& queens) {
    // Check if the square is blocked
    if (board[row][col] == '*') {
        return false;
    }
    
    // Check if any previous queen threatens this position
    for (int i = 0; i < row; i++) {
        int queen_col = queens[i];
        
        // Same column
        if (queen_col == col) {
            return false;
        }
        
        // Same diagonal (both main and anti-diagonal)
        if (abs(queen_col - col) == abs(i - row)) {
            return false;
        }
    }
    
    return true;
}

// Recursive function to place queens
void place_queens(int row, vector<int>& queens) {
    // Base case: all queens placed
    if (row == N) {
        count++;
        return;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < N; col++) {
        if (is_valid(row, col, queens)) {
            queens[row] = col;
            place_queens(row + 1, queens);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Read the chessboard
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    
    // Vector to store column positions of queens in each row
    vector<int> queens(N);
    
    // Start placing queens from row 0
    place_queens(0, queens);
    
    cout << count << "\n";
    return 0;
}

/*
 * Algorithm Explanation:
 * 
 * The Eight Queens puzzle is a classic constraint satisfaction problem.
 * We need to place 8 queens on an 8×8 chessboard so that no two queens
 * threaten each other.
 * 
 * Constraints:
 * 1. No two queens in the same row
 * 2. No two queens in the same column
 * 3. No two queens on the same diagonal
 * 4. Cannot place queens on blocked squares (*)
 * 
 * Approach:
 * 1. Place queens row by row (one queen per row)
 * 2. For each row, try placing the queen in each column
 * 3. Check if the placement is valid
 * 4. If valid, recursively place queens in the next row
 * 5. If all queens are placed, increment the count
 * 
 * Validation:
 * - Column check: No queen in the same column
 * - Diagonal check: No queen on the same diagonal
 * - Blocked square check: Cannot place on '*'
 * 
 * Example:
 * 
 * Input board:
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * 
 * One valid solution:
 * Q.......
 * ....Q...
 * ......Q.
 * .....Q..
 * ...Q....
 * .Q......
 * .......Q
 * ..Q.....
 * 
 * Alternative Solution using bit manipulation:
 * 
 * int solve(int row, int col_mask, int diag1_mask, int diag2_mask) {
 *     if (row == 8) return 1;
 *     
 *     int count = 0;
 *     for (int col = 0; col < 8; col++) {
 *         if (board[row][col] == '*') continue;
 *         
 *         int diag1 = row + col;
 *         int diag2 = row - col + 7;
 *         
 *         if (!(col_mask & (1 << col)) && 
 *             !(diag1_mask & (1 << diag1)) && 
 *             !(diag2_mask & (1 << diag2))) {
 *             
 *             count += solve(row + 1, 
 *                           col_mask | (1 << col),
 *                           diag1_mask | (1 << diag1),
 *                           diag2_mask | (1 << diag2));
 *         }
 *     }
 *     return count;
 * }
 * 
 * int main() {
 *     for (int i = 0; i < 8; i++) {
 *         cin >> board[i];
 *     }
 *     
 *     cout << solve(0, 0, 0, 0) << "\n";
 *     return 0;
 * }
 * 
 * Why backtracking works:
 * 
 * 1. **Systematic Search**: We try all possible valid placements
 * 2. **Early Pruning**: Invalid placements are rejected immediately
 * 3. **Constraint Propagation**: Each placement affects future choices
 * 4. **Complete Search**: We explore all valid configurations
 * 
 * Optimization Techniques:
 * 
 * 1. **Symmetry Breaking**: We can reduce search space by exploiting symmetries
 * 2. **Bit Manipulation**: Use bits to represent constraints efficiently
 * 3. **Forward Checking**: Check constraints before making assignments
 * 4. **Variable Ordering**: Place queens in rows with fewer valid positions first
 * 
 * Test Cases:
 * 
 * Test 1: Empty board
 * Input:
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * Output: 92 (standard 8-queens problem)
 * 
 * Test 2: Board with some blocked squares
 * Input:
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * ........
 * Output: 92
 * 
 * Test 3: Fully blocked board
 * Input:
 * ********
 * ********
 * ********
 * ********
 * ********
 * ********
 * ********
 * ********
 * Output: 0
 * 
 * Time Complexity Analysis:
 * - Worst case: O(8!) = O(40320)
 * - In practice, much faster due to constraint pruning
 * - Each queen placement reduces future choices
 * - Blocked squares further reduce search space
 * 
 * Space Complexity Analysis:
 * - O(8) for queen positions
 * - O(8²) for board storage
 * - O(8) for recursion stack
 * - Total: O(8²)
 * 
 * Applications:
 * - Constraint satisfaction problems
 * - Game theory
 * - Scheduling problems
 * - Resource allocation
 * - Artificial intelligence
 * 
 * Historical Context:
 * - First posed by Max Bezzel in 1848
 * - Solved by Franz Nauck in 1850
 * - 92 distinct solutions exist
 * - 12 fundamental solutions (others are rotations/reflections)
 */
