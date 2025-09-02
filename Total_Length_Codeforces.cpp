#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


// 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) 
// + (1 + 2 + 3 + 4) + (1 + 2 + 3) + (1 + 2) = 1 + 3 + 6 + 20 + 9
// = 39
 

ll solve(vector<ll>& a, ll n, ll k){
    ll i = 0, j = 0, cnt = 0, sum = 0;
    while(j < n){
        //include the first character
        sum += a[j];
        while(i <= j and sum > k){
            sum -= a[i];
            i++;
        }
        ll len = j - i + 1;
        cnt += (len*(len + 1))/2;
        j++;
    }
    return cnt;
}


signed main(){
    FIO
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    } 
    cout << solve(a, n, k);
}