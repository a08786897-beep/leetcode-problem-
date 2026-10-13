class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        
        sort(squares.begin(), squares.end());
        
        long long ans = 0;
        int ngc = n / 2;
        
        for (int i = 0; i < ngc; ++i) {
            ans -= squares[i];
        }
        for (int i = ngc; i < n; ++i) {
            ans += squares[i];
        }
        
        return ans;
    }
};