
 
// 4 5
// books : 3 1 2 1 (before sorting)
// books : 1 1 2 3 (after sorting)
// time :  T T T F
// max_time = 5-1 = 4-1 = 3-2 =1
// books read = 3
 
// 1 2 3 4 
/*
lo = 1, hi = 4, mid = 2 condition = T
lo = 3 hi = 4, mid = 3 condition = T
lo = 4, hi = 4, mid = 4, conditon = F
lo = 4, hi = 3, loop break
ans = 3
*/
 
/*
The problem can be written in the following way: for each index i
 denote ri
 as the largest index such that ai+…+ari⩽t
. The problem is to find max(ri−i+1)
.

One can see that ri
 are nondecreasing, so the problem can be solved with two pointers: iterate over i
 and keep a pointer to corresponding ri
.
*/
 
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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }   
    int ans = INT_MIN;
    int i = 0, j = 0, len = 0, sum = 0;
    while(j < n){
        sum += a[j];
        while(i <= j and sum > t){
            sum -= a[i];
            i++;
        }
        len = j - i + 1;
        ans = max(ans, len);
        j++;
    }
    cout << ans << nl;
}