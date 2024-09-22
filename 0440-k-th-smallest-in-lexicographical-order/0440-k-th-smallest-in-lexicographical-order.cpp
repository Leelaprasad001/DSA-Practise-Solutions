class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur{1};
        --k;
        while (k) {
            long steps = count(cur, n);
            if (steps <= k) cur++, k -= steps;
            else cur *= 10, --k;
        }
        return cur;
    }
    long count(long p, long n) {
        long steps{0};
        for (long f = p, l = p; f <= n; f *= 10, l = l * 10 + 9)
            steps += min(n + 1, l + 1) - f;
        return steps;
    }
};