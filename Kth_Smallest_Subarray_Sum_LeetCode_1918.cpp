#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	int f(int mid, vector<int>& nums){
		int i = 0, j = 0, sum = 0, cnt = 0, n = nums.size();
		while(j < n){
			sum += nums[j];
			while(sum > mid){
				sum -= nums[i];
				i++;
			}
			cnt += (j - i + 1);
			j++;
		}
		return cnt;
	}
	int KthSmallestSubArraySum(vector<int>& nums, int k){
		sort(nums.begin(), nums.end());
		int lo = nums[0];
		int hi = accumulate(nums.begin(), nums.end(), 0);
		int ans = 0;
		while(lo <= hi){
			int mid = lo + (hi - lo) / 2;
			if(f(mid, nums) >= k){
				ans = mid;
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}
		return ans;
	}
};


signed main(){
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for(int i=0;i<n;i++) cin >> nums[i];
	Solution s;
	cout << s.KthSmallestSubArraySum(nums, k);
}