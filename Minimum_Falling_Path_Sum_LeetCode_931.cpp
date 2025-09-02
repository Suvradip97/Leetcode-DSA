

/*
931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/


// Memoization

class Solution {
public:
    int func(int i, int j, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {
        if (j < 0 or j >= matrix[0].size()) {
            return 1e8;
        }
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        if (dp[i][j] != 1e9)
            return dp[i][j];
        int up = matrix[i][j] + func(i + 1, j, matrix, dp);
        int left = matrix[i][j] + func(i + 1, j - 1, matrix, dp);
        int right = matrix[i][j] + func(i + 1, j + 1, matrix, dp);
        return dp[i][j] = min(up, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            ans = min(ans, func(0, i, matrix, dp));
        }
        return ans;
    }
};


// Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int left = matrix[i][j] + (j > 0 ? dp[i + 1][j - 1] : 1e8);
                int right = matrix[i][j] + (j + 1 < n ? dp[i + 1][j + 1] : 1e8);
                int down = matrix[i][j] + dp[i + 1][j];
                dp[i][j] = min(left, min(down, right));
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};



// Space Optimization + Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 1e8);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<int> temp(n, 1e8);
            for (int j = 0; j < n; j++) {
                int left = matrix[i][j] + (j > 0 ? dp[j - 1] : 1e8);
                int right = matrix[i][j] + (j + 1 < n ? dp[j + 1] : 1e8);
                int down = matrix[i][j] + dp[j];
                temp[j] = min(left, min(down, right));
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};

