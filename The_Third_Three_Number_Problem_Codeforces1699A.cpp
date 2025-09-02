#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 





signed main(){
	FIO
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2){
			cout << -1;
		}else{
			cout << 0 << " " << 0 << " " << (n/2);
		}
		cout << nl;
	}
}