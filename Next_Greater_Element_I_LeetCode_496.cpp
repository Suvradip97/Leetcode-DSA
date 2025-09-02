
// 496. Next Greater Element I
// LeetCode Easy



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty() == false) {
                mp[nums2[i]] = st.top();
            } else {
                mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};