/*
You are given an array of n integers, and your task is to find three 
values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the 
target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print three integers: the positions of the values. 
If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 5000
1 \le x,a_i \le 10^9

1 2 5 7

Example
Input:
4 8
2 7 5 1

Output:
1 3 4
*/


#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 



signed main(){
	FIO
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<int> ans;
	bool flag = false;
	sort(a.begin(), a.end());
	for(int i=0;i<n-2;i++){
		int rem = x - a[i];
		int l = i + 1;
		int r = n - 1;
		while(l < r){
			int sum = a[l] + a[r];
			if(sum == rem){
				ans.push_back(i);
				ans.push_back(l);
				ans.push_back(r);
				flag = true;
				break;
			}else if(sum > rem){
				r--;
			}else{
				l++;
			}
		}
		if(flag == true)
			break;
	}
	if(ans.size() == 0) cout << "IMPOSSIBLE";
	else{
		for(auto a:ans){
			cout << a << " ";
		}
	}
}