

/*
1508. Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
*/



// Brute Force

Gives Memory Limit Error

// Heap solution to avoid Memory Limit error

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1000000007;
        vector<int> prefix(n, 0);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                long long val = prefix[j] - (i-1>=0 ? prefix[i-1] : 0);
                minHeap.push(val);
            }
        }
        
        long long result = 0;
        for (int i = 1; i <= right; ++i) {
            int sum_value = minHeap.top();
            minHeap.pop();
            if (i >= left) {
                result = (result + sum_value) % MOD;
            }
        }
        return result;
    }
};

// Binary Search Concept


First Solution (Naive Approach)
Generate All Subarray Sums:
Iterate over all possible subarrays and calculate their sums. Store these sums in a list.
Sort the Sums:
Sort the list of subarray sums.
Sum the Desired Range:
Sum the values in the sorted list from the left index to the right index.
Complexity
Time Complexity: O(n*n * logn)
Space Complexity: O(n*n);

Optimized Solution
Binary Search and Window Sum Calculation:

Use binary search to find the sum of the first k smallest subarray sums.
Maintain a sliding window to efficiently calculate sums of subarrays up to a target value.
Count and Sum Calculation:

For each midpoint in the binary search, count how many subarray sums are less than or equal to the midpoint and calculate their total sum.
Adjust the Sum for Modulo Operation:

Ensure the final sum respects the modulo constraint by adjusting for the exact count of subarray sums.
Complexity
Time Complexity: O(nlogn)
Space Complexity: O(1)

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total
    // sum.
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};