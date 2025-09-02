
/*

Count total set bits GFG

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int highestPower(int n){
        int b = 0;
        while(1 << b <= n){
            b++;
        }
        return --b;
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n <= 1) return n;
        
        int x = highestPower(n);
        int y = x * pow(2, (x - 1));
        int rem_bits = n - pow(2, x) + 1;
        int z = countSetBits(n - pow(2, x));
        return (( y + rem_bits + z)%(1000000007));
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends