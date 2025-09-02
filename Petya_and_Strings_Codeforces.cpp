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
    cin >> a >> b;

    for(int i=0;i<a.size();i++) a[i] = tolower(a[i]);
    for(int i=0;i<b.size();i++) b[i] = tolower(b[i]);

    if(a < b) 
        cout << -1;
    else if(a == b)
        cout << 0;
    else
        cout << 1;  
}