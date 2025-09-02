

/*

LeetCode Easy 

20 Valid Parenthesis


Logic :

1) If i see an opening then push it onto stack
2) If i see a closing then check the if the stack is empty if true
return false, as it means that the opening has not yet been encountered
else check if top of stack and current element are opposite or not.
if true then pop from stack else return false
3) Finally if stack is empty return true else return false as we have
only encountered opening only.

*/



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if (n % 2) {
            return false;
        }
        for (auto a : s) {
            if (a == '(' || a == '{' || a == '[') {
                st.push(a);
            } else {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                if (ch == '(' and a == ')' || ch == '{' and a == '}' ||
                    ch == '[' and a == ']') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.empty() == true) {
            return true;
        }
        return false;
    }
};