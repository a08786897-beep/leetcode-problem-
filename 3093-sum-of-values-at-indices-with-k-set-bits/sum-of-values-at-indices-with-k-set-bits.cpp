class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(n, 0);

        for (int i = 1; i < n; i++) {
            bits[i] = bits[i / 2] + (i % 2);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (bits[i] == k) {
                sum += nums[i];
            }
        }

        return sum;
    }
};