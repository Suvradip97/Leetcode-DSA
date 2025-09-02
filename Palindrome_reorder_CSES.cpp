#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 



signed main(){
    FIO
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto a : s){
        mp[a]++;
    }
    int cnt = 0;
    char c;
    for(auto a : mp){
        if(a.s % 2 == 1) {
            cnt++;
            c = a.f;
        }
    }

    if(cnt > 1){
        cout << "NO SOLUTION";
    }
    else{
        string ans;
        for(auto a : mp){
            for(int i=0;i<a.s/2;i++){
                ans.push_back(a.f);
            }
        }
        if(cnt == 1){
            cout << ans << c;
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }else{
            cout << ans;
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
    }
}