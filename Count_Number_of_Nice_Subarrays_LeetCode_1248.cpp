


/*

LeetCode Medium

1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

*/

// With transforming the nums array

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
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> newarr;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2)
                newarr.push_back(1);
            else
                newarr.push_back(0);
        }
        int ans = func(newarr, k) - func(newarr, k - 1);
        return ans;
    }
};


// Without transforming the nums array


class Solution {
public:
    int func(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, good = 0;
        while (j < nums.size()) {
            if (nums[j] % 2)
                count++;
            while (i <= j and count > k) {
                if (nums[i] % 2) {
                    count--;
                }
                i++;
            }
            good += j - i + 1;
            j++;
        }
        return good;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x = func(nums, k);
        int y = func(nums, k - 1);
        int ans = func(nums, k) - func(nums, k - 1);
        return ans;
    }
};