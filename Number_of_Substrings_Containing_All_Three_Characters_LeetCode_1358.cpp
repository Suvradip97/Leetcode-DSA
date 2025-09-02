
/*

LeetCode Medium

1358. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all
 these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the 
characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", 
"bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the 
characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1


*/





class Solution {
public:
    int func(string s, int k) {
        int i = 0, j = 0, ans = 0, len = 0;
        int n = s.size();
        map<char, int> freq;
        while (j < n) {
            freq[s[j]]++;
            while (i <= j and freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }
                i++;
            }
            len = j - i + 1;
            ans += len;
            j++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        int x = func(s, 3);
        int y = func(s, 2);
        return (x - y);
    }
};