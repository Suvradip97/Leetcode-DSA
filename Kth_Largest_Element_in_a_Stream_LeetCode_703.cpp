 

/*

703. Kth Largest Element in a Stream
LeetCode Easy

*/





class KthLargest {
public:
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for (auto a : nums) {
            if (pq.size() < k) {
                pq.push(a);
            } else {
                int num = pq.top();
                pq.pop();
                int mn = max(num, a);
                pq.push(mn);
            }
        }
    }

    int add(int val) {
        if (pq.size() < x) {
            pq.push(val);
        } else {
            int num = pq.top();
            pq.pop();
            int mn = max(num, val);
            pq.push(mn);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */