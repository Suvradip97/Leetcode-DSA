


/*

1346. Check If N and Its Double Exist
LeetCode Easy

*/




class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(mp[2 * arr[i]] || ((arr[i] % 2 == 0) && (mp[arr[i] / 2])))
                return true;
            else
                mp[arr[i]]++;
        }
        return false;
    }
};