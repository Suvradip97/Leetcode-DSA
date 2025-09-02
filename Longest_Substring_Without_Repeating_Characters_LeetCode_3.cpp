

/*

LeetCode Medium

3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest 
substring
without repeating characters.

 
*/




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0, j= 0;
        int ans = INT_MIN;
        int n = s.size();
        if(n <= 1) return n;
        map<char, int> mp;
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            ans = (max(ans, j - i + 1));
            j++;
        }
        return ans;
    }
};