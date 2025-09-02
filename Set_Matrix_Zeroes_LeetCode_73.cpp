


/* LeetCode Medium 73

73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

*/
// Set Matrix Zeroes

#include<bits/stdc++.h>
using namespace std;



//Brute Force Solution



class Solution{
public:

	void MarkRow(vector<vector<int>>& nums, int i){
		int m = nums[0].size();
		for(int j=0;j<m;j++){
			if(nums[i][j] == 1) nums[i][j] = -1;
		}
	}

	void MarkColumn(vector<vector<int>>& nums, int j){
		int n = nums.size();
		for(int i=0;i<n;i++){
			if(nums[i][j] == 1) nums[i][j] = -1;
		}
	}

	vector<vector<int>> setMatrixZeroes(vector<vector<int>>& nums, int n, int m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(nums[i][j] == 0){
					MarkRow(nums, i);
					MarkColumn(nums, j);
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << nums[i][j] << " ";
			}
			cout << endl;
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(nums[i][j] == -1){
					nums[i][j] = 0;
				}
			}
		}
		return nums;
	}
};


//Better Solution


class Solution{
public:
	vector<vector<int>> setMatrixZeroes(vector<vector<int>> nums, int n, int m){
		int row[n] = {0};
		int col[m] = {0};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(nums[i][j] == 0){
					row[i] = 1;
					col[j] = 1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(row[i] || col[j]){
					nums[i][j] = 0;
				}
			}
		}
		return nums;
	}
};


//Optimal Solution





signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//Input the testcases
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> nums(n, vector<int>(m, 0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int no;
				cin >> no;
				nums[i][j] = no;
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << nums[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		Solution s;
		vector<vector<int>> ans = s.setMatrixZeroes(nums, n, m);
		for(auto a : ans){
			for(auto x : a){
				cout << x << " ";
			}
			cout << endl;
		} 
	}
}



