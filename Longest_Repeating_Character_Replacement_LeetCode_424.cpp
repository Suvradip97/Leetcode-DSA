

/*

424. Longest Repeating Character Replacement

LeetCode Medium

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

*/



class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, len = 0, ans = INT_MIN, maxf = INT_MIN, changes = 0;
        map<char, int> freq;
        while (j < s.size()) {
            // include the first character
            freq[s[j]]++;
            maxf = max(maxf, freq[s[j]]);
            len = j - i + 1;
            changes = len - maxf;
            if(changes <= k){
                ans = max(ans, len);
            }else{
                while(i <= j and changes > k){
                    freq[s[i]]--;
                    changes--;
                    i++;
                    if(freq[s[i]] == 0){
                        freq.erase(s[i]);
                    }
                }
            }
            j++;
        }
        return ans;
    }
};