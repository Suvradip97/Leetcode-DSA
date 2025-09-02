
/*

518. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

*/


// Memoization


class Solution {
public:
    int func(int ind, vector<int>& coins, int tar, vector<vector<int>>& dp) {
        if (ind == 0) {
            return ((tar % coins[0]) == 0);
        }
        if (dp[ind][tar] != -1)
            return dp[ind][tar];
        int nonpick = func(ind - 1, coins, tar, dp);
        int pick =
            (coins[ind] <= tar) ? func(ind, coins, tar - coins[ind], dp) : 0;
        return dp[ind][tar] = (pick + nonpick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, coins, amount, dp);
    }
};



// Tabulation


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int nonpick = dp[i - 1][j];
                int pick = (coins[i] <= j) ? dp[i][j - coins[i]] : 0;
                dp[i][j] = (pick + nonpick);
            }
        }
        return dp[n - 1][amount];
    }
};




// Space Optimization



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            prev[i] = (i % coins[0] == 0);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int nonpick = prev[j];
                int pick = (coins[i] <= j) ? curr[j - coins[i]] : 0;
                curr[j] = (pick + nonpick);
            }
            prev = curr;
        }
        return prev[amount];
    }
};