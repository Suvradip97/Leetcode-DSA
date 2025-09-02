/*
You are given a playlist of a radio station since its establishment. 
The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
Output
Print the length of the longest sequence of unique songs.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k_i \le 10^9

Example
Input:
8
1 2 1 3 2 7 4 2

Output:
5
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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	int j = 0, i = 0, ans = INT_MIN;
	map<int, int> mp;
	while(j < n){
		if(mp.find(a[j]) == mp.end()){
			mp.insert({a[j], j});
		}else{
			if(mp[a[j]] > i){
				i++;
				mp[a[j]] = j;
			}
			i = j;
		}
		ans = max(ans, j-i+1);
		j++;
	}
	cout << ans << nl;
}