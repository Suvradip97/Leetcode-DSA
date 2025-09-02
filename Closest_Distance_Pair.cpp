#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long>> vvl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long, long>> vpl;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef unordered_map<int, int> mii;
typedef unordered_map<long, long> mll;
#define f first;
#define s second;
#define pub(x) push_back(x);
#define pob() pop_back();
#define mp(i, j) make_pair(i, j);
#define binary_search bs;
#define lower_bound lb;
#define upper_bound ub;
 




signed main(){
	FIO
	int t;
	cin >> t;
	while(t--){
		int n;
		vector<pair<int, int>> dist(n, {0, 0});
		for(int i=0;i<n;i++){
			cin >> dist[i].f >> dist[i].s; 
		}
		cout << closestDistPair(dist, 0, n-1);
	}

}