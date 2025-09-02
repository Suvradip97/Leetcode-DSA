



#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 

void solve(vector<ll>& a,ll n, ll p){
	ll total = 0;
	for(auto i : a) total += i;
	ll ans = (p / total) * n;
	ll rem_p = p % total;

	// Circular array copy it twice
	for(auto x : a){
		a.push_back(x);
	}

	ll sum = 0, len = INT_MAX, start = 0;
	ll i = 0, j = 0;
	while(j < 2 *n){
		sum += a[j];
		while(i <= j and sum >= rem_p){
			if(len > j - i + 1){
				start = i;
				len = j - i + 1;
			}
			sum -= a[i++];
		}
		j++;
	}
	cout << start + 1 << " " << ans + len << nl;
}


signed main(){
	FIO
	ll n, p;
	cin >> n >> p;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	solve(a, n , p);
}