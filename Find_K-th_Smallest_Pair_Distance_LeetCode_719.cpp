

/*


719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2


*/



class Solution {
public:
    int cnt_pairs(int x, vector<int>& nums) {
        int pairs = 0;
        int n = nums.size();
        for (int l = 0, r = 1; r < n; r++) {
            while (r > l and nums[r] - nums[l] > x) {
                l++;
            }
            pairs += (r - l);
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back();
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (cnt_pairs(mid, nums) < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};


// Another version of f(x) function


class Solution {
public:
    int cnt_pairs(int x, vector<int>& nums) {
        int pairs = 0;
        int n = nums.size();
        for (int l = 0, r = 1; r < n; r++) {
            while (r > l and nums[r] - nums[l] > x) {
                l++;
            }
            pairs += (r - l);
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back();
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (cnt_pairs(mid, nums) >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};