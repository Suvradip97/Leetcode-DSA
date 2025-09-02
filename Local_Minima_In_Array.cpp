#include<bits/stdc++.h>
using namespace std;


signed main(){
	vector<int> nums = {10,9,8,7,6,5,8,9,10,11,12};
	int l = 0;
	int r = nums.size() - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(nums[mid] < nums[mid + 1]){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << nums[l] << endl;
}