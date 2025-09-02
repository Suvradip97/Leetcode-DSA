
/*

918. Maximum Sum Circular Subarray
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104


Approach 2: Calculate the "Minimum Subarray"
Intuition
As mentioned before, we know that the maximum "normal sum" is the Maximum Subarray problem which can be found with Kadane's. As such, we can focus on finding the "special sum".

Instead of thinking about the "special sum" as the sum of a prefix and a suffix, we can think about it as the sum of all elements, minus a subarray in the middle. In this case, we want to minimize this middle subarray's sum, which we can calculate using Kadane's algorithm as well.


If we use Kadane's algorithm but use min() instead of max() to update the current subarray sum, it will give us the minimum subarray. Then, we can just subtract the minimum subarray from the total sum to find the "special sum".

There is one case we need to consider however; what if the minimum subarray contains all elements, such as in the case where every element is negative? In that case, our "special sum" would represent an empty array, which is invalid because the problem explicitly states that we need a non-empty subarray.

If we find that the minimum subarray is equal to the total sum, then we need to ignore the "special sum" and just return the "normal sum".

Algorithm
Calculate the maximum subarray maxSum using Kadane's algorithm.
Calculate the minimum subarray minSum using Kadane's algorithm, by using min() instead of max().
Calculate the sum of all the elements in nums, totalSum
If minSum == totalSum return maxSum, otherwise return max(maxSum, totalSum - minSum).



*/



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = 0, maxi1 = INT_MIN, mini = INT_MAX, sum2 = 0, totalsum = 0;
        // Kadanes algo
        for (auto a : nums) {
            sum1 = max(sum1, 0) + a;
            sum2 = min(sum2, 0) + a;
            maxi1 = max(maxi1, sum1);
            mini = min(mini, sum2);
            totalsum += a;
        }
        if (totalsum == mini) {
            return maxi1;
        }
        return max(maxi1, totalsum - mini);
    }
};