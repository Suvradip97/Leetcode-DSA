#include<bits/stdc++.h>
using namespace std;

# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 
# define for(i, a, n) for(int i=a;i<n;i++)




signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n%2 == 1){
            n *= 3;
            n += 1;
        }
        else{
            n /= 2;
        }
    }
    cout << n << nl;
}