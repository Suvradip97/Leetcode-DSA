
/*

*/



// Memoization


class Solution{
public:
	int MOD = (int)(1e9 + 7);
	int func(int ind, int sum, int arr[], vector<vector<int>>& dp){
	    if(ind == 0){
	        if(arr[0] == 0 and sum == 0) return 2;
	        if(sum == 0 || sum == arr[0]) return 1;
	        return 0;
	    }
	    if(dp[ind][sum] != -1) return dp[ind][sum];
	    int non_pick = func(ind - 1, sum, arr, dp) % MOD;
	    int pick = (arr[ind] <= sum) ? func(ind - 1, sum - arr[ind], arr, dp) % MOD : 0;
	    return dp[ind][sum] = (pick + non_pick) % MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return func(n-1, sum, arr, dp);
	}
};



// Tabulation


class Solution{
public:
	int MOD = (int)(1e9 + 7);
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        if(arr[0] == 0){
            dp[0][0] = 2;
        }else{
            dp[0][0] = 1;
        }
        if(arr[0] <= sum and arr[0] != 0) dp[0][arr[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int non_pick = dp[i-1][j] % MOD;
                int pick = (arr[i] <= j) ? dp[i-1][j-arr[i]] % MOD : 0;
                dp[i][j] = (non_pick + pick) % MOD;
            }
        }
        return dp[n-1][sum];
        
	}
};



// Space Optimization


class Solution{
public:
	int MOD = (int)(1e9 + 7);
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int> dp(sum + 1, 0);
        if(arr[0] == 0){
            dp[0] = 2;
        }else{
            dp[0] = 1;
        }
        if(arr[0] <= sum and arr[0] != 0) dp[arr[0]] = 1;
        for(int i=1;i<n;i++){
            vector<int> curr(sum + 1, 0);
            for(int j=0;j<=sum;j++){
                int non_pick = dp[j] % MOD;
                int pick = (arr[i] <= j) ? dp[j-arr[i]] % MOD : 0;
                curr[j] = (non_pick + pick) % MOD;
            }
            dp = curr;
        }
        return dp[sum];
	}
};