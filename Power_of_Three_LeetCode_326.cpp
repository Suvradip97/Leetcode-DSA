


/*

326. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 

Constraints:

-231 <= n <= 231 - 1

*/



// Brute Force : (logn base 3)


class Solution {
public:n
    bool isPowerOfThree(int n) {
        double x = (double)n;
        while(true){
            if(x == 1) return true;
            else if(x <= 0) return false;
            x /= 3;
        }
    }
};