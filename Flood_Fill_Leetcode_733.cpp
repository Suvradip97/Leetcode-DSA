

// 733. Flood Fill


class Solution {
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

private:
    void dfs(int row, int col, int ini_color, int color,
             vector<vector<int>>& image, vector<vector<int>>& ans) {
        ans[row][col] = color;
        int n = image.size(), m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                image[nrow][ncol] == ini_color and ans[nrow][ncol] != color) {
                dfs(nrow, ncol, ini_color, color, image, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int ini_color = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ini_color, color, image, ans);
        return ans;
    }
};