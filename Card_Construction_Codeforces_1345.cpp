

/*

Codeforces Round 639 Div 2

*/



#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 




signed main(){
    FIO

    ull t;
    cin >> t;
    vector<ull> dp;
    dp.push_back(0);
    dp.push_back(2);
    
    while(t--){
        ull height = 2;
        while(true){
            ull req = dp.back() + (2 * height) + (height - 1);
            dp.push_back(req);
            height++;
            if(req > 1e9){
                break;
            }
        }
        ull n;
        cin >> n;
        ull ans = 0;
        while(n > 1){
            ull index = (upper_bound(dp.begin(), dp.end(), n) - dp.begin());
            index--;
            ans++;
            n -= dp[index];
        }
        cout << ans << nl;
    }
}