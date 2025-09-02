#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long, long>> vpl;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef unordered_map<int, int> mii;
typedef unordered_map<long, long> mll;
#define ll long long
#define f first;
#define s second;
#define nl '\n';
#define pub(x) push_back(x);
#define pob() pop_back();
#define mp(i, j) make_pair(i, j);
#define binary_search bs;
#define lower_bound lb;
#define upper_bound ub;



bool isPossible(ll d, ll n, ll k, vector<ll>& cows){
	ll cow_cnt = 1, pos = cows[0];
	for(int i=1;i<n;i++){
		if(cows[i] - pos >= d){
			pos = cows[i];
			cow_cnt++;
			if(cow_cnt >= k) return true;
		}
	}
	return false;
}

void solve(ll n, ll k, vector<ll>& cows){
	ll lo = 0;
	ll hi = *max_element(cows.begin(), cows.end()) - *min_element(cows.begin(), cows.end());
	ll ans = 0;
	while(lo <= hi){
		ll mid = lo + (hi - lo)/2;
		if(isPossible(mid, n, k, cows)){
			ans = mid;
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	cout << ans << nl;
}


signed main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> cows(n, 0);
	for(ll i=0;i<n;i++) cin >> cows[i];
	solve(n, k, cows);
}