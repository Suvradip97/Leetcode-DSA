
/*

Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 18K+Points: 2
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

1<=l<=r<=109

*/



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int n){
        if(n % 4 == 0){
            return n;
        }else if(n % 4 == 1){
            return 1;
        }else if(n % 4 == 2){
            return (n + 1);
        }else{
            return 0;
        }
    }
    int findXOR(int l, int r) {
        // complete the function here
        return (f(l - 1) ^ f(r));
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends