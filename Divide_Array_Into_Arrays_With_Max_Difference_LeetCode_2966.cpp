

/*

2966. Divide Array Into Arrays With Max Difference

Given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

 

Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2

Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:

The difference between any two elements in each array is less than or equal to 2.

Example 2:

Input: nums = [2,4,2,2,5,2], k = 2

Output: []

Explanation:

Different ways to divide nums into 2 arrays of size 3 are:

[[2,2,2],[2,4,5]] (and its permutations)
[[2,2,4],[2,2,5]] (and its permutations)
Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.

Example 3:

Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14

Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]

Explanation:

The difference between any two elements in each array is less than or equal to 14.

 

Constraints:

n == nums.length
1 <= n <= 105
n is a multiple of 3
1 <= nums[i] <= 105
1 <= k <= 105



Solution :

Approach: Sorting
Intuition
We need to partition an integer array into subarrays of size three, each adhering to specific conditions. These conditions stipulate that every array element must be allocated to exactly one subarray, and the difference between any two elements within a given subarray should not exceed a positive integer, denoted as k.

Elements closer in value to each other are more likely to meet the criteria that the difference between any two elements in one subarray is less than or equal to k. Given that the elements should be distributed among subarrays of size three, a logical approach involves ordering elements with similar values such that they are proximate. Sorting the array in ascending order emerges as a strategic move. Sorting not only facilitates a systematic exploration of the elements but also streamlines the identification of valid subarrays.

The essence of the solution lies in traversing the sorted array in increments of three because the subarrays are of size three. This traversal through the sorted nums array is instrumental in constructing subarrays that satisfy the conditions outlined in the problem statement. To satisfy the condition that the difference between any two elements in one subarray is less than or equal to k, the loop iterates through the sorted array, and at each step, it assesses the difference between the first and third elements within the current triplet.

The rationale behind this method is that the sorted nature of the array guarantees that the smallest and largest elements within each triplet are positioned at the extremes. By examining the difference between these elements, one can effectively determine whether the conditions of the problem are met. If the difference between the third and first elements exceeds the specified threshold k, it signifies an impossibility of forming valid subarrays, and an empty array is returned.

Take, for instance, the array [a, a+1, a+2, a+3, a+4, a+5] with k = 2 where a is any positive number. A valid partition is achieved by creating subarrays such as [[a, a+1, a+2], [a+3, a+4, a+5]], where the difference between any two elements within each subarray is less than or equal to k.

Partitioning the nums array differently, we can build the valid subarray [a+2, a+3, a+4], but this disrupts the possibility of creating a second valid subarray. After creating [a+2, a+3, a+4], the remaining numbers are [a, a+1, a+5], where the difference between the first and last element is 5, exceeding the threshold k = 2. This example illustrates that the most promising strategy involves keeping the elements with the closest values in sorted order within the same subarray. Placing the first, second, and third elements in sorted order together, followed by the fourth, fifth, and sixth elements in another triplet, adheres to the principle that elements with minimal differences are grouped. This approach offers a guaranteed solution if one exists, and aligns with the problem constraints.

Now, consider the scenario presented by the example [a, a+1, a+3, a+4, a+5, a+6] with a given threshold k = 2, where a represents any positive number. Notably, the initial triplet [a, a+1, a+3] does not constitute a valid subarray. In response, one explores the possibility of forming a valid subarray with a+3 and other numbers. Successfully, [a+3, a+4, a+5] emerges as a valid triplet.

Then, to complete the initial triplet [a, a+1, ?], the task is to find a suitable number from the remaining array. Importantly, due to the sorted order, the remaining numbers are greater than a+3. If the triplet [a, a+1, ?] could not form a valid subarray with a+3, it logically follows that it is impossible for these elements to form a valid subarray with any subsequent number in the array.

This observation underscores a critical aspect of the solution strategy. The impossibility in the previous example of forming a valid triplet with the initial elements and a+3 means that further attempts with subsequent numbers are invalid, ensuring the algorithm provides an optimal solution for various cases while meeting the specified constraints.



When the difference between the third and first elements of the triplet is within the specified threshold k, the triplet is appended to the result array, which eventually contains all valid subarrays. The loop continues this process until the entirety of the sorted array is traversed. Incrementing by 3's through the sorted array ensures that the constructed subarrays are inherently compliant with the defined conditions: each element of num is in exactly one subarray, the subarrays are of size 3, and the difference between any two elements in one subarray is less than or equal to k.



Algorithm:

1)Sort the given array nums in ascending order.
2)Initialize an empty array ans to store the result, which will be a 2D array containing arrays of size 3.
3)Use a for loop to iterate through the sorted array nums with a step size of 3. The loop variable i represents the starting index of each potential array of size 3.
4)For each potential array of size 3, check if the difference between the third element (nums[i + 2]) and the first element (nums[i]) is greater than k. 
If the difference exceeds k, the conditions are not satisfied and return an empty array.
5)If the difference condition is met for the current potential array, append a new array to the result (ans). 
The new array consists of the three elements at indices i, i + 1, and i + 2 in the sorted array.
6)After processing all potential arrays, return the final 2D array ans containing valid arrays of size 3.




*/



class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};
