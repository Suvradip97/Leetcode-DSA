#include<bits/stdc++.h>
using namespace std;


/* Given a string find all possible combinations of words that are possible

0 -> .j
1 -> abc
2 -> def
3 -> ghi
4 -> jkl
5 -> mno 
6 -> pqrs
7 -> tu
8 -> vwx
9 -> yz


e.g : 5   7   3
      m   t   g
      n   u   h
      o       i

      2 * 3 * 3 = 18 combinations = mtg, mth, mti, ntg, nth, nti, etc



*/


string arr[] = {".j", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getPaths(int n){
	//Base cases
	if(n == 0){
		vector<string> ans = {""};
		return ans;
	}else if(n < 0){
		vector<string> ans;
		return ans;
	}

	//Recursive Cases
	vector<string> ans1 = getPaths(n - 1);
	vector<string> ans2 = getPaths(n - 2);
	vector<string> ans3 = getPaths(n - 3);

	vector<string> ans;
	for(auto a : ans1){
		string snew = "1" + a;
		ans.push_back(snew);
	}
	for(auto a : ans2){
		string snew = "2" + a;
		ans.push_back(snew);
	}
	for(auto a: ans3){
		string snew = "3" + a;
		ans.push_back(snew);
	}
	return ans;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> ans = getPaths(n);
	for(auto a : ans){
		cout << a << endl;
	}
}

