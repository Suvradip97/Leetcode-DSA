

/*

1901. Find a Peak Element II

Leetcode Medium

*/



class Solution {
public:
    int maxVal(vector<vector<int>>& mat, int n, int m, int col) {
        int idx = -1;
        int maxval = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxval) {
                maxval = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int lo = 0;
        int hi = m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int maxRowidx = maxVal(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxRowidx][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxRowidx][mid + 1] : -1;
            if (mat[maxRowidx][mid] > left and mat[maxRowidx][mid] > right) {
                return {maxRowidx, mid};
            } else if (mat[maxRowidx][mid] < left) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return {-1, -1};
    }
};