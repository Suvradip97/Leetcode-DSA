


/* 1482. Minimum Number of Days to Make m Bouquets

LeetCode Medium

Binary Search on Answer


*/



class Solution {
public:
    bool check(int day, vector<int>& bloomDay, int m, int k) {
        int b = 0;
        int cnt = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                b += cnt / k;
                cnt = 0;
            }
        }
        b += cnt/k;
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(n < (long long)m * k){
            return -1;
        }
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, bloomDay, m, k)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};