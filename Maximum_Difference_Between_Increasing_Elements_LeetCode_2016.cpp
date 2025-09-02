/*

2016. Maximum Difference Between Increasing Elements


Hint 1 : could keep a track of the minimum while traversing
Hint 2 : a potential answer arises when current minimum is 
greater than nums[i] i.e. the current element. 
*/



class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
                cout << premin << endl;
            }
        }
        return ans;
    }
};