//Leetcode 11 Medium

/*
Container With Most Water
Medium

13903

847

Add to List

Share
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int lo = 0;
    	int hi = height.size() - 1;
        int ans = INT_MIN;
        int area = 0;

        //Simulate
        while(lo < hi){
        	int x = min(height[lo] , height[hi]);
        	area = x*(hi-lo);
        	ans = max(ans, area);
        	if(height[lo] < height[hi]){
        		lo++;
        	}else{
        		hi--;
        	}
        }
        return ans;
    }
};

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	//Read the input
	int n;
	cin >> n;
	vector<int> height;
	for(int i=0;i<n;i++){
		int no;
		cin >> no;
		height.push_back(no);
	}
	Solution s;
	cout << s.maxArea(height) << endl;
}