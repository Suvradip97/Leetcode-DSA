
/*

416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/



// Memoization


class Solution {
public:
    bool SubsetSum(int i, vector<int>& nums, int target,
                   vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (i == 0)
            return (nums[i] == target);
        if (dp[i][target] != -1)
            return dp[i][target];
        bool notpick = SubsetSum(i - 1, nums, target, dp);
        bool pick = (nums[i] <= target)
                        ? SubsetSum(i - 1, nums, target - nums[i], dp)
                        : false;
        return dp[i][target] = (pick | notpick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        else {
            int target = sum / 2;
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));
            return SubsetSum(n - 1, nums, target, dp);
        }
    }
};


// Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 or n == 1)
            return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= target; i++)
            dp[0][i] = false;
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notpick = dp[i - 1][j];
                bool pick = (nums[i] <= j) ? dp[i - 1][j - nums[i]] : false;
                dp[i][j] = (pick | notpick);
            }
        }
        return dp[n - 1][target];
    }
};




// Space Optimization


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 or n == 1)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, 0);
        dp[0] = true;
        if(nums[0] <= target) dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, 0);
            curr[0] = true;
            for (int j = 1; j <= target; j++) {
                bool notpick = dp[j];
                bool pick = (nums[i] <= j) ? dp[j - nums[i]] : false;
                curr[j] = (pick | notpick);
            }
            dp = curr;
        }
        return dp[target];
    }
};