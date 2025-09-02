

/*
Balanced Team Codeforces ICPC Assiut
*/



#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


// 10 12 14 20 21 22 23 24 24 24 24
// 1  2  3  1  2  3  4  5  6  7  8
// 10 10 10 20 20 20 20 20 20 20 200
// easy application of upper bound



signed main(){
    FIO;
    ll n;
    cin >> n;
    vector<ll> students(n, 0);
    for(ll i=0;i<n;i++){
        cin >> students[i];
    }
    sort(students.begin(), students.end());
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x = students[i] + 5;
        ll ind = upper_bound(students.begin(), students.end(), x) - students.begin();
        ans = max(ans, ind - i);
    }

    cout << ans << nl;
}