
// DP7 Ninja's Training 

// Vacation atcoder 


// Memoization

class Solution {
  public:
    int func(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i == 0){
            int maxi = 0;
            for(int task = 0; task <3 ; task++){
                if(task != j){
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != j){
                maxi = max(maxi, arr[i][task] + func(i - 1, task, arr, dp));
            }
        }
        return dp[i][j] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return func(n - 1, 3, arr, dp);
    }
};


// Tabulation


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        maxi = max(maxi, arr[day][task] + dp[day - 1][task]);
                    }
                }
                dp[day][last] = maxi;
            }
        }
        return dp[n-1][3];
    }
};



// Tabulation with Space Complexity


// Temp array is required for every computation fo ith day, so dont update it
// after every computation


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<int> dp(4, 0);
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day = 1; day < n; day++){
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        temp[last] = max(temp[last], arr[day][task] + dp[task]);
                    }
                }
            }
            dp = temp;
        }
        return dp[3];
    }
};