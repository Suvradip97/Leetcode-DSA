/*

70. Climbing Stairs
Solved
Easy
Topics
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/


// Brute Force : Recursion Exponential Time Complexity

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        return(climbStairs(n -1) + climbStairs(n - 2));
    }
};

// Memoization : TC : O(n)

class Solution {
public:
    int func(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = func(n - 1, dp) + func(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};


// Tabulation : TC : O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Tabulation with Space optimization

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 1, curr = 0;
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;;
    }
};