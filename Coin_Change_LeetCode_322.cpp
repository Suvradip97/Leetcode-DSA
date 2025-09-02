
/*

322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/


// Memoization

class Solution {
public:
    int func(int ind, vector<int>& coins, int target, vector<vector<int>>& dp){
        if(ind == 0){
            if(target % coins[0] == 0){
                return target / coins[0];
            }else{
                return 1e9;
            }
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int non_pick = func(ind - 1, coins, target, dp);
        int pick = (coins[ind] <= target) ? (1 + func(ind, coins, target - coins[ind], dp)) : 1e9;
        return dp[ind][target] = min(pick, non_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int x = func(n-1, coins, amount, dp);
        if (x >= 1e9) { 
            return -1; 
        } else { 
            return x;
        }
    }
};


// Tabulation


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int non_pick = dp[i-1][j];
                int pick = (coins[i] <= j) ? 1 + dp[i][j- coins[i]] : 1e9;
                dp[i][j] = min(pick, non_pick);
            }
        }
        if(dp[n-1][amount] >= 1e9){
            return -1;
        }else{
            return dp[n-1][amount];
        }
    }
};



// Space Optimization

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }else{
                prev[i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int non_pick = prev[j];
                int pick = (coins[i] <= j) ? 1 + curr[j- coins[i]] : 1e9;
                curr[j] = min(pick, non_pick);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9){
            return -1;
        }else{
            return prev[amount];
        }
    }
};