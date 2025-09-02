

/*
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases
*/


// Memoization

class Solution {
public:
    int func(int i, int j, vector<vector<int>>& obstacleGrid,
             vector<vector<int>>& dp) {
        if (i == 0 and j == 0)
            return 1;
        if (i < 0 or j < 0 or (obstacleGrid[i][j] == 1))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, obstacleGrid, dp);
        int left = func(i, j - 1, obstacleGrid, dp);
        return dp[i][j] = (up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (obstacleGrid[m - 1][n - 1] == 1 or obstacleGrid[0][0] == 1)
            return 0;
        return func(m - 1, n - 1, obstacleGrid, dp);
    }
};


// Tabulation


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 or obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    continue;
                else if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};



// Space Optimization with Tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 or obstacleGrid[0][0] == 1)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    temp[j] = 1;
                else if (obstacleGrid[i][j] == 1)
                    temp[j] = 0;
                else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[j];
                    if (j > 0)
                        left = temp[j - 1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};