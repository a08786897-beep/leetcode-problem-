class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0) return -1;

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];   // FIX

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int score = prefix[i] - suffix[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};