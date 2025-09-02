
/*

LeetCode Medium

930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/




class Solution {
public:
    int func(vector<int>& nums, int goal) {
        int i = 0, j = 0, count = 0, sum = 0;
        int n = nums.size();
        while (j < n) {
            // include the first character
            sum += nums[j];
            while (i <= j and sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = func(nums, goal) - func(nums, goal - 1);
        return ans;
    }
};