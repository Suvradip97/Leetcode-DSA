
/*

LeetCode Medium

1004. Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, zeroes = 0;
        int ans = INT_MIN, len = 0;
        int n = nums.size();
        deque<int> q;
        while(j < n){
            if(nums[j] == 0){
                zeroes++;
                q.push_back(j);
            }
            if(zeroes > k){
                zeroes--;
                int x = q.front();
                i = ++x;
                q.pop_front();
            }
            len = j - i + 1;
            ans = max(ans, len);
            j++;
            
        }
        return ans;
    }
};