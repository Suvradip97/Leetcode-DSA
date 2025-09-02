#include<bits/stdc++.h>
using namespace std;

#define const MOD 1e9 + 7 
#define ll long long 

bool primes[100000001];

void sieve(){
	fill(primes, primes + 100000001, true);
	primes[0] = primes[1] = false;
	for(int i=2;i*i<=100000001;i++){
		if(primes[i]){
			for(int j=i*i;j<=100000001;j+=i){
				primes[j] = false;
			}
		}
	}
}


int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b % a, a);
}

long long power(int x, int n){
	if(n == 0) return 1;

	int half_power = power(x, n/2);
	if(n%2){
		return(half_power * half_power * x);
	}else{
		return(half_power * half_power);
	}
}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cout << power(5, 2) << '\n';

	sieve();

	for(int i=1;i<=1000;i++){
		if(primes[i]){
			cout << i << '\n';
		}
	}

	cout << gcd(25, 10);
}