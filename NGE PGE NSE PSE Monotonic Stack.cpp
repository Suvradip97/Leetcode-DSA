#include<bits/stdc++.h>
using namespace std;



signed main(){
	
    // take inputs
    int n;
	cin >> n;
    vector<int> arr(n ,0);
	stack <int> st1, st2, st3, st4;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
    
    // Initialise output data structures
 	vector<int> pge(n, -1);
    vector<int> nge(n, -1);
    vector<int> nse(n, -1);
    vector<int> pse(n, -1);
    
    // Run the Monotonic stack algorithm for pge and nge
    
    // PGE
 	for(int i=0;i<n;i++){
        while(!st1.empty() && st1.top() <= arr[i]){
            st1.pop();
        }
        pge[i] = (st1.empty() ? -1 : st1.top());
        st1.push(arr[i]);
    }

    // NGE

    for(int i=n-1;i>=0;i--){
        while(!st2.empty() && st2.top() <= arr[i]){
            st2.pop();
        }
        nge[i] = (st2.empty() ? -1 : st2.top());
        st2.push(arr[i]);
    }

    // PSE

    for(int i=0;i<n;i++){
        while(!st3.empty() && st3.top() >= arr[i]){
            st3.pop();
        }
        pse[i] = (st3.empty() ? -1 : st3.top());
        st3.push(arr[i]);
    }

    // NSE

    for(int i=n-1;i>=0;i--){
        while(!st4.empty() && st4.top() >= arr[i]){
            st4.pop();
        }
        nse[i] = (st4.empty() ? -1 : st4.top());
        st4.push(arr[i]);
    }

    // Output the answer
    cout << "Arr : ";
    for(auto a : arr){
        cout << a << " ";
    }
    // PGE
    cout << endl << "PGE : ";
    for(auto x : pge){
        cout << x << " " ;
    }
    // NGE
    cout << endl << "NGE : ";
    for(auto x : nge){
        cout << x << " " ;
    }
    // PSE
    cout << endl << "PSE : ";
    for(auto x : pse){
        cout << x << " " ;
    }
    // NSE
    cout << endl << "NSE : ";
    for(auto x : nse){
        cout << x << " " ;
    }
}