/*

3405. Count the Number of Arrays with K Matching Adjacent Elements

You are given three integers n, m, k. A good array arr of size n is defined as follows:

Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, m = 2, k = 1

Output: 4

Explanation:

There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
Hence, the answer is 4.
Example 2:

Input: n = 4, m = 2, k = 2

Output: 6

Explanation:

The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
Hence, the answer is 6.
Example 3:

Input: n = 5, m = 2, k = 0

Output: 2

Explanation:

The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
 

Constraints:

1 <= n <= 105
1 <= m <= 105
0 <= k <= n - 1

Solution 

Approach: Combinatorial Mathematics
Intuition
The problem requires us to construct an array of length n, where each number is in the range [1,m], and exactly k pairs of adjacent elements are the same. We need to find how many such arrays can be constructed.

In an array of length n, there are n−1 pairs of adjacent elements. Among these, k pairs must consist of equal adjacent elements, and the remaining n−1−k pairs must consist of different adjacent elements. We can treat these n−1−k differing adjacent positions as partitions, which divide the array into n−k contiguous segments, where each segment contains identical values.

We can first choose the positions to insert these partitions and then assign values to each segment. Let's calculate the total number of such combinations step-by-step:

Among the n−1 positions between array elements, we choose n−1−k to place the partitions. This can be done in ( 
k
n−1
​
 ) ways (since ( 
n−1−k
n−1
​
 )=( 
k
n−1
​
 )).
The first segment can take any of the m values, since there are no restrictions on it.
Every subsequent segment (there are n−k−1 such segments) must differ from the previous segment's value. So, each of them has m−1 possible choices, giving a total of (m−1) 
n−k−1
  options.
By the multiplication principle, the total number of valid arrays is:

m×( 
k
n−1
​
 )×(m−1) 
n−k−1
 

To compute this efficiently, we use:

the factorial-based formula for combinations: ( 
b
a
​
 )= 
b!(a−b)!
a!
​
 ,
modular inverses for division under a modulus,
and binary exponentiation for powers.

*/




const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};