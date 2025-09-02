#include<bits/stdc++.h>
using namespace std;


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adj[n + 1];
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Print the graph
	for(int i=0;i<n + 1;i++){
		for(auto a:adj[i]){
			cout << a << " ";
		}
		cout << endl;
	}
}