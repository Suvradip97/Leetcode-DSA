

/*

2486. Append Characters to String to Make Subsequence
LeetCode Medium

Idea is to take two pointers and traverse s till the end and at the end 
pointer of t points till the point the characters are found in s
so remaining ans = (t.size() - t_pointer) characters must be inserted at the 
end of s. so return the above result

*/



class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        while(l < n and r < m){
            if(s[l] == t[r]){
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return (m - r);
    }
};