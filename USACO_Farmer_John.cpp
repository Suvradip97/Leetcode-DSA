#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


/*
Binary Search on Answer is applicable here as it is a monotonic function
*/



bool check(int mid, string s, int n){
	set<string> st;
	for(int i=0;i<(n - mid + 1);i++){
		string sub = s.substr(i, mid);
		if(st.find(sub) == st.end()){
			st.insert(sub);
		}else{
			return false;
		}
	}
	return true;
}


signed main(){
	FIO
	int n;
	string s;
	cin >> n >> s;
	int ans = 1, lo = 1, hi = n;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(check(mid, s, n)){
			ans = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	cout << ans;
}