

// Unbounded Knapsack

/*

Knapsack with Duplicate Items
Given a set of N items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Examples:

Input: N = 2, W = 3, val = {1, 1}, wt = {2, 1}
Output: 3
Explanation: 1.Pick the 2nd element thrice. 2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
Input: N = 4, W = 8, val[] = {6, 1, 7, 7}, wt[] = {1, 3, 4, 5}
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.
Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val and wt as input parameters and returns the maximum possible value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

*/


// Memeoization


class Solution{
public:
    int func(int ind, int w, int val[], int wt[], vector<vector<int>>& dp){
        if(ind == 0){
            return (w / wt[0]) * val[0];
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int nottake = 0 + func(ind - 1, w, val, wt, dp);
        int take = INT_MIN;
        if(wt[ind] <= w){
            take = val[ind] + func(ind, w - wt[ind], val, wt, dp);
        }
        return dp[ind][w] = max(nottake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return func(N-1, W, val, wt, dp);
    }
};



// Tabulation




class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        for(int i = 0; i <= W; i++){
            dp[0][i] = (i/ wt[0]) * val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake = 0 + dp[i-1][j];
                int take = (wt[i] <= j) ? val[i] + dp[i][j - wt[i]] : INT_MIN;
                dp[i][j] = max(nottake, take);
            }
        }
        return dp[N-1][W];
    }
};




// Space Optimiztion 2 arrays



class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        for(int i = 0; i <= W; i++){
            prev[i] = (i/ wt[0]) * val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake = 0 + prev[j];
                int take = (wt[i] <= j) ? val[i] + curr[j - wt[i]] : INT_MIN;
                curr[j] = max(nottake, take);
            }
            prev = curr;
        }
        return prev[W];
    }
};




// Space Optimization Single array



class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W + 1, 0);
        for(int i = 0; i <= W; i++){
            prev[i] = (i/ wt[0]) * val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake = 0 + prev[j];
                int take = (wt[i] <= j) ? val[i] + prev[j - wt[i]] : INT_MIN;
                prev[j] = max(nottake, take);
            }
        }
        return prev[W];
    }
};