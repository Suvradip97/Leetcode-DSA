

/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

*/


// Memoization

class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 and j == 0)
            return grid[i][j];
        if (i < 0 or j < 0)
            return 1e6;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, grid, dp);
        int left = func(i, j - 1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, grid, dp);
    }
};


// Tabulation


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    continue;
                else {
                    int up = (i - 1 >= 0 ? dp[i - 1][j] : 1e6);
                    int left = (j - 1 >= 0 ? dp[i][j - 1] : 1e6);
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


// Space Optimization + Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 1e6);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    temp[j] = grid[i][j];
                else {
                    int up = (i - 1 >= 0 ? dp[j] : 1e6);
                    int left = (j - 1 >= 0 ? temp[j - 1] : 1e6);
                    temp[j] = grid[i][j] + min(up, left);
                    cout << temp[j] << " ";
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};