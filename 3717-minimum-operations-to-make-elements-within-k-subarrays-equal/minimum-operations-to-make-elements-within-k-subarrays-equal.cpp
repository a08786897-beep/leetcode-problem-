class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Coordinate-compressed Fenwick trees for counts and sums.
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        struct Fenwick {
            vector<long long> bit;
            Fenwick(int n) : bit(n + 1, 0) {}

            void add(int i, long long delta) {
                for (; i < (int)bit.size(); i += i & -i)
                    bit[i] += delta;
            }

            long long sum(int i) const {
                long long result = 0;
                for (; i > 0; i -= i & -i)
                    result += bit[i];
                return result;
            }
        };

        Fenwick counts(vals.size()), sums(vals.size());
        long long windowSum = 0;

        auto addValue = [&](int value, int delta) {
            int i = lower_bound(vals.begin(), vals.end(), value) - vals.begin() + 1;
            counts.add(i, delta);
            sums.add(i, 1LL * value * delta);
            windowSum += 1LL * value * delta;
        };

        auto windowCost = [&]() -> long long {
            // Find the lower median (rank (x + 1) / 2).
            int rank = (x + 1) / 2;
            int lo = 1, hi = (int)vals.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (counts.sum(mid) >= rank) hi = mid;
                else lo = mid + 1;
            }

            long long median = vals[lo - 1];
            long long leftCount = counts.sum(lo);
            long long leftSum = sums.sum(lo);
            long long rightCount = x - leftCount;
            long long rightSum = windowSum - leftSum;

            return median * leftCount - leftSum
                 + rightSum - median * rightCount;
        };

        // cost[i] is the minimum cost to make nums[i..i+x-1] equal.
        int m = n - x + 1;
        vector<long long> cost(m);

        for (int i = 0; i < x; ++i) addValue(nums[i], 1);
        cost[0] = windowCost();

        for (int start = 1; start < m; ++start) {
            addValue(nums[start - 1], -1);
            addValue(nums[start + x - 1], 1);
            cost[start] = windowCost();
        }

        // dp[j][t]: minimum cost using the first j elements to choose t
        // non-overlapping windows.
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int j = 0; j <= n; ++j) dp[j][0] = 0;

        for (int j = 1; j <= n; ++j) {
            for (int t = 1; t <= k; ++t) {
                dp[j][t] = dp[j - 1][t];  // Skip nums[j - 1].

                if (j >= x && dp[j - x][t - 1] != INF) {
                    int start = j - x;
                    dp[j][t] = min(dp[j][t],
                                   dp[j - x][t - 1] + cost[start]);
                }
            }
        }

        return dp[n][k];
    }
};