#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 




ll solve(vector<ll>& a, ll n, ll s){
    ll i = 0, j = 0, sum = 0, cnt = 0;
    while(j < n){
        //include the first character
        sum += a[j];
        while(i <= j and sum > s){
            sum -= a[i];
            i++;
        }
        cnt += (j - i + 1);
        j++;
    }

    return cnt;
}


signed main(){
    FIO
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    } 
    cout << solve(a, n, s);
}