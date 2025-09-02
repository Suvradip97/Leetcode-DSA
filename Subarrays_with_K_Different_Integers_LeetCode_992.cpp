
/*

LeetCode Hard 

992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good 
subarrays of nums.

A good array is an array where the number of different integers in 
that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

*/






class Solution {
public:
    int func(vector<int>& nums, int k){
        int i =0, j= 0, count = 0, n = nums.size();
        map<int, int> freq;
        while(j < n){
            freq[nums[j]]++;
            while(i <= j and freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = func(nums, k);
        int y = func(nums, k - 1);
        return (x - y);
    }
};