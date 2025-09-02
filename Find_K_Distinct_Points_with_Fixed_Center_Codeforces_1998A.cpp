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
	int t;	
	cin >> t;
	while(t--){
		int xc, yc, k;
		cin >> xc >> yc >> k;
		if(k % 2){
			for(int i=1;i<=k/2;i++){
				cout << xc - i << " " << yc << nl;
				cout << xc + i << " " << yc << nl;
			}
			cout << xc << " " << yc << nl;
		}else{
			for(int i=1;i<=k/2;i++){
				cout << xc - i << " " << yc << nl;
				cout << xc + i << " " << yc << nl;
			}

		}
	}

}