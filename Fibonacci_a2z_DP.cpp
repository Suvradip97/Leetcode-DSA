#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


// Brute Force Recursion : exponential time complexity

int fib(int n){
	if(n <= 1) return n;
	return(fib(n - 1) + fib(n - 2));
}

// Memoization : TC : O(N)
vector<int> dp(n + 1, -1);

int fib(int n){
	if(n <= 1) return n;
	if(dp[n] != -1) return dp[n];
	return dp[n] = fib(n - 1) + fib(n - 2);
}


// Tabulation : Tc : O(N) SC : O(N)

int fib(int n){
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}


// Tabulation with Space Optimization

int fib(int n){
	int prev2 = 0, prev1 = 1, curr = 0;
	for(int i=2;i<=n;i++){
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1; 
}
signed main(){
	int n;
	cin >> n;

}