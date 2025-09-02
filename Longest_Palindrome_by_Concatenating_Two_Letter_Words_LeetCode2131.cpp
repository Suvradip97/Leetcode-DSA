
/*
2131. Longest Palindrome by Concatenating Two Letter Words

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/




class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26] = {{0}};
        for (auto& w : words) {
            const int i = w[0] - 'a', j = w[1] - 'a';
            freq[i][j]++;
        }
        int pal = 0;
        bool hasDouble = 0;
        for (int i = 0; i < 26; i++) {
            const int fi = freq[i][i];
            pal += fi / 2 * 4;
            if (hasDouble == 0 && (fi & 1) == 1)
                hasDouble = 1;
        }
        pal += hasDouble * 2;
        for (int i = 0; i < 26; i++)
            for (int j = i + 1; j < 26; j++)
                pal += min(freq[i][j], freq[j][i]) * 4;
        return pal;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();