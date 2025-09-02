
/*

DP 18


Partitions with Given Difference
Difficulty: MediumAccuracy: 36.76%Submissions: 120K+Points: 4
Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.

Example 1:

Input:
n = 4
d = 3
arr[] =  { 5, 2, 6, 4}
Output: 1
Explanation:
There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Example 2:

Input:
n = 4
d = 0 
arr[] = {1, 1, 1, 1} 
Output: 6 
Explanation:
we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
Thus there are total 6 ways for partition the array arr. 
Your Task:
You don't have to read input or print anything. Your task is to complete the function countPartitions() which takes the integer n and d and array arr and returns the count of partitions.

Expected Time Complexity: O( n*sum(arr))
Expected Space Complexity: O( sum(arr))

Constraint:
1 <= n <= 500
0 <= d  <= 25000
0 <= arr[i] <= 50


*/


int MOD = (int)(1e9 + 7);
int func(int i, int s, vector<int>& arr, vector<vector<int>>& dp){
    if(i == 0){
        if(arr[0] == 0 and s == 0) return 2;
        if(s == 0 || arr[0] == s) return 1;
        return 0;
    }
    if(dp[i][s] != -1) return dp[i][s];
    int non_pick = func(i - 1, s, arr, dp) ;
    int pick = (arr[i] <= s) ? func(i-1, s - arr[i], arr, dp) : 0;
    return dp[i][s] = (pick + non_pick) % MOD;
}

int findWays(int tar, vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return func(n-1, tar, arr, dp);
}

int countPartitions(int n, int d, vector<int>& arr) {
    // Code here
    int totalsum = 0;
    for(auto a : arr) totalsum += a;
    int sum = totalsum - d;
    if(sum % 2 || sum < 0) return 0;
    else return findWays(sum / 2, arr);
}



// Tabulation


class Solution {
  public:
    int MOD = (int)(1e9 + 7);
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalsum = 0;
        for(auto a : arr) totalsum += a;
        if((totalsum - d) % 2 || (totalsum - d) < 0) return 0;
        int tar = (totalsum - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] <= tar and arr[0] != 0) dp[0][arr[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int non_pick = dp[i-1][j] % MOD;
                int pick = (arr[i] <= j) ? dp[i-1][j-arr[i]] % MOD : 0;
                dp[i][j] = (non_pick + pick) % MOD;
            }
        }
        return dp[n-1][tar];
    }
};


// Space optimization


class Solution {
  public:
    int MOD = (int)(1e9 + 7);
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalsum = 0;
        for(auto a : arr) totalsum += a;
        if((totalsum - d) % 2 || (totalsum - d) < 0) return 0;
        int tar = (totalsum - d) / 2;
        vector<int> dp(tar + 1, 0);
        if(arr[0] == 0) dp[0] = 2;
        else dp[0] = 1;
        if(arr[0] <= tar and arr[0] != 0) dp[arr[0]] = 1;
        for(int i=1;i<n;i++){
            vector<int> curr(tar + 1, 0);
            curr[0] = 1;
            for(int j=0;j<=tar;j++){
                int non_pick = dp[j] % MOD;
                int pick = (arr[i] <= j) ? dp[j-arr[i]] % MOD : 0;
                curr[j] = (non_pick + pick) % MOD;
            }
            dp = curr;
        }
        return dp[tar];
    }
};