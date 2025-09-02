#include<bits/stdc++.h>
using namespace std;


// Store a graph as adjacency matrix

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int adj[n + 1][n + 1];
	memset(adj, 0, sizeof(adj));
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	//Print the graph
	for(int i=0;i<n + 1;i++){
		for(int j=0;j<n + 1;j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}



/*
5 6
1 2
1 3
3 4
2 4
2 5
4 5
*/