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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll ans = 0,  mincapacity = INT_MAX;
        for(ll i=0;i<n;i++){
            mincapacity = min(mincapacity, a[i]);
            ans += mincapacity;
        }
        cout << ans << nl;
    }
}