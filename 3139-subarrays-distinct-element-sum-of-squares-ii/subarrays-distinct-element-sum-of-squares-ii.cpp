class Solution {
    static const int MOD = 1e9 + 7;
    int n;
    vector<long long> sumSq, sumV, lazy;

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;
        int mid = (l + r) / 2;
        long long val = lazy[node];

        lazy[2 * node] = (lazy[2 * node] + val) % MOD;
        sumSq[2 * node] = (sumSq[2 * node] + 2 * val * sumV[2 * node] + val * val * (mid - l + 1)) % MOD;
        sumV[2 * node] = (sumV[2 * node] + val * (mid - l + 1)) % MOD;

        lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;
        sumSq[2 * node + 1] = (sumSq[2 * node + 1] + 2 * val * sumV[2 * node + 1] + val * val * (r - mid)) % MOD;
        sumV[2 * node + 1] = (sumV[2 * node + 1] + val * (r - mid)) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            sumSq[node] = (sumSq[node] + 2 * val * sumV[node] + val * val * (r - l + 1)) % MOD;
            sumV[node] = (sumV[node] + val * (r - l + 1)) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumV[node] = (sumV[2 * node] + sumV[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sumSq.assign(4 * n, 0);
        sumV.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100005, -1);
        long long totalSum = 0;
        long long currentAns = 0;

        for (int r = 0; r < n; ++r) {
            int prev = last[nums[r]];
            last[nums[r]] = r;
            
            update(1, 0, n - 1, prev + 1, r, 1);
            currentAns = (currentAns + sumSq[1]) % MOD;
        }

        return currentAns;
    }
};