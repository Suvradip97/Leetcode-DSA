#include<bits/stdc++.h>
using namespace std;


void solve(int a, int b){
	if(a % b == 0 || b % a == 0){
		cout << "Multiples";
	}
	else{
		cout << "No Multiples";
	}
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	solve(a, b);
}