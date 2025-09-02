
/*
Fruits in Baskets GFG
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i = 0, j = 0, bucket_size = 0;
        int ans = INT_MIN, len = 0;
        map<int, int> freq;
        while(j < fruits.size()){
            //Pick the first fruit type
            freq[fruits[j]]++;
            while(i <= j and freq.size() > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0){
                    freq.erase(fruits[i]);
                }
                i++;
            }
            len = j - i + 1;
            ans = max(ans, len);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends