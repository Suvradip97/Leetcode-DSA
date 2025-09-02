
/*

Subset Sum Problem

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 104

*/



// Memoization

class Solution{   
public:
    bool func(int i, vector<int>& a, int j, vector<vector<int>>& dp){
        if(j == 0) return true;
        if(i == 0) return (a[i] == j);
        if(dp[i][j] != -1) return dp[i][j];
        bool notpick = func(i - 1, a, j, dp);
        bool pick = (a[i] <= j) ? func(i - 1, a, j - a[i], dp) : false;
        return dp[i][j] = (pick or notpick);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return func(n-1, arr, sum, dp);
    }
};


// Tabulation


TC : O(N * Sum)
SC : O(N * Sum)


class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i=0;i<n;i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notpick = dp[i - 1][j];
                bool pick = (arr[i] <= j) ? dp[i - 1][j - arr[i]] : false;
                dp[i][j] = (pick or notpick);
            }
        }
        return dp[n-1][sum];
    }
};


//Space optimition


class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<bool> dp(sum + 1, false), curr(sum + 1, false);
        dp[0] = curr[0] = true;
        dp[arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notpick = dp[j];
                bool pick = (arr[i] <= j) ? dp[j - arr[i]] : false;
                curr[j] = (pick or notpick);
            }
            dp = curr;
        }
        return dp[sum];
    }
};


class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        dp[arr[0]] = true;
        for(int i=1;i<n;i++){
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for(int j=1;j<=sum;j++){
                bool notpick = dp[j];
                bool pick = (arr[i] <= j) ? dp[j - arr[i]] : false;
                curr[j] = (pick or notpick);
            }
            dp = curr;
        }
        return dp[sum];
    }
};