
// 200. Number of Islands
// Leetcode medium



class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // Traverse all its neighbours
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    if(delrow == 0 or delcol == 0){
                        int nrow = row + delrow;
                        int ncol = col + delcol;
                        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                            grid[nrow][ncol] == '1' and !vis[nrow][ncol]) {
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] and grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return cnt;
    }
};