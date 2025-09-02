
/*

1823. Find the Winner of the Circular Game


Approach
This problem is a variation of the classic Josephus problem, which involves determining the position of the last remaining person after a series of eliminations in a circle. The solution can be approached using a mathematical method, iterating to find the final position. Here's the step-by-step approach:

Initialization: Start by considering the position of the winner as 0 in a 0-indexed system. This simplifies the calculation because the Josephus problem is traditionally solved using 0-based indexing.

Iterative Calculation: Iterate from 1 to n, updating the position of the winner at each step using the formula:
winner=(winner+k)% i

This formula calculates the new position of the winner after each friend is eliminated. The modulo operation ensures the position wraps around the circle.
Convert to 1-indexed: After completing the loop, convert the 0-indexed position to a 1-indexed position by adding 1. This final step aligns the result with the problem's requirement, where friends are numbered from 1 to n.

How it work

Initial Setup: Assume we have n friends sitting in a circle and they are eliminated every k steps.

0-Indexed Calculation: Start with winner = 0. This represents the position of the winner in a 0-based index system.

Iterate Through Friends: For each friend count from 1 to n:

Calculate the new position of the winner after one friend is eliminated using the formula: winner=(winner+k)%i
This ensures that the position wraps around correctly in the circle.
1-Indexed Result: Convert the final result from 0-based index to 1-based index by adding 1. This is because the problem specifies that friends are numbered from 1 to n.


class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner=0;
        for (int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};