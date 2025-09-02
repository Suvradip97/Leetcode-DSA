

/*

137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.


*/

// Best Approach : Concept of Buckets

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};

// Sorting approach

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1;i<nums.size();i+=3){
            if(nums[i] != nums[i-1]){
                ans = nums[i-1];
                break;
            }
        }
        return (ans == 0 ? nums[nums.size() - 1] : ans);
    }
};


// Bit Manipulation approach


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, cnt = 0;
        for (int bitindx = 0; bitindx < 32; bitindx++) {
            cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & (1 << bitindx)) != 0)
                    cnt++;
            }
            if (cnt % 3 == 1) {
                ans = ans | (1 << bitindx);
            }
        }
        return ans;
    }
};
