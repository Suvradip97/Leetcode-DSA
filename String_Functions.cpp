#include<bits/stdc++.h>
using namespace std;

// to tak einput of a string getline(cin, string)
// substr(i,j) prints the string from position i upto a length of j 
// substr(i) prints the string from i to the end;
// at(i) prints the character at ith index
// stoi(string) method converts a string to an integer value
// to_string(string) converts the different dastatype to string
// erase(idx) deletes all character from index idx
// erase(idx, len) deletes a total of len characters starting from idx
// erase(idx, 1) will delete only the idx th character of the string

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	string s;
	getline(cin, s);

	
	cout << s.size() << endl;
	cout << s << endl;
	cout << s.substr(1) << endl;
	cout << s.substr(1, 3) << endl;
	cout << s.at(0) << endl;
	cout << s.at(1) << endl;
	
	
	string s = "aabb";
	for(int i=1;i<=4;i++){
		cout << s.substr(0, i) << endl;
	}
	*/
	
	string s1 = "123";
	int x = stoi(s1) + 10;
	cout << x <<  endl;

	int a = 10;
	float b = 10.354;

	string s2 = to_string(a);
	string s3 = to_string(b);
	cout << s2 << endl;
	cout << s3 << endl;


	string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        cout << s[i] << " " << i << endl;
    }
    s.erase(2,1);
    cout << endl;
    for(int i=0;i<s.length();i++){
        cout << s[i] << " " << i << endl; 
    }
   
}