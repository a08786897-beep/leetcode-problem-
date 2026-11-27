class Solution {
public:
    static constexpr int MAX_N = 1000;
    static constexpr int MAX_B = 1500;
    int memo[MAX_N + 1][MAX_B + 5];

    int solve(int n, int budget, int minprice, vector<vector<int>>& items, vector<int>& copies) {
        if (n == 0) {
            return (minprice > 0 && minprice != INT_MAX) ? (budget / minprice) : 0;
        }
        if (n <= MAX_N && budget <= MAX_B && memo[n][budget] != -1) {
            return memo[n][budget];
        }

        int take = 0;
        int price = items[n - 1][1];

        if (price <= budget) {
            take = 1 + copies[n - 1] + solve(n - 1, budget - price, minprice, items, copies);
        }
        int skip = solve(n - 1, budget, minprice, items, copies);

        int ans = max(take, skip);
        if (n <= MAX_N && budget <= MAX_B) {
            memo[n][budget] = ans;
        }
        return ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        if (n == 0 || budget < 0) {
            return 0;
        }

        vector<int> copies(n, 0);
        int minprice = INT_MAX;

        for (int i = 0; i < n; i++) {
            minprice = min(minprice, items[i][1]);
            if (items[i][0] == 0) {
                continue;
            }
            int copy = 0;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0) {
                    copy++;
                }
            }
            copies[i] = copy;
        }

        memset(memo, -1, sizeof(memo));
        return solve(n, budget, minprice, items, copies);
        
    }
};