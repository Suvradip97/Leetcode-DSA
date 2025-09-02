
/*

912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4

*/


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> counting(2 * 50000 + 1, 0);
        for (int num : nums) {
            // we add 5 * 10^4 because for smallest possible element -5 * 10^4 index must be 0
            counting[num + 50000]++;
        }
        int write_ind = 0;
        for (int number_ind = 0; number_ind < counting.size(); ++number_ind) {
            int freq = counting[number_ind];
            while (freq != 0) {
                nums[write_ind] = number_ind - 50000;
                write_ind++;
                freq--;
            }
        }
        return nums;
    }
};