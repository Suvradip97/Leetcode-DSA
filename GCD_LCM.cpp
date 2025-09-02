#include<bits/stdc++.h>
using namespace std;

/* Euclid's method to calculate the gcd is very easy only one line code
gcd(a,b) = gcd(b,a%b) -------------- Recursive Case
gcd(a,0) = a ------------------- Base case

product of two numbers = gcd*lcm
a * b  = gcd * lcm

*/

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){

	int x, y;
	cin >> x >> y;

	cout << "GCD is " << gcd(x,y) << endl;
	int lcm = (x*y) / gcd(x,y);
	cout << "LCM is " << lcm << endl;
	return(0);

}