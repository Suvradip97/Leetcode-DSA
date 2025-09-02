#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define ull unsigned long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 



signed main(){
    FIO;
    ll n;
    cin >> n;

    map<string, ll> mp;
    mp["Bessie"] = 0;
    mp["Elsie"] = 0;
    mp["Daisy"] = 0;
    mp["Gertie"] = 0;
    mp["Annabelle"] = 0;
    mp["Maggie"] = 0;
    mp["Henrietta"] = 0;

    for(ll i=0;i<n;i++){
        string s; cin >> s;
        ll k; cin >> k;
        mp[s] += k;
    }


    ll first_min = 1e9;
    ll second_min = 1e9;
    ll count = 0;
    for(auto a : mp){
        if(a.second < first_min){
            first_min = a.second;
        }
    }

    for(auto a : mp){
        if(a.second > first_min and a.second < second_min){
            second_min = a.second;
            count = 1;
        }
        else if(a.second == second_min){
            count++;
        }
    }
    
    if(count == 0 || count > 1){
        cout << "Tie" << nl;
    }else{
        string s;
        for(auto a : mp){
            if(a.second == second_min){
                s = a.first;
                break;
            } 
        }
        cout << s << nl;
    }
}


/*
10
Bessie 1
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Annabelle 10
Bessie 6
Henrietta 5
*/