//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int x =-2, y = n;
        while(n > 0){
            if(n&1 == 0){
                ++x;
                break;
            }
            x++;
            n >>= 1;
        }
        cout << x << endl;
        n = y | (1 << x);
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends