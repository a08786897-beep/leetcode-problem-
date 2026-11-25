class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
    const ll BASE = 100007;

    vector<ll> power;

    bool check(int len, const vector<int>& nums) {
        int n = nums.size();
        if (len <= 0 || len > n) return false;

        unordered_map<ll, int> mp;
        mp.reserve(n - len + 1);

        ll hash = 0;
        for (int i = 0; i < len; i++) {
            ll val = ((ll)nums[i] % MOD + MOD) % MOD;
            hash = (hash * BASE + val) % MOD;
        }
        mp[hash]++;

        ll highestpower = power[len - 1];

        for (int i = len; i < n; i++) {
            ll out_val = ((ll)nums[i - len] % MOD + MOD) % MOD;
            ll in_val = ((ll)nums[i] % MOD + MOD) % MOD;

            ll remove_term = (out_val * highestpower) % MOD;
            hash = (hash - remove_term + MOD) % MOD;
            hash = (hash * BASE + in_val) % MOD;

            mp[hash]++;
        }

        for (const auto& p : mp) {
            if (p.second == 1) {
                return true;
            }
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        power.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        int left = 1, right = n;
        int ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};