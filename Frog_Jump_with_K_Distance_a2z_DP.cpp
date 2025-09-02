

// Minimal Cost GFG


// Memoization + DP

class Solution {
  public:
    int func(int i, int k, vector<int>& height, vector<int>& dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int minenergy = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j >= 0){
                int jump = func(i-j, k, height, dp) + abs(height[i] - height[i-j]);
                minenergy = min(minenergy, jump);
            }
        }
        return dp[i] = minenergy;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n, -1);
        return func(n-1, k, height, dp);
    }
};



// Tabulation : TC O(n*k) SC O(n)

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int minenergy = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j >= 0){
                    int jump = dp[i-j] + abs(height[i] - height[i-j]);
                    minenergy = min(minenergy, jump);
                }
            }
            dp[i] = minenergy;
        }
        return dp[n-1];
    }
};

