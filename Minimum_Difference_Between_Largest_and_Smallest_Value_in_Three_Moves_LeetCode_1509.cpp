

/*

1509. Minimum Difference Between Largest and Smallest Value in Three Moves

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/



Solution :

Intuition
The goal is to minimize the difference between the maximum and minimum values in the array after making at most 3 moves. Since we can make up to 3 changes, effectively we can remove up to 3 elements from either end (start or end) of the sorted array to minimize the difference. The main insight is to try out the combinations of removing elements from both ends and find the minimum possible difference.

Approach
Sort the array nums.
If the size of the array n is less than or equal to 4, return 0 since we can remove all elements to get an empty array which results in a difference of 0.
Calculate the minimum difference by removing elements in these combinations:
Remove the last 3 elements.
Remove the first 3 elements.
Remove the first 1 and last 2 elements.
Remove the first 2 and last 1 elements.
The result will be the minimum of these differences.

Complexity
Time complexity:
𝑂(𝑛log𝑛)

Space complexity:

O(1)


*/





class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minVal = INT_MAX;
        int n = nums.size();
        if(n <= 4) return 0;

        minVal = min(minVal, nums[n-4] - nums[0]);
        minVal = min(minVal, nums[n-1] - nums[3]);
        minVal = min(minVal, nums[n-2] - nums[2]);
        minVal = min(minVal, nums[n-3] - nums[1]);
        return minVal;
        
    }
};