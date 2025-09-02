#include<bits/stdc++.h>
using namespace std;


// 347. Top K Frequent Elements
// LeetCode Medium


class Solution {
public:

    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        //Store element-frequency pair in the map
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        //Store the element-frequency pair in the vector using custom sort function
        vector<pair<int, int>> temp(mpp.begin(), mpp.end());
        sort(temp.begin(), temp.end(), compare);
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};