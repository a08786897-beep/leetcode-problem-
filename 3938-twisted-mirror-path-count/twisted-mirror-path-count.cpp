class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // dp[c] stores ways arriving at column c with two states:
        // state 0: coming from above (moving down)
        // state 1: coming from left (moving right)
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        
        // Base initialization for the start
        dp[1] = {1, 1};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    // Mirror cell: directions swap/reflect
                    dp[c + 1] = {dp[c + 1][1], dp[c][0]};
                } else {
                    // Empty cell: can come from either direction
                    long long val = (dp[c + 1][1] + dp[c][0]) % MOD;
                    dp[c + 1] = {val, val};
                }
            }
        }

        return dp[n][0];
    }
};