#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


void solve(){
	int n;
	cin >> n;
	vector<int> a(n, 0), b(32, 0);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int j = 0;j<32;j++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			cnt += (a[i] & (1 << j));
		}
		b[j] = cnt;
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<32;i++){
			if(!b[i] % k) cout << k << " ";
		}
	}
}



signed main(){
	FIO
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << nl;
	}
}