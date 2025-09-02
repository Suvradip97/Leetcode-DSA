
#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


ll solve(vector<ll>& a, ll k){
	ll i = 0, j = 0, ans = 0, n = a.size();
	multiset<ll> mst;
	while(j < n){
		mst.insert(a[j]);
		while(*mst.rbegin() - *mst.begin() > k){
			mst.erase(mst.find(a[i]));
			i++;
		}
		ans += (j - i + 1);
		j++;
	}
	return ans;
}


signed main(){
	FIO
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto &i : a){
		cin >> i;
	}
	cout << solve(a, k) << nl;
}