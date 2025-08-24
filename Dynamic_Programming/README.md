# 🔗 Dynamic Programming

This directory contains solutions to the 19 dynamic programming problems from the CSES Problem Set. These problems teach fundamental DP concepts and techniques.

## 🎯 Problems Overview

| # | Problem Name | Difficulty | Topic | Solution |
|---|--------------|------------|-------|----------|
| 1 | [Dice Combinations](Dice_Combinations.cpp) | ★★☆☆☆ | Basic DP | [View Solution](Dice_Combinations.cpp) |
| 2 | [Minimizing Coins](Minimizing_Coins.cpp) | ★★☆☆☆ | Coin Change | [View Solution](Minimizing_Coins.cpp) |
| 3 | [Coin Combinations I](Coin_Combinations_I.cpp) | ★★☆☆☆ | Unbounded Knapsack | [View Solution](Coin_Combinations_I.cpp) |
| 4 | [Coin Combinations II](Coin_Combinations_II.cpp) | ★★★☆☆ | Bounded Knapsack | [View Solution](Coin_Combinations_II.cpp) |
| 5 | [Removing Digits](Removing_Digits.cpp) | ★★★☆☆ | Digit DP | [View Solution](Removing_Digits.cpp) |
| 6 | [Grid Paths](Grid_Paths.cpp) | ★★★☆☆ | 2D DP | [View Solution](Grid_Paths.cpp) |
| 7 | [Book Shop](Book_Shop.cpp) | ★★★☆☆ | Knapsack | [View Solution](Book_Shop.cpp) |
| 8 | [Money Sums](Money_Sums.cpp) | ★★★☆☆ | Subset Sum | [View Solution](Money_Sums.cpp) |
| 9 | [Removal Game](Removal_Game.cpp) | ★★★☆☆ | Game Theory + DP | [View Solution](Removal_Game.cpp) |
| 10 | [Two Sets II](Two_Sets_II.cpp) | ★★★☆☆ | Subset Sum | [View Solution](Two_Sets_II.cpp) |
| 11 | [Beautiful Permutation](Beautiful_Permutation.cpp) | ★★★☆☆ | Permutation DP | [View Solution](Beautiful_Permutation.cpp) |
| 12 | [Go Go Turtle](Go_Go_Turtle.cpp) | ★★★★☆ | Advanced DP | [View Solution](Go_Go_Turtle.cpp) |
| 13 | [Decreasing String](Decreasing_String.cpp) | ★★★★☆ | String DP | [View Solution](Decreasing_String.cpp) |
| 14 | [School Excursion](School_Excursion.cpp) | ★★★★☆ | Knapsack with Groups | [View Solution](School_Excursion.cpp) |
| 15 | [Counting Numbers](Counting_Numbers.cpp) | ★★★★☆ | Digit DP | [View Solution](Counting_Numbers.cpp) |
| 16 | [Counting Numbers II](Counting_Numbers_II.cpp) | ★★★★★ | Advanced Digit DP | [View Solution](Counting_Numbers_II.cpp) |
| 17 | [Counting Numbers III](Counting_Numbers_III.cpp) | ★★★★★ | Very Advanced Digit DP | [View Solution](Counting_Numbers_III.cpp) |
| 18 | [Counting Numbers IV](Counting_Numbers_IV.cpp) | ★★★★★ | Extremely Advanced Digit DP | [View Solution](Counting_Numbers_IV.cpp) |
| 19 | [Counting Numbers V](Counting_Numbers_V.cpp) | ★★★★★ | Ultimate Digit DP | [View Solution](Counting_Numbers_V.cpp) |

## 🚀 Learning Objectives

After solving these problems, you should be comfortable with:
- Basic DP concepts and memoization
- State transitions and recurrence relations
- 1D and 2D DP problems
- Knapsack variations (bounded, unbounded, with groups)
- Digit DP techniques
- Game theory with DP
- String DP problems
- Advanced optimization techniques

## 💡 Key DP Concepts

### 1. **State Definition**
- Clearly define what information you need to remember
- Keep states as simple as possible
- Avoid redundant information

### 2. **Recurrence Relation**
- Express current state in terms of smaller subproblems
- Ensure all base cases are covered
- Verify the relation is correct

### 3. **Memoization vs Tabulation**
- **Memoization**: Top-down approach, recursive with memory
- **Tabulation**: Bottom-up approach, iterative
- Choose based on problem constraints

### 4. **Space Optimization**
- Often only need previous states
- Use rolling arrays for 1D DP
- Consider if we can solve in-place

## 🔗 Related Resources

- [CSES Problem Set](https://cses.fi/problemset/)
- [CP Handbook - Dynamic Programming](https://cses.fi/book/book.pdf#page=49)
- [DP Tutorials](https://cp-algorithms.com/dynamic_programming/)
- [Knapsack Problems](https://en.wikipedia.org/wiki/Knapsack_problem)

## 📚 Problem Categories

### **Basic DP (★★☆☆☆)**
- **Dice Combinations**: Introduction to DP with simple recurrence
- **Minimizing Coins**: Classic coin change problem
- **Coin Combinations I**: Unbounded knapsack variant

### **Intermediate DP (★★★☆☆)**
- **Coin Combinations II**: Bounded knapsack with ordering
- **Removing Digits**: Digit DP introduction
- **Grid Paths**: 2D DP with constraints
- **Book Shop**: Standard knapsack problem
- **Money Sums**: Subset sum problem
- **Removal Game**: Game theory + DP
- **Two Sets II**: Subset sum with constraints

### **Advanced DP (★★★★☆)**
- **Beautiful Permutation**: Permutation counting with DP
- **Go Go Turtle**: Complex state transitions
- **Decreasing String**: String manipulation with DP
- **School Excursion**: Knapsack with group constraints
- **Counting Numbers**: Basic digit DP

### **Expert DP (★★★★★)**
- **Counting Numbers II-V**: Progressively harder digit DP problems
- **Advanced optimization techniques**
- **Complex state management**

## 💻 Implementation Tips

1. **Start Simple**: Begin with basic recurrence, optimize later
2. **Test Cases**: Always test with edge cases and small examples
3. **State Compression**: Use bit manipulation when possible
4. **Memory Management**: Be careful with large DP tables
5. **Modulo Operations**: Handle large numbers properly

## 🏆 Practice Strategy

1. **Solve in Order**: Start with basic problems, progress to advanced
2. **Understand Patterns**: Look for similarities between problems
3. **Implement Multiple Solutions**: Try both memoization and tabulation
4. **Optimize**: Practice space and time optimizations
5. **Review**: Revisit problems to reinforce concepts

---

*Master Dynamic Programming to become a competitive programming champion! 🚀*
