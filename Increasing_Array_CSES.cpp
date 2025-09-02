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
    ll ans = 0;
    vector<ll> nums;
    for(int i=0;i<n;i++){
        ll no;
        cin >> no;
        nums.push_back(no);
    }
    for(int i=1;i<n;i++){
        if(nums[i] <nums[i-1]){
            ll diff = nums[i] - nums[i-1];
            ans += abs(nums[i] - nums[i-1]);
            nums[i] += abs(diff);
        }
    }
    cout << ans << nl;
}   