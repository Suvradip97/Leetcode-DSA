#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 

/*
 
dont ignore skipping all the same elements in the case a[i] == b[j]

*/

ll solve(vector<ll>& a, vector<ll>& b){
    ll ans = 0, i = 0, j = 0;
    ll n = a.size(), m = b.size();
    while(i < n and j < m){
        if(a[i] < b[j]){
            i++;
            while(i < n and a[i] == a[i-1]) {
                i++;
            }
        }else if(a[i] > b[j]){
            j++;
            while(j < n and b[j] == b[j-1]) {
                j++;
            }
        }else{
            ll t = a[i];
            ll cnt1 = 0;
            ll cnt2 = 0;
            while(i < n and a[i] == t){
                cnt1++;
                i++;
            }
            while(j < m and b[j] == t){
                cnt2++;
                j++;
            }
            ans += (cnt1*cnt2);
        }
    }
    return ans;
}


signed main(){
    FIO
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i=0;i<n;i++) cin >> a[i];
    for(ll i=0;i<m;i++) cin >> b[i];

    cout << solve(a, b);
}