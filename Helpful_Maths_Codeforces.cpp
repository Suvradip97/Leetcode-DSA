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
    string a, b;
    cin >> a;
    for(int i=0;i<a.size();i+=2){
        b += a[i];
    }
    sort(b.begin(), b.end());
    for(int i=0;i<b.size();i++){
        if(i != b.size()-1){
            cout << b[i] << "+";
        }else{
            cout << b[i];
        }
    }
}