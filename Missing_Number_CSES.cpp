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
    ll sum1 = (n * (n + 1)) / 2;
    ll sum2 = 0;
    for(int i=0;i<n-1;i++){
        ll num;
        cin >> num;
        sum2 += num;
    }
    cout << sum1 - sum2 << nl;
} 