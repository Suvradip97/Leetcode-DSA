

// 503. Next Greater Element II
// LeetCode Medium 503



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        stack<int> st;
        for (int i = 2 * nums.size() - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    ans[i % n] = st.top();
                }
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};