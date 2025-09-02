
/*

62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right

*/


// Memoization 


class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 and j == 0)
            return 1;
        if (i < 0 or j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);
        return dp[i][j] = (left + up);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, dp);
    }
};



// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    continue;
                else {
                    int up = (i - 1) >= 0 ? dp[i - 1][j] : 0;
                    int left = (j - 1) >= 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = (up + left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};



// Tabulation with Space optimization
// Basically we need to store the previous row in each row computation and
// after current row is computed we make it the prev one and we keep
// on computing the current row

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    curr[j] = 1;
                else {
                    int up = dp[j];
                    int left = (j - 1) >= 0 ? curr[j - 1] : 0;
                    curr[j] = (up + left);
                }
            }
            dp = curr;
        }
        return dp[n - 1];
    }
};