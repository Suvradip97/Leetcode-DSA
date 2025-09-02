#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


// 7th
// 1 2 2 1 1 1 2 2

int gcd(int a, int b){
	if(a == 0) return b;
	else return gcd(b%a, a);
}

signed main(){
	FIO
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		vector<int> gcd_arr(n-1);
		for(int i=1;i<n;i++){
			int x = gcd(a[i], a[i-1]);
			gcd_arr[i-1] = x;
		}
		for(auto a : gcd_arr) cout << a << " ";
		cout << nl;
		int cnt = 0;
		int start = 0;
		int end = 0;
		for(int i=1;i<n-1;i++){
			if(gcd_arr[i] < gcd_arr[i-1]){
				start = i;
			}else{
				end = i;
			}
			cnt += (end - start);
		}
		if(cnt > 1) cout << "NO" << nl;
		else cout << "YES" << nl;  
	}
}