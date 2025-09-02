

/*

Count triplets with sum smaller than X

Given an array arr[] of distinct integers of size n and a value sum, 
the task is to find the count of triplets (i, j, k), having (i<j<k) 
with the sum of (arr[i] + arr[j] + arr[k]) smaller than the 
given value sum.

TestCases

18 86
30 8 23 6 10 9 31 7 19 20 1 33 21 27 28 3 25 26

Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        int i = 0;
        int count = 0;
        sort(arr, arr + n);
        for(;i<n-2;i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                int s = arr[i] + arr[j] + arr[k];
                if(s < sum){
                    count += (k - j);
                    j++;
                }else{
                    k--;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends