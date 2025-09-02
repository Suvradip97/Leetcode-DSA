


// Memoization


class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int func(int ind, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[0] <= w) return val[0];
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int nottake = func(ind - 1, w, wt, val, dp);
        int take = INT_MIN;
        if(wt[ind] <= w){
            take = val[ind] + func(ind - 1, w - wt[ind], wt, val , dp);
        }
        return dp[ind][w] = max(take, nottake);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return func(n-1, W, wt, val, dp);
    }
};



// Tabulation



class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for(int j=wt[0];j<=W;j++){
            dp[0][j] = val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int nottake = dp[i-1][j];
                int take = (wt[i] <= j) ? val[i] + dp[i - 1][j - wt[i]] : INT_MIN;
                dp[i][j] = max(take, nottake);
            }
        }
        return dp[n-1][W];
    }
};



// Space Optimization

// 2 Arrays


class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = val.size();
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        for(int j=wt[0];j<=W;j++){
            prev[j] = val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int nottake = prev[j];
                int take = (wt[i] <= j) ? val[i] + prev[j - wt[i]] : INT_MIN;
                curr[j] = max(take, nottake);
            }
            prev = curr;
        }
        return prev[W];
    }
};



// Space Optimization 2

// single Array : Overwriting Concept

lass Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = val.size();
        vector<int> prev(W + 1, 0);
        for(int j=wt[0];j<=W;j++){
            prev[j] = val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=W;j>=0;j--){
                int nottake = prev[j];
                int take = (wt[i] <= j) ? val[i] + prev[j - wt[i]] : INT_MIN;
                prev[j] = max(take, nottake);
            }
        }
        return prev[W];
    }
};