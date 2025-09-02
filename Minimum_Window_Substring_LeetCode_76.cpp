
/*

LeetCode Hard

76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character 
in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


*/




class Solution {
public:
    string func(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0, startindx = -1, minlen = INT_MAX, cnt = 0;
        map<char, int> freq;
        for (auto a : t) {
            freq[a]++;
        }
        while (j < n) {
            if (freq[s[j]] > 0) {
                cnt++;
            }
            freq[s[j]]--;
            while (cnt == m) {
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    startindx = i;
                }
                freq[s[i]]++;
                if (freq[s[i]] > 0) {
                    cnt -= 1;
                }
                i++;
            }
            j++;
        }
        cout << startindx << " " << minlen << endl;
        return (startindx == -1 ? "" : s.substr(startindx, minlen));
    }
    string minWindow(string s, string t) { return func(s, t); }
};