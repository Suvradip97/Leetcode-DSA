
/*


78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.



*/




class Solution {
private :
    void func(vector<int>& nums, int i, int n){
        if(i == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        func(nums, i + 1, n);   // Pick the element
        v.pop_back();
        func(nums, i + 1, n);   // Non Pick the element
    }    
    
public:
    vector<int> v;
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        func(nums, 0, n);
        return ans;
    }
};