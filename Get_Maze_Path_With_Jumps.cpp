#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 



vector<string> solve(int sr, int sc, int dr, int dc){
    if(sr == dr and sc == dc){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    if(sr > dr){
        vector<string> ans;
        return ans;
    }
    if(sc > dc){
        vector<string> ans;
        return ans;
    }
    vector<string> myans;
    for(int i=1;i<=(dc-sc);i++){
        vector<string> horizontal = solve(sr, sc + i, dr, dc);
        for(auto a : horizontal){
            string s = 'h' + to_string(i) + a;
            myans.push_back(s);
        }
    }
    for(int i=1;i<=(dr-sr);i++){
        vector<string> vertical = solve(sr + i, sc, dr, dc);
        for(auto a : vertical){
            string s = "v" + to_string(i) + a; 
            myans.push_back(s);
        }
    }
    for(int i=1;i<=(dr-sr);i++){
        vector<string> diag = solve(sr + i, sc + i, dr, dc);
        for(auto a : diag){
            string s = "d" + to_string(i) + a; 
            myans.push_back(s);
        }
    }
    return myans;
} 

signed main(){
    FIO
    int n, m; cin >> n >> m;
    vector<string> ans = solve(1, 1, n, m);
    for(auto a : ans){
        cout << a;
        cout << nl;
    }
}