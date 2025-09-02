#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 



signed main(){
	FIO

	ll n;
	cin >> n;
	while(n--){
		ll x;
		cin >> x;
		ll ans = 0;
		for(ll i=1;i*i<=x;i++){
			if(x % i == 0){
				ans++;
				if(x/i != i){
					ans++;
				}
			}
		}
		cout << ans << nl;
	}	
}