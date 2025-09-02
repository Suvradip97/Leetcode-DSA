

// Geek Jump GFG



// Memoization

//{ Driver Code Starts

class Solution {
  public:
    int func(int n, vector<int>& height, vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int left = func(n-1, height, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        if(n > 1)
            right = func(n-2, height, dp) + abs(height[n] - height[n-2]);
        return dp[n] = min(left, right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, -1);
        return func(n-1, height, dp);
    }
};



// Tabulation

class Solution {
  public:
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int left = dp[i-1] + abs(height[i] - height[i-1]);
            int right = INT_MAX;
            if(i > 1){
                right = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n -1];
    }
};


// Space Optimzation with Tabulation

class Solution {
  public:
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int left = dp[i-1] + abs(height[i] - height[i-1]);
            int right = INT_MAX;
            if(i > 1){
                right = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n -1];
    }
};