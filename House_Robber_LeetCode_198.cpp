
// Maximum sum of non adjacent elments DP 5

/*

198. House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/



// Memoization 

class Solution {
public:
    int func(int i, vector<int>& a, vector<int>& dp) {
        if (i == 0)
            return a[i];
        if (dp[i] != -1)
            return dp[i];
        int pick = a[i] + (i > 1 ? func(i - 2, a, dp) : 0);
        int nonpick = func(i - 1, a, dp);
        return dp[i] = max(pick, nonpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(n - 1, nums, dp);
    }
};


// Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + (i > 1 ? dp[i - 2] : 0);
            int nonpick = dp[i - 1];
            dp[i] = max(pick, nonpick);
        }
        return dp[n - 1];
    }
};


// Space Optimiziation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + (i > 1 ? prev2 : 0);
            int nonpick = prev1;
            int curr = max(pick, nonpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};