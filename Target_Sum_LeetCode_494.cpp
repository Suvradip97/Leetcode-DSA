/*

494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/



// Tabulation


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto a : nums) totalsum += a;
        if((totalsum - target) % 2 || (totalsum - target) < 0) return 0;
        int tar = (totalsum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0] <= tar and nums[0] != 0) dp[0][nums[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int non_pick = dp[i-1][j];
                int pick = (nums[i] <= j) ? dp[i-1][j-nums[i]] : 0;
                dp[i][j] = (non_pick + pick);
            }
        }
        return dp[n-1][tar];
    }
};



// Space Optimization



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto a : nums) totalsum += a;
        if((totalsum - target) % 2 || (totalsum - target) < 0) return 0;
        int tar = (totalsum - target) / 2;
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] <= tar and nums[0] != 0) prev[nums[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int non_pick = prev[j];
                int pick = (nums[i] <= j) ? prev[j-nums[i]] : 0;
                curr[j] = (non_pick + pick);
            }
            prev = curr;
        }
        return prev[tar];
    }
};